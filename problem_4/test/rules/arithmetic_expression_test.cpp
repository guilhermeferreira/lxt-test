/**
 * Copyright(c) 2015 Guilherme M. Ferreira <guilherme.maciel.ferreira@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "arithmetic_expression_test.h"

#include <cmath>
#include <limits>

using namespace std;
using namespace luxoft;


//-----------------------------------------------------------------------------
// ArithmeticExpressionTest class
//-----------------------------------------------------------------------------

ArithmeticExpressionTest::ArithmeticExpressionTest()
{
	TEST_ADD(ArithmeticExpressionTest::parse_IntegerConstant_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_FloatConstant_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Object_Test);

	TEST_ADD(ArithmeticExpressionTest::parse_Addition_2_ConstantOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Addition_2_ObjectOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Addition_3_Operands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Addition_4_Operands_Test);

	TEST_ADD(ArithmeticExpressionTest::parse_Subtraction_2_ConstantOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Subtraction_2_ObjectOperands_Test);

	TEST_ADD(ArithmeticExpressionTest::parse_Multiplication_2_ConstantOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Multiplication_2_ObjectOperands_Test);

	TEST_ADD(ArithmeticExpressionTest::parse_Division_2_ConstantOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_Division_2_ObjectOperands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_3_Operands_Test);
	TEST_ADD(ArithmeticExpressionTest::parse_4_Operands_Test);
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_IntegerConstant_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("20", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 20.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_FloatConstant_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("20.5", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 20.5) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Object_Test()
{
	ObjectTable objTable;
	FloatingObject *obj = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj->setValue(30);

	std::vector<Token*> tokens;
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 30.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Addition_2_ConstantOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("50", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("10", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 60.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Addition_2_ObjectOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(50);
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	Token t2("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(10);
	Token t3(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 60.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Addition_3_Operands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("100", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("10", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	Token t4("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t4);

	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(1.5);
	Token t5(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t5);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 111.5) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Addition_4_Operands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(50);
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	Token t2("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("50", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	Token t4("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t4);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(2.5);
	Token t5(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t5);

	Token t6("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t6);

	Token t7("10", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t7);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);
	TEST_ASSERT(fabs(expression.evaluate() - 112.5) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Subtraction_2_ConstantOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("10", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("-", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("5", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 5.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Subtraction_2_ObjectOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(10);
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	Token t2("-", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(5);
	Token t3(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 5.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Multiplication_2_ConstantOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("*", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 4.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Multiplication_2_ObjectOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(2);
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	Token t2("*", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(2);
	Token t3(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 4.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Division_2_ConstantOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("50", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("/", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 25.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_Division_2_ObjectOperands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(50);
	Token t1(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t1);

	Token t2("/", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(2);
	Token t3(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t3);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 25.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_3_Operands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("50", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	Token t3("10", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t3);

	Token t4("-", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t4);

	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(20);
	Token t5(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t5);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	TEST_ASSERT(fabs(expression.evaluate() - 40.0) <= numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void ArithmeticExpressionTest::parse_4_Operands_Test()
{
	ObjectTable objTable;

	std::vector<Token*> tokens;
	Token t1("200", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t1);

	Token t2("/", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t2);

	FloatingObject *obj1 = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	obj1->setValue(50);
	Token t3(ObjectTable::CALL_TOTAL_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t3);

	Token t4("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t4);

	FloatingObject *obj2 = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	obj2->setValue(10);
	Token t5(ObjectTable::CALL_MINUTE_COST, TOKEN_TYPE_OBJECT);
	tokens.push_back(&t5);

	Token t6("*", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(&t6);

	Token t7("2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(&t7);

	ArithmeticExpression expression(1);
	expression.parse(tokens, objTable);

	// FIXME Due the lack of operator precedence in the grammar, non-
	// commutative operations (i.e. subtraction and division) are not
	// evaluated properly when expressions contain more than two operands

	TEST_ASSERT(fabs(expression.evaluate() - 20.0) <= numeric_limits<float>::epsilon());
}
