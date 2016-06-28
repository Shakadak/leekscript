#ifndef LSNULL
#define LSNULL

#include <iostream>
#include <string>
#include "../LSValue.hpp"
#include "../Type.hpp"

namespace ls {

class LSNull : public LSValue {
public:

	static LSValue* null_var;
	static LSClass* null_class;

	LSNull();
	LSNull(int refs);

	~LSNull() {}

	LSValue* clone() const override;

	bool isTrue() const override;

	LSValue* operator - () const override;
	LSValue* operator ! () const override;
	LSValue* operator ~ () const override;

	LSValue* operator ++ () override;
	LSValue* operator ++ (int) override;

	LSValue* operator -- () override;
	LSValue* operator -- (int) override;

	LSValue* operator + (const LSValue*) const override;
	LSValue* operator + (const LSNull*) const override;
	LSValue* operator + (const LSBoolean*) const override;
	LSValue* operator + (const LSNumber*) const override;
	LSValue* operator + (const LSString*) const override;
	LSValue* operator + (const LSArray<LSValue*>*) const override;
	LSValue* operator + (const LSArray<int>*) const override;
	LSValue* operator + (const LSObject*) const override;
	LSValue* operator + (const LSFunction*) const override;
	LSValue* operator + (const LSClass*) const override;

	LSValue* operator += (LSValue*) override;
	LSValue* operator += (const LSNull*) override;
	LSValue* operator += (const LSBoolean*) override;
	LSValue* operator += (const LSNumber*) override;
	LSValue* operator += (const LSString*) override;
	LSValue* operator += (const LSArray<LSValue*>*) override;
	LSValue* operator += (const LSObject*) override;
	LSValue* operator += (const LSFunction*) override;
	LSValue* operator += (const LSClass*) override;

	LSValue* operator - (const LSValue*) const override;
	LSValue* operator - (const LSNull*) const override;
	LSValue* operator - (const LSBoolean*) const override;
	LSValue* operator - (const LSNumber*) const override;
	LSValue* operator - (const LSString*) const override;
	LSValue* operator - (const LSArray<LSValue*>*) const override;
	LSValue* operator - (const LSObject*) const override;
	LSValue* operator - (const LSFunction*) const override;
	LSValue* operator - (const LSClass*) const override;

	LSValue* operator -= (LSValue*) override;
	LSValue* operator -= (const LSNull*) override;
	LSValue* operator -= (const LSBoolean*) override;
	LSValue* operator -= (const LSNumber*) override;
	LSValue* operator -= (const LSString*) override;
	LSValue* operator -= (const LSArray<LSValue*>*) override;
	LSValue* operator -= (const LSObject*) override;
	LSValue* operator -= (const LSFunction*) override;
	LSValue* operator -= (const LSClass*) override;

	LSValue* operator * (const LSValue*) const override;
	LSValue* operator * (const LSNull*) const override;
	LSValue* operator * (const LSBoolean*) const override;
	LSValue* operator * (const LSNumber*) const override;
	LSValue* operator * (const LSString*) const override;
	LSValue* operator * (const LSArray<LSValue*>*) const override;
	LSValue* operator * (const LSObject*) const override;
	LSValue* operator * (const LSFunction*) const override;
	LSValue* operator * (const LSClass*) const override;

	LSValue* operator *= (LSValue*) override;
	LSValue* operator *= (const LSNull*) override;
	LSValue* operator *= (const LSBoolean*) override;
	LSValue* operator *= (const LSNumber*) override;
	LSValue* operator *= (const LSString*) override;
	LSValue* operator *= (const LSArray<LSValue*>*) override;
	LSValue* operator *= (const LSObject*) override;
	LSValue* operator *= (const LSFunction*) override;
	LSValue* operator *= (const LSClass*) override;

	LSValue* operator / (const LSValue*) const override;
	LSValue* operator / (const LSNull*) const override;
	LSValue* operator / (const LSBoolean*) const override;
	LSValue* operator / (const LSNumber*) const override;
	LSValue* operator / (const LSString*) const override;
	LSValue* operator / (const LSArray<LSValue*>*) const override;
	LSValue* operator / (const LSObject*) const override;
	LSValue* operator / (const LSFunction*) const override;
	LSValue* operator / (const LSClass*) const override;

	LSValue* operator /= (LSValue*) override;
	LSValue* operator /= (const LSNull*) override;
	LSValue* operator /= (const LSBoolean*) override;
	LSValue* operator /= (const LSNumber*) override;
	LSValue* operator /= (const LSString*) override;
	LSValue* operator /= (const LSArray<LSValue*>*) override;
	LSValue* operator /= (const LSObject*) override;
	LSValue* operator /= (const LSFunction*) override;
	LSValue* operator /= (const LSClass*) override;

