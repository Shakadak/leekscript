#include "../../compiler/value/ObjectAccess.hpp"

#include "../../compiler/semantic/SemanticAnalyser.hpp"
#include "../../vm/value/LSNull.hpp"
#include "../../vm/value/LSString.hpp"
#include "../../vm/value/LSFunction.hpp"
#include "../../vm/value/LSClass.hpp"
#include "../../vm/Program.hpp"

using namespace std;

namespace ls {

ObjectAccess::ObjectAccess() {
	object = nullptr;
	type = Type::POINTER;
	class_attr = false;
	attr_addr = nullptr;
}

ObjectAccess::~ObjectAccess() {
	delete object;
}

void ObjectAccess::print(ostream& os) const {
	object->print(os);
	os << "." << field;
}

void ObjectAccess::analyse(SemanticAnalyser* analyser, const Type) {

	object->analyse(analyser);

//	cout << "Analyse oa : " << field << " => ";
//	cout << object->type << endl;

	// Search direct attributes
	try {
		//type = object->attr_types.at(field);
		//cout << "Type of " << field << " : " << type << endl;
	} catch (exception&) {}

//	cout << type << endl;


	// Search class attributes
	string clazz = object->type.clazz;

	//cout << "Classe : " << clazz << endl;

	if (analyser->program->system_vars.find(clazz) != analyser->program->system_vars.end()) {

		LSClass* std_class = (LSClass*) analyser->program->system_vars[clazz];

		//cout << "Classe ! ";
		//std_class->print(cout);
		//cout << endl;

		try {
			type = std_class->fields[field];
			//cout << "Field " << field << " in class " << clazz << " found." << endl;
			//cout << "(type " << type << ")" << endl;
		} catch (exception& e) {

		}

		auto types = analyser->internal_vars[clazz]->attr_types;

//		cout << "search type of " << field << endl;

		if (types.find(field) != types.end()) {

//			cout << " oa " << field << endl;

			//type = types[field];
			//class_attr = true;

			// TODO : the attr must be a function here, not working with other types
			//attr_addr = ((LSFunction*) std_class->static_fields[field])->function;

			//attr_addr = std_class->getDefaultMethod(field)->function;
		}
	}

	//cout << "final : " << type << endl;
}

LSValue* object_access(LSValue* o, LSString* k) {
	return o->attr(k);
}

LSValue** object_access_l(LSValue* o, LSString* k) {
	return o->attrL(k);
}

jit_value_t ObjectAccess::compile_jit(Compiler& c, jit_function_t& F, Type) const {

	if (class_attr) {


		// TODO : only functions!
		return JIT_CREATE_CONST_POINTER(F, new LSFunction(attr_addr));

	} else {

		jit_value_t o = object->compile_jit(c, F, Type::POINTER);

		jit_type_t args_types[2] = {JIT_POINTER, JIT_POINTER};
		jit_type_t sig = jit_type_create_signature(jit_abi_cdecl, JIT_POINTER, args_types, 2, 0);

		jit_value_t k = JIT_CREATE_CONST_POINTER(F,  new LSString(field));
		jit_value_t args[] = {o, k};

		jit_value_t res = jit_insn_call_native(F, "access", (void*) object_access, sig, args, 2, JIT_CALL_NOTHROW);

		VM::delete_temporary(F, o);
		VM::delete_temporary(F, k);
		return res;
	}
}

jit_value_t ObjectAccess::compile_jit_l(Compiler& c, jit_function_t& F, Type) const {

	jit_value_t o = object->compile_jit(c, F, Type::POINTER);

	jit_type_t args_types[2] = {JIT_POINTER, JIT_POINTER};
	jit_type_t sig = jit_type_create_signature(jit_abi_cdecl, JIT_POINTER, args_types, 2, 0);

	jit_value_t k = JIT_CREATE_CONST_POINTER(F,  new LSString(field));
	jit_value_t args[] = {o, k};
	return jit_insn_call_native(F, "access_l", (void*) object_access_l, sig, args, 2, JIT_CALL_NOTHROW);
}

}