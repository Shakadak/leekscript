#include "Test.hpp"

void Test::test_numbers() {

	header("Numbers");

	// basic numbers
	code("0").equals("0");
	code("-1").equals("-1");
	code("-(-1)").equals("1");
	code("π").equals("3.141592653589793116");

	// basic operations
	code("0 + 5").equals("5");
	code("5 + 5").equals("10");
	code("10 - 3").equals("7");
	code("-2 + 3").equals("1");
	code("5 * 5").equals("25");
	code("15 / 3").equals("5");
	code("15 / 2").equals("7.5");
	code("12 ** 2").equals("144");
	code("2 ** 5").equals("32");
	code("2 < 5").equals("true");
	code("12 < 5").equals("false");
	code("5 == 12").equals("false");
	code("12 == 12").equals("true");
	code("0.2 + 0.1").almost(0.3);
	code("|-12|").equals("12");
	code("-12 * 2").equals("-24");
	code("(-12) * 2").equals("-24");
	code("-12 ** 2").equals("-144");
	code("-12 ** 2").equals("-144");
	code("(-12) ** 2").equals("144");
	code("-12 + 2").equals("-10");
	code("let a = [2, 'a'] [-a[0], +a[0], ~a[0]] == [-2, 2, ~2]").equals("true");

	// Hexadecimal representation
	code("0x0").equals("0");
	code("0x00000000").equals("0");
	code("0x1").equals("1");
	code("0x00000001").equals("1");
	code("0xf").equals("15");
	code("0x0000000f").equals("15");
	code("-0xf").equals("-15");
	code("0xff").equals("255");
	code("0x10").equals("16");
	code("-0xffff").equals("-65535");
	code("0xffffffff").equals("4294967295");

	// null must not be considered as 0
	code("null + 5").equals("null");
	code("null * 5").equals("null");

	// with variables
	code("let a = 2 a++").equals("2");
	code("let a = 2; ++a").equals("3");
	code("let a = 2 a--").equals("2");
	code("let a = 2; --a").equals("1");
	code("let a = 2 a += 5").equals("7");
	code("let a = 2 a -= 5").equals("-3");
	code("let a = 2 a *= 5").equals("10");
	code("let a = 100 a /= 5").equals("20");
	code("let a = 56 a %= 17").equals("5");
	code("let a = 15 a **= 2").equals("225");
	code("let a = 1.5 a * 0.5").equals("0.75");

	// multiple operations
	code("(33 - 2) / 2").equals("15.5");
	code("12 < (45 / 4)").equals("false");
	code("12 == (24 / 2)").equals("true");
	code("2.5 + 4.7").almost(7.2);
	code("2.5 × 4.7").equals("11.75");
	code("5 * 2 + 3 * 4").equals("22");

	// binary
	code("0 & 0").equals("0");
	code("1 & 0").equals("0");
	code("1 & 1").equals("1");
	code("5 & 12").equals("4");
	code("87619 & 18431").equals("17987");
	code("let a = 87619 a &= 18431").equals("17987");
	code("let a = 87619 a &= 18431 a").equals("17987");
	code("0 | 0").equals("0");
	code("1 | 0").equals("1");
	code("1 | 1").equals("1");
	code("5 | 12").equals("13");
	code("87619 | 18431").equals("88063");
	code("let a = 87619 a |= 18431").equals("88063");
	code("let a = 87619 a |= 18431 a").equals("88063");
	code("0 ^ 0").equals("0");
	code("1 ^ 0").equals("1");
	code("1 ^ 1").equals("0");
	code("5 ^ 12").equals("9");
	code("87619 ^ 18431").equals("70076");
	code("let a = 87619 a ^= 18431").equals("70076");
	code("let a = 87619 a ^= 18431 a").equals("70076");
	code("0 << 0").equals("0");
	code("1 << 0").equals("1");
	code("123456 << 0").equals("123456");
	code("0 << 1").equals("0");
	code("0 << 12").equals("0");
	code("1 << 8").equals("256");
	code("123 << 12").equals("503808");
	code("let a = 123 a <<= 11").equals("251904");
	code("let a = 123 a <<= 13 a").equals("1007616");
	code("0 >> 0").equals("0");
	code("1 >> 0").equals("1");
	code("123456 >> 0").equals("123456");
	code("0 >> 1").equals("0");
	code("0 >> 12").equals("0");
	code("155 >> 3").equals("19");
	code("-155 >> 3").equals("-20");
	code("12345 >> 8").equals("48");
	code("123123123 >> 5").equals("3847597");
	code("let a = 123123123 a >>= 6").equals("1923798");
	code("let a = 123123123 a >>= 7 a").equals("961899");
	code("155 >>> 3").equals("19");
	code("-155 >>> 3").equals("536870892");
	code("let a = -155 a >>>= 4").equals("268435446");
	code("let a = -155 a >>>= 5 a").equals("134217723");

	// string conversions
	code("65.char()").equals("'A'");
	code("Number.char(65)").equals("'A'");
	code("126.char()").equals("'~'");
	code("Number.char(128040)").equals("'🐨'");

	// large numbers
	// code("12344532132423").equals("12344532132423");

	/*
	 * Number standard library
	 */
	header("Number standard library");
	code("Number").equals("<class Number>");
	code("Number()").equals("0");
	code("new Number").equals("0");
	code("new Number()").equals("0");
	code("new Number(12)").equals("12");

	// constants
	code("Number.pi").equals("3.141592653589793116");
	code("2 × Number.pi").equals("6.283185307179586232");
	code("Number.e").equals("2.718281828459045091");
	code("Number.phi").equals("1.618033988749894903");
	code("Number.epsilon").equals("0.000000000000000222");

//	code("Number.abs").equals("<function>");
	code("Number.abs(-12)").equals("12");
	code("Number.floor(5.9)").equals("5");
	code("var a = 5 Number.floor(a)").equals("5");
	code("var a = 5.4 Number.floor(a)").equals("5");
	code("Number.round(5.7)").equals("6");
	code("Number.round(5.4)").equals("5");
	code("Number.ceil(5.1)").equals("6");
	code("Number.max(5, 12)").equals("12");

	code("Number.cos(0)").equals("1");
	code("Number.cos(π)").equals("-1");
	code("Number.cos(π / 2)").almost(0.0);

	code("Number.sin(0)").equals("0");
	code("Number.sin(π)").almost(0.0);
	code("Number.sin(π / 2)").equals("1");
	code("Number.sin(- π / 2)").equals("-1");

	code("Number.isInteger(12)").equals("true");
	code("Number.isInteger(0)").equals("true");
	code("Number.isInteger(-5)").equals("true");
	code("Number.isInteger(12.9)").equals("false");
	code("Number.isInteger(-5.2)").equals("false");
	code("Number.isInteger(π)").equals("false");

	// Object-like calls
	code("(-12).abs()").equals("12");
	code("π.cos()").equals("-1");
	code("(π / 2).sin()").equals("1");
	code("12.sqrt()").equals("3.464101615137754386");
	code("12.8.floor()").equals("12");
	code("-12.8.floor()").equals("-12");
	code("(-12.8).floor()").equals("-13");
	code("12.2.ceil()").equals("13");
	code("12.8.round()").equals("13");
	code("-12.8.round()").equals("-13");
	code("2.pow(10)").equals("1024");
	code("0.isInteger()").equals("true");
	code("56.7.isInteger()").equals("false");
	code("(-56.7).isInteger()").equals("false");
	code("3.max(5)").equals("5");
	code("5.max(3)").equals("5");

	// Combinated
	code("3.max(5).min(2)").equals("2");
	code("3.max(5).max(10).max(12)").equals("12");
	code("10.max(5).max(8.7).max(-3.91)").equals("10");
	code("10.sqrt().cos()").equals("-0.99978607287932586");
}
