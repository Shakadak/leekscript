#include "Test.hpp"

void Test::test_arrays() {

	header("Arrays");

	success("[]", "[]");
	success("[1]", "[1]");
	success("[1, 2, 3]", "[1, 2, 3]");
	success("[1.21, -5, 4.55, 12, -6.7]", "[1.21, -5, 4.55, 12, -6.7]");
	success("[true, false, true]", "[true, false, true]");
	success("[23, true, '', {}, 123]", "[23, true, '', {}, 123]");
	success("[1, 2, 3] + [4, 5, 6]", "[1, 2, 3, 4, 5, 6]");
	success("[] + 1", "[1]");
	success("[] + 1 + 2 + 3", "[1, 2, 3]");
	success("[1] + [2] + [3]", "[1, 2, 3]");
	success("[1, 2, 3][1]", "2");
	success("let a = [1, 2, 3] a[0]", "1");
	success("let a = [1, 2, 3] a[0] = 5 a[0]", "5");
	success("let a = [1, 2, 3] a[0] += 5 a[0]", "6");
	success("let v = 12 let a = [v, 2, 3] a[0] += 5 a[0]", "17");
	success("let a = [23, 23, true, '', [], 123] |a|", "6");
	success("let a = [1, 2, 3]; ~a", "[3, 2, 1]");
	success("let a = [1, 2, 3] a[1] = 12 a", "[1, 12, 3]");
	success("[1.2, 321.42, 23.15]", "[1.2, 321.42, 23.15]");
	success("[1, 2, 3, 4, 5][1:3]", "[2, 3, 4]");
	success("2 in [1, 2, 3]", "true");
	success("4 in [1, 2, 3]", "false");
	success("'yo' in ['ya', 'yu', 'yo']", "true");
	success("let a = 2 if (a in [1, 2, 3]) { 'ok' } else { 'no' }", "'ok'");

	/*
	 * Array operations
	 */
	header("Array operations");
	success("[1, 2, 3, 4, 5] ~~ x -> x ^ 2", "[1, 4, 9, 16, 25]");
	success("[1, 2, 3, 4, 5] ~~ (x -> x ^ 2)", "[1, 4, 9, 16, 25]");
	success("['yo', 'toto', 'salut'] ~~ x -> x + ' !'", "['yo !', 'toto !', 'salut !']");
	success("[1, 2, 3] ~~ x -> [x]", "[[1], [2], [3]]");
	success("[1, 2, 3] ~~ x -> 'yo'", "['yo', 'yo', 'yo']");
	success("let f = x -> x * 10 [1, 2, 3] ~~ f", "[10, 20, 30]");
//	success("[1.2, 321.42, 23.15] ~~ x -> x * 1.7", "[2.04, 546.414, 39.355]");


	/*
	 * Intervals
	 */
	header("Intervals");
	success("[1..10]", "[1..10]");
	success("145 in [1..1000]", "true");
	success("1 in [1..1000]", "true");
	success("1000 in [1..1000]", "true");
	success("0 in [1..1000]", "false");
	success("1001 in [1..1000]", "false");
	/*
	success("[1..1000][500]", "501");
	success("[1000..2000][12]", "1012");
	*/

	/*
	 * Array standard library
	 */
	header("Array standard library");
	success("Array", "<class Array>");
	success("Array()", "[]");
	success("new Array", "[]");
	success("new Array()", "[]");

	success("Array.size([1, 'yo', true])", "3");
	success("Array.size([6, 4, 3, 2, -11])", "5");
	success("[1, 'yo', true].size()", "3");
	success("[1, -2, 3, -12, -6].size()", "5");

	success("Array.average([1, 2, 3, 4, 5, 6])", "3.5");
	success("Array.average([])", "0");
	success("[1, 2, 3, 4, 5, 6].average()", "3.5");
	success("[].average()", "0");
	success("['salut', true, []].average()", "0");
	success("[10, -5.7, 30.89, 66].average()", "25.2975");

	success("Array.sum([10, -5, 30, 66])", "101");
	success("[10, -5, 30, 66].sum()", "101");
	success("Array.sum(['ab', 'cd', 'ef'])", "'abcdef'");
	success("['ab', 'cd', 'ef'].sum()", "'abcdef'");
	success("['abc', true, 12, [1, 2]].sum()", "'abctrue12<array>'");
	success("[10, -5.7, 30.89, 66].sum()", "101.19");

	success("Array.map([1, 2, 3], x -> x ^ 2)", "[1, 4, 9]");
	success("[3, 4, 5].map(x -> x ^ 2)", "[9, 16, 25]");
	success("[321, 213, 121].map(x -> x ^ 2).size()", "3");

	success("Array.map2([1, 'yo ', []], [12, 55, 9], (x, y -> x + y))", "[13, 'yo 55', [9]]");

	success("Array.filter([1, 2, 3, 10, true, 'yo'], x -> x > 2)", "[3, 10, 'yo']");
	success("[3, 4, 5].filter(x -> x > 6)", "[]");

	success("Array.contains([1, 2, 3, 10, 1], 1)", "true");
	success("[3, 4, 5].contains(6)", "false");

	success("Array.isEmpty([])", "true");
	success("[3, 4, 5].isEmpty()", "false");
	//success("let a = 0 Array.iter([1,2,3], x -> a += x) a", "6");
	//success("let a = 2 [1,2,3].iter(x -> a *= x) a", "12");

	success("Array.partition([1, 2, 3, 4, 5], (x -> x < 3))", "[[1, 2], [3, 4, 5]]");
	success("Array.partition([1, 2, 3, 10, true, 'yo'], x -> x > 2)", "[[3, 10, 'yo'], [1, 2, true]]");
	success("[1, 2, 3, 4, 5].partition(x -> x > 3)", "[[4, 5], [1, 2, 3]]");
	success("[1, 2, 3, 4, 5].partition(x -> x == 3)", "[[3], [1, 2, 4, 5]]");
	success("[1, 2, 3, 4, 5, 6].filter(x -> x > 2).partition(x -> x > 4)", "[[5, 6], [3, 4]]");
	// success("[1, 2, 3, 4, 5].partition(x -> 'yolo')", "**error**");

	success("Array.first([1, 2, 3, 10, true, 'yo', null])", "1");
	success("['yo', 3, 4, 5].first()", "'yo'");
	success("Array.last([1, 2, 3, 10, true, 'yo', null])", "null");
	// success("['yo', 3, 4, 5].last()", "5");

	// TODO : the return type of first() must be the element type of the array if it's homogeneous
//	success("[[321, 21], [23, 212], [654, 9876]].first().last()", "21");

	success("Array.foldLeft([1, 2, 3, 10, true, 'yo', null], (x, y -> x + y), 'concat:')", "'concat:12310trueyonull'");
	success("Array.foldRight([1, 2, 3, 10, true, 'yo', null], (x, y -> x + y), 'concat:')", "16");

//	success("Array.shuffle([1, 2, 3, 10, true, 'yo', null])", "test shuffle ?");

	success("Array.reverse([1, 2, 3, 10, true, 'yo', null])", "[null, 'yo', true, 10, 3, 2, 1]");
	success("[null].reverse()", "[null]");
	success("[].reverse()", "[]");
	success("[1, 2, 3].reverse()", "[3, 2, 1]");
	success("Array.search([1, 2, 3, 10, true, 'yo', null], 10, 0)", "3");

	success("Array.search([1, 2, 3, 4, 5], 5, 0)", "4");
	success("Array.search([1, 2, 3, 10, true, 'yo', null], 3, 3)", "-1");
	success("[1, 2, 3, 10, true, 'yo', null].search('yo', 0)", "5");
	success("Array.search([1, 2, 3, 10, true, 'yo', null], false, 0)", "-1");
	success("[null].search(null, 0)", "0");

	success("Array.subArray([1, 2, 3, 10, true, 'yo', null], 3, 5)", "[10, true, 'yo']");
	success("Array.subArray([1, 2, 3, 10, true, 'yo', null], 3, 1)", "[]");
	success("Array.subArray([1, 2, 3, 10, true, 'yo', null], 0, 100)", "[1, 2, 3, 10, true, 'yo', null]");
	success("Array.subArray([1, 2, 3, 10, true, 'yo', null], 1, 1)", "[2]");

	success("[].pop()", "null");
	success("Array.pop(['1', '2'])", "'2'");
	success("['1', '2'].pop()", "'2'");
	success("let a = ['1', '2', '3'] a.pop() a", "['1', '2']");

	success("let a = [1, 2, 3] Array.push(a, 4)", "[1, 2, 3, 4]");
	success("[].push([])", "[[]]");
	success("[0].pushAll([1, 2, 3])", "[0, 1, 2, 3]");
	success("let a = [1, 2] a.push(3) a", "[1, 2, 3]");
//	success("let a = [1, 2] a.push(3.5) a", "[1, 2, 3.5]");
	success("let a = [1.5, -2.9] a.push(3.5) a", "[1.5, -2.9, 3.5]");

	success("Array.concat([], [true, 'yo'])", "[true, 'yo']");

	success("[].join('a')", "''");
	success("['salut', 'ça', 'va'].join(' ')", "'salut ça va'");
	success("[1, null, 'va'].join(' ')", "'1 null va'");

	success("let a = [1, 2, 3] a.clear() a", "[]");
	success("let a = [1, 2, 3] Array.clear(a)", "[]");

	success("let a = [1, 2, 3] a.fill(12, 4) a", "[12, 12, 12, 12]");
	success("let a = [] Array.fill(a, 'test', 2)", "['test', 'test']");

	success("let a = [1, 2, 3] Array.insert(a, 12, 1)", "[1, 12, 2, 3]");
	success("let a = [1, 2, 3] Array.insert(a, 12, 6)", "[1, 2, 3, 0, 0, 0, 12]");

	success("let a = [1, 2, 3] Array.remove(a, 1)", "2");
	success("let a = [1, 2, 3] Array.remove(a, 1) a", "[1, 3]");
//	success("let a = [1, 2, 3] Array.remove(a, 1) a", "[0: 1, 2: 3]");
	success("let a = [1, 2, 3] Array.remove(a, 1)", "2");

//	success("let a = [] Array.removeKey(a, 'key')", "null");
//	success("let a = [1, 2, 3] a.insert('test', 'key') a.removeKey('key')", "'test'");
//	success("let a = [1, 2, 3] a.insert('test', 'key') a.removeKey('key') a", "[0: 1, 1: 2, 2: 3]");

	success("let a = [1, 2, 3] a.removeElement(1) a", "[2, 3]");
	success("let a = [1, 2, 3] a.removeElement('key') a", "[1, 2, 3]");

	/*
	success("3 ~ x -> x ^ x", "27");
	success("[1, 2, 3] ~ x -> x + 4", "[1, 2, 3, 4]");
	success("[1, 2, 3] ~~ print", "[null, null, null]");
	success("[1, 2, 3] ~~ x -> [x, x]", "[[1, 1], [2, 2], [3, 3]]");
	success("let s = 0 let a = [1, 2, 3, 4] let f = x -> s += x a ~~ f s", "10");
	success("let s = 0 [1, 2, 3, 4, 5].each(x -> s += x)", "15");
	success("[1, 2, 3, 4, 5].fold_left(+,0)", "15");
	//success("let f = x -> x + 10 let g = x -> x ^ 2 [1, 2, 3] ~~ f ~~ g", "[121, 144, 169]");
	//success("[1, 2, 3] ~~ (x -> x * 5) ~~ (x -> x - 1)", "[4, 9, 14]");
	*/

	/*
	[1, 2, 3] ~~= (x -> x * 5 + 2)
	[1, 2, 3] ~+= 1   =>   [2, 3, 4]
	[1, 2, 3] ~*= 5
	[1, 2, 3] ~= (x -> x * 5)
	*/

	// let a = [for let i = 0; i < 100; i++ do i end]
	// a[10:*]
	// a[] = 12 (a += 12)
}