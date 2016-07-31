#ifndef LEXICAL_ERROR_HPP_
#define LEXICAL_ERROR_HPP_

#include <string>

class LexicalError {
public:

	enum Type {
		UNTERMINATED_STRING
	};

	Type type;
	unsigned int line;
	unsigned int character;

	LexicalError(Type type, int line, int character);
	virtual ~LexicalError();

	std::string message() const;
};

#endif