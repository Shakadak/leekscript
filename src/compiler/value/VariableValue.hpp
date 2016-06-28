#ifndef VARIABLEVALUE_HPP
#define VARIABLEVALUE_HPP

#include "../lexical/Ident.hpp"
#include "../value/LeftValue.hpp"
#include "../Compiler.hpp"

namespace ls {

class Value;
class SemanticVar;

class VariableValue : public LeftValue {
public:

	Token* name;
	SemanticVar* var;

	VariableValue(Token* name);
	virtual ~VariableValue();

	virtual void print(std::ostream&) const override;

	virtual void analyse(SemanticAnalyser*, const Type) override;
	void must_take(SemanticAnalyser* analyser, const Type& type);

	virtual jit_value_t compile_jit(Compiler&, jit_function_t&, Type) const override;
	virtual jit_value_t compile_jit_l(Compiler&, jit_function_t&, Type) const override;
};

}

#endif