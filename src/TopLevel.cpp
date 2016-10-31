#include <unistd.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <string>
#include "../lib/utf8.h"
#include <gmp.h>
#include <gmpxx.h>

#include "leekscript.h"

#include "doc/Documentation.hpp"
#include "../benchmark/Benchmark.hpp"
#include "vm/LSValue.hpp"

using namespace std;

bool param_time = false;
bool param_verbose = false;
bool param_exec = false;
bool param_file = false;
bool param_json = false;

#if DEBUG > 1
namespace ls {
	std::map<LSValue*, LSValue*> objs;
}
#endif

void print_errors(ls::VM::Result& result) {

	#if DEBUG > 0
		cout << "main() " << result.program << endl;
	#endif

	for (const auto& e : result.syntaxical_errors) {
		std::cout << "Line " << e->token->line << ": " << e->message << std::endl;
	}
	for (const auto& e : result.semantical_errors) {
		std::cout << "line " << e.line << ": " << e.message() << std::endl;
	}
}

int main(int argc, char* argv[]) {

	srand(time(0));

	/** Generate the standard functions documentation */
	if (argc > 1 && string(argv[1]) == "-doc") {
		ls::Documentation().generate(cout);
		return 0;
	}

	/** Arguments */
	if (argc > 1 && argv[1][0] == '-') {
		string args(argv[1]);
		for (char c : args) {
			if (c == 't') param_time = true;
			else if (c == 'v') param_verbose = true;
			else if (c == 'e') param_exec = true;
			else if (c == 'f') param_file = true;
			else if (c == 'j') param_json = true;
		}
	}

	std::string code;
	ls::VM vm;

	if (param_file || param_json) {

		string file("");
		if (argc > 2) file = argv[2];
		if (argc == 2 && argv[1][0] != '-') file = argv[1];

		// Read file
		ifstream ifs(file.data());
		code = string((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
		ifs.close();

		// Execute
		if (param_file) {

			auto result = vm.execute(code, "{}");
			print_errors(result);

			cout << result.value << endl;
			cout << "(" << result.operations << " ops, "
				<< result.compilation_time_ms << "ms + "
				<< result.execution_time_ms << "ms)" << endl;

		} else if (param_json) {

			auto result = vm.execute(code, "{}");
			cout << "{\"success\":true,\"ops\":" << result.operations
				<< ",\"time\":" << result.execution_time
				<< ",\"ctx\":" << result.context
				<< ",\"res\":\"" << result.value << "\"}" << endl;
		}

	} else if (param_exec) {

		string code = argv[2];
		string ctx = argv[3];

		auto result = vm.execute(code, ctx);
		cout << "{\"success\":true,\"ops\":" << result.operations
			<< ",\"time\":" << result.execution_time
			<< ",\"ctx\":" << result.context << ",\"res\":\""
			<< result.value << "\"}" << endl;

	} else {

		cout << "~~~ LeekScript v1.0 ~~~" << endl;
		string ctx = "{}";

		while (!std::cin.eof()) {

			// Get a instruction
			cout << ">> ";
			std::getline(std::cin, code);

			// Execute
			auto result = vm.execute(code, ctx);
			print_errors(result);

			cout << result.value << endl;

			cout << "(" << result.operations << " ops, "
				<< result.compilation_time_ms << "ms + "
				<< result.execution_time_ms << "ms)" << endl;
			ctx = result.context;
		}
	}
	return 0;
}