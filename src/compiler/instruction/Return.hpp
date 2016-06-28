#ifndef RETURN_HPP
#define RETURN_HPP

#include "../../compiler/instruction/Instruction.hpp"
#include "../../compiler/value/Expression.hpp"
#include "../../compiler/value/Function.hpp"

namespace ls {

class Return : public Instruction {
public:

	Value* expression;
	Function* function;
	bool in_function;

	Return();
	Return(Value*);
	virtual ~Return();

	virtual void print(std::ostream&) const override;

	virtual void analyse(SemanticAnalyser*, const Type& req_type) override;

	virtual jit_value_t compile_jit(Compiler&, jit_function_t&, Type) const override;
};

}

#endif