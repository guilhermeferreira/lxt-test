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
#include "assignment_statement_test.h"

#include <cmath>
#include <limits>

using namespace std;
using namespace std::tr1;
using namespace luxoft;


//-----------------------------------------------------------------------------
// AssignmentStatementTest class
//-----------------------------------------------------------------------------

AssignmentStatementTest::AssignmentStatementTest()
{
	TEST_ADD(AssignmentStatementTest::constantAssignmentStatement_Test);
	TEST_ADD(AssignmentStatementTest::expressionAssignmentStatement_Test);
}

//-----------------------------------------------------------------------------

void AssignmentStatementTest::constantAssignmentStatement_Test()
{
	ObjectTable objTable;

	std::vector< shared_ptr<Token> > tokens;
	Token *t1 = new Token("call_total_cost", TOKEN_TYPE_OBJECT);
	tokens.push_back(shared_ptr<Token>(t1));
	Token *t2 = new Token("=", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(shared_ptr<Token>(t2));
	Token *t3 = new Token("14.2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(shared_ptr<Token>(t3));

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	AssignmentStatement assignment(1);
	assignment.parse(tokens, objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) > numeric_limits<float>::epsilon());
	assignment.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void AssignmentStatementTest::expressionAssignmentStatement_Test()
{
	ObjectTable objTable;

	std::vector< shared_ptr<Token> > tokens;
	Token *t1 = new Token("call_total_cost", TOKEN_TYPE_OBJECT);
	tokens.push_back(shared_ptr<Token>(t1));
	Token *t2 = new Token("=", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(shared_ptr<Token>(t2));
	Token *t3 = new Token("14.2", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(shared_ptr<Token>(t3));
	Token *t4 = new Token("+", TOKEN_TYPE_ARITHMETIC_OPERATOR);
	tokens.push_back(shared_ptr<Token>(t4));
	Token *t5 = new Token("5.8", TOKEN_TYPE_NUMERIC_CONSTANT);
	tokens.push_back(shared_ptr<Token>(t5));

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	AssignmentStatement assignment(1);
	assignment.parse(tokens, objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 20.0f) > numeric_limits<float>::epsilon());
	assignment.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 20.0f) < numeric_limits<float>::epsilon());
}
