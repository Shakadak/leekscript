#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Module.hpp"
#include "LSValue.hpp"
#include "value/LSClass.hpp"
#include "value/LSNumber.hpp"

using namespace std;

namespace ls {

Module::Module(std::string name) : name(name) {
	clazz = new LSClass(name, 1);
}

Module::~Module() {}

void Module::include(SemanticAnalyser* analyser, Program* program) {

	program->system_vars.insert({name, clazz});
	SemanticVar* var = analyser->add_var(new Token(name), Type::CLASS, nullptr);

	for (auto f : fields) {
		//var->attr_types.insert(pair<string, Type>(f.name, f.type));
		clazz->addField(f.name, f.type);
	}

	for (auto f : static_fields) {
		//var->attr_types.insert(pair<string, Type>(f.name, f.type));
		clazz->addStaticField(f.name, LSNumber::get(std::stoi(f.value)));
	}

	for (auto m : methods) {
		clazz->addMethod(m.name, m.impl);
	}

	for (auto m : static_methods) {
		var->attr_types.insert({m.name, m.impl[0].type});
		clazz->addStaticMethod(m.name, m.impl);
	}
}

void Module::field(std::string name, Type type) {
	fields.push_back(ModuleField(name, type));
}

void Module::static_field(std::string name, Type type, std::string value) {
	static_fields.push_back(ModuleStaticField(name, type, value));
}

void Module::method(std::string name, initializer_list<Method> impl) {
	methods.push_back(ModuleMethod(name, impl));
}

void Module::method(std::string name, Type obj_type, Type return_type, initializer_list<Type> args, void* addr) {
	methods.push_back(ModuleMethod(name, {{obj_type, return_type, args, addr}}));
}

void Module::static_method(string name, initializer_list<StaticMethod> impl) {
	static_methods.push_back(ModuleStaticMethod(name, impl));
}

void Module::static_method(string name, Type return_type, initializer_list<Type> args, void* addr) {
	static_methods.push_back(ModuleStaticMethod(name, {{return_type, args, addr}}));
}

void Module::generate_doc(std::ostream& os, std::string translation_file) {

	ifstream f;
	f.open(translation_file);
	stringstream j;
	j << f.rdbuf();
	std::string str = j.str();
	f.close();

	// Erase tabs
	str.erase(std::remove(str.begin(), str.end(), '	'), str.end());

	// Parse json
	char *endptr;
	JsonValue translation(JSON_NULL, nullptr);
	JsonAllocator allocator;
	jsonParse((char*) str.c_str(), &endptr, &translation, allocator);

	map<std::string, JsonValue> translation_map;
	if (translation.getTag() == JSON_OBJECT) {
		for (auto i : translation) {
			translation_map.insert({i->key, i->value});
		}
	}

	os << "\"" << name << "\":{";

	os << "\"attributes\":{";
	for (unsigned e = 0; e < static_fields.size(); ++e) {

		ModuleStaticField& a = static_fields[e];

		std::string desc = (translation_map.find(a.name) != translation_map.end()) ?
				translation_map[a.name].toNode()->value.toString() : "";

		if (e > 0) os << ",";
		os << "\"" << a.name << "\":{\"type\":";
		a.type.toJson(os);
		os << ",\"value\":\"" << a.value << "\"";
		os << ",\"desc\":\"" << desc << "\"";
		os << "}";
	}

	os << "},\"methods\":{";
	for (unsigned e = 0; e < methods.size(); ++e) {
		ModuleMethod& m = methods[e];

		if (e > 0) os << ",";
		os << "\"" << m.name << "\":{\"type\":";
		m.impl[0].type.toJson(os);

		if (translation_map.find(m.name) != translation_map.end()) {
			JsonNode* json = translation_map[m.name].toNode();
			std::string desc = json->value.toString();
			std::string return_desc = json->next->next->value.toString();

			os << ",\"desc\":\"" << desc << "\"";
			os << ",\"return\":\"" << return_desc << "\"";
		}
		os << "}";
	}

	os << "},\"static_methods\":{";
		for (unsigned e = 0; e < static_methods.size(); ++e) {
			ModuleStaticMethod& m = static_methods[e];

			if (e > 0) os << ",";
			os << "\"" << m.name << "\":{\"type\":";
			m.impl[0].type.toJson(os);

			if (translation_map.find(m.name) != translation_map.end()) {
				JsonNode* json = translation_map[m.name].toNode();
				std::string desc = json->value.toString();
				std::string return_desc = json->next->next->value.toString();

				os << ",\"desc\":\"" << desc << "\"";
				os << ",\"return\":\"" << return_desc << "\"";
			}
			os << "}";
		}
	os << "}}";
}

}