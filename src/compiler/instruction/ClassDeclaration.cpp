#include "../../compiler/instruction/ClassDeclaration.hpp"

#include "../../vm/value/LSNull.hpp"
#include "../../vm/value/LSClass.hpp"

using namespace std;

namespace ls {

ClassDeclaration::ClassDeclaration() {
	can_return = false;
}

ClassDeclaration::~ClassDeclaration() {}

void ClassDeclaration::print(ostream& os, bool debug) const {
	os << "class " << name << " {" << endl;
	for (VariableDeclaration* vd : fields) {
		vd->print(os, debug);
		os << endl;
	}
	os << "}";
}

void ClassDeclaration::analyse(SemanticAnalyser* analyser, const Type&) {
	for (VariableDeclaration* vd : fields) {
		vd->analyse(analyser, Type::UNKNOWN);
	}
}

jit_value_t ClassDeclaration::compile(Compiler& c) const {
	return JIT_CREATE_CONST_POINTER(c.F, LSNull::null_var);
}

}
