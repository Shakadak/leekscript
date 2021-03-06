#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <vector>
#include "../instruction/Instruction.hpp"
#include "Value.hpp"

namespace ls {

class Block : public Value {
public:

	std::vector<Instruction*> instructions;

	Block();
	virtual ~Block();

	virtual void print(std::ostream&, int indent, bool debug) const override;
	virtual unsigned line() const override;

	virtual void analyse(SemanticAnalyser* analyser, const Type& req_type) override;

	jit_value_t compile(Compiler&) const;

};

}

#endif
