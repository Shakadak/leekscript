#include "Block.hpp"

#include "../../vm/value/LSNull.hpp"
#include "../../vm/value/LSNumber.hpp"
#include "../instruction/Return.hpp"
#include "../../vm/VM.hpp"

using namespace std;

namespace ls {

Block::Block() {
	type = Type::UNKNOWN;
}

Block::~Block() {
	for (Instruction* instruction : instructions) {
		delete instruction;
	}
}

void Block::print(ostream& os) const {
	os << "Block {" << endl;
	for (Instruction* instruction : instructions) {
		instruction->print(os);
		os << endl;
	}
	os << "}";
}

void Block::can_return(Type type) {

}

void Block::analyse(SemanticAnalyser* analyser, const Type req_type) {

	analyser->enter_block();

	for (unsigned i = 0; i < instructions.size(); ++i) {
		instructions[i]->analyse(analyser, req_type);
		if (i == instructions.size() - 1) {
			type = instructions[i]->type;
		}
	}

	analyser->leave_block();
}

jit_value_t Block::compile_jit(Compiler& c, jit_function_t& F, Type type) const {

	c.enter_block();

	for (unsigned i = 0; i < instructions.size(); ++i) {

		if (i == instructions.size() - 1) {
			jit_value_t val = instructions[i]->compile_jit(c, F, type);
			c.leave_block();
			return val;
		} else {
			jit_value_t res = instructions[i]->compile_jit(c, F, type);
			if (type.nature == Nature::POINTER) {
				VM::delete_temporary(F, res);
			}
		}
	}
	c.leave_block();
	return JIT_CREATE_CONST_POINTER(F, LSNull::null_var);
}

}