	LSValue* poww(const LSValue*) const override;
	LSValue* poww(const LSNull*) const override;
	LSValue* poww(const LSBoolean*) const override;
	LSValue* poww(const LSNumber*) const override;
	LSValue* poww(const LSString*) const override;
	LSValue* poww(const LSArray<LSValue*>*) const override;
	LSValue* poww(const LSObject*) const override;
	LSValue* poww(const LSFunction*) const override;
	LSValue* poww(const LSClass*) const override;

	LSValue* pow_eq(LSValue*) override;
	LSValue* pow_eq(const LSNull*) override;
	LSValue* pow_eq(const LSBoolean*) override;
	LSValue* pow_eq(const LSNumber*) override;
	LSValue* pow_eq(const LSString*) override;
	LSValue* pow_eq(const LSArray<LSValue*>*) override;
	LSValue* pow_eq(const LSObject*) override;
	LSValue* pow_eq(const LSFunction*) override;
	LSValue* pow_eq(const LSClass*) override;

	LSValue* operator % (const LSValue*) const override;
	LSValue* operator % (const LSNull*) const override;
	LSValue* operator % (const LSBoolean*) const override;
	LSValue* operator % (const LSNumber*) const override;
	LSValue* operator % (const LSString*) const override;
	LSValue* operator % (const LSArray<LSValue*>*) const override;
	LSValue* operator % (const LSObject*) const override;
	LSValue* operator % (const LSFunction*) const override;
	LSValue* operator % (const LSClass*) const override;

	LSValue* operator %= (LSValue*) override;
	LSValue* operator %= (const LSNull*) override;
	LSValue* operator %= (const LSBoolean*) override;
	LSValue* operator %= (const LSNumber*) override;
	LSValue* operator %= (const LSString*) override;
	LSValue* operator %= (const LSArray<LSValue*>*) override;
	LSValue* operator %= (const LSObject*) override;
	LSValue* operator %= (const LSFunction*) override;
	LSValue* operator %= (const LSClass*) override;

	bool operator == (const LSValue*) const override;
	bool operator == (const LSNull*) const override;
	bool operator == (const LSBoolean*) const override;
	bool operator == (const LSNumber*) const override;
	bool operator == (const LSString*) const override;
	bool operator == (const LSArray<LSValue*>*) const override;
	bool operator == (const LSFunction*) const override;
	bool operator == (const LSObject*) const override;
	bool operator == (const LSClass*) const override;

	bool operator < (const LSValue*) const override;
	bool operator < (const LSNull*) const override;
	bool operator < (const LSBoolean*) const override;
	bool operator < (const LSNumber*) const override;
	bool operator < (const LSString*) const override;
	bool operator < (const LSArray<LSValue*>*) const override;
	bool operator < (const LSFunction*) const override;
	bool operator < (const LSObject*) const override;
	bool operator < (const LSClass*) const override;

	bool operator > (const LSValue*) const override;
	bool operator > (const LSNull*) const override;
	bool operator > (const LSBoolean*) const override;
	bool operator > (const LSNumber*) const override;
	bool operator > (const LSString*) const override;
	bool operator > (const LSArray<LSValue*>*) const override;
	bool operator > (const LSFunction*) const override;
	bool operator > (const LSObject*) const override;
	bool operator > (const LSClass*) const override;

	bool operator <= (const LSValue*) const override;
	bool operator <= (const LSNull*) const override;
	bool operator <= (const LSBoolean*) const override;
	bool operator <= (const LSNumber*) const override;
	bool operator <= (const LSString*) const override;
	bool operator <= (const LSArray<LSValue*>*) const override;
	bool operator <= (const LSFunction*) const override;
	bool operator <= (const LSObject*) const override;
	bool operator <= (const LSClass*) const override;

	bool operator >= (const LSValue*) const override;
	bool operator >= (const LSNull*) const override;
	bool operator >= (const LSBoolean*) const override;
	bool operator >= (const LSNumber*) const override;
	bool operator >= (const LSString*) const override;
	bool operator >= (const LSArray<LSValue*>*) const override;
	bool operator >= (const LSFunction*) const override;
	bool operator >= (const LSObject*) const override;
	bool operator >= (const LSClass*) const override;

	bool in(const LSValue*) const override;

	LSValue* at (const LSValue* value) const override;
	LSValue** atL (const LSValue* value) override;

	LSValue* range(int start, int end) const override;
	LSValue* rangeL(int start, int end) override;

	LSValue* attr(const LSValue* key) const override;
	LSValue** attrL(const LSValue* key) override;

	LSValue* abso() const override;

	std::ostream& print(std::ostream& os) const override;
	std::string json() const override;

	LSValue* getClass() const override;

	int typeID() const override;

	virtual const BaseRawType* getRawType() const override;
};

}

#endif