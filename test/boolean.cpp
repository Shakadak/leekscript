#include "Test.hpp"

void Test::test_booleans() {

	header("Booléens");

	success("true", "true");
	success("false", "false");
	success("!true", "false");
	success("!false", "true");
	success("true and true", "true");
	success("true and false", "false");
	success("false and true", "false");
	success("false and false", "false");
	success("true or true", "true");
	success("true or false", "true");
	success("false or true", "true");
	success("false or false", "false");
	success("true xor true", "false");
	success("true xor false", "true");
	success("false xor true", "true");
	success("false xor false", "false");
	success("12 xor 5", "false");
	success("12 xor 0", "true");
	success("false xor 99", "true");
}
