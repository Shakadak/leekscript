#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <string>
#include "../src/leekscript.h"
#include "../src/vm/VM.hpp"
#include "../src/compiler/semantic/SemanticError.hpp"
#include "../src/compiler/lexical/LexicalError.hpp"

// TODO
/*
 code("2 + 2").equals("4")
 code("'hello'()").error(SemanticError::CANNOT_CALL_VALUE, "'hello'")
 code("'unterminated").error(LexicalError::UNTERMINATED_STRING)
 code("[1, 2, 3].size()").between(2, 5)
 file("test/code/strings.ls").almost(52, 2)
 code("1 + 1").operations(1)

 file("long_code.ls").timeout(500).equals(32312)

 code("while (true) {}").timeout(10).error(Timeout)
*/

/*
#define STR(...) #__VA_ARGS__
#define code(...) _code(STR(__VA_ARGS__))
#define equals(...) _equals(STR(__VA_ARGS__))
*/
#define code _code
#define equals _equals

class Test {
private:
	ls::VM vm;
	int total;
	int success_count;
	double exeTime;
	int obj_created;
	int obj_deleted;

public:

	class Input;

	Test();
	virtual ~Test();

	int all();
	void header(std::string);

	Input _code(const std::string& _code);
	Input file(const std::string& file_name);

	void test_general();
	void test_operations();
	void test_operators();
	void test_references();
	void test_system();
	void test_objects();
	void test_strings();
	void test_numbers();
	void test_booleans();
	void test_arrays();
	void test_map();
	void test_set();
	void test_functions();
	void test_loops();
	void test_classes();
	void test_files();

	class Input {
	private:
		Test* test;
		std::string _name;
		std::string _code;
	public:
		Input(Test* test, const std::string& name, const std::string& _code)
			: test(test), _name(name), _code(_code) {};
		void _equals(std::string&& expected);
		template <typename T>
		void almost(T expected, T delta = std::numeric_limits<T>::epsilon());
		template <typename T>
		void between(T a, T b);
		void semantic_error(ls::SemanticError::Type error, std::string param);
		void lexical_error(ls::LexicalError::Type error);
		void operations(int ops);
		Input& timeout(int ms);

		ls::VM::Result run();
		void pass(std::string expected);
		void fail(std::string expected, std::string actuel);
		std::string& name() { return _name; };
	};
};




#endif
