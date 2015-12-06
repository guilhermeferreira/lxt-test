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
#include "arithmetic_expression.h"

#include <cassert>

#include <sstream>

#include "operation_table.h"
#include "syntactic_error_exception.h"


namespace luxoft {

using namespace std;
using namespace std::tr1;

//-----------------------------------------------------------------------------
// ArithmeticExpression class
//-----------------------------------------------------------------------------

ArithmeticExpression::ArithmeticExpression(const int lineNumber)
: Expression(lineNumber),
  operand_(),
  expression_(),
  operation_(),
  constant_(0)
{
}

//-----------------------------------------------------------------------------

ArithmeticExpression::~ArithmeticExpression()
{
}

//-----------------------------------------------------------------------------

void ArithmeticExpression::parse(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());

	// Consume the first two elements, <operand> and arithmetic operator:
	//
	//      <arithmetic_expression>::= <operand> "+" <arithmetic_expression>
	//                               | <operand> "-" <arithmetic_expression>
	//                               | <operand> "*" <arithmetic_expression>
	//                               | <operand> "/" <arithmetic_expression>
	//                               | <operand>
	//
	// The remaining <arithmetic_expression> is processed recursively (i.e. it's a context-
	// free grammar anyways)

	// Process expressions with a single operand, variable (object) or constant
	parseOperand(tokens, objectTable);

	// Process expressions that have operand, arithmetic operator and another
	// expression (e.g. <arithmetic_expression> ::= <object> "+" <arithmetic_expression>)
	if (tokens.size() > 1) {
		parseArithmeticOperator(tokens);

		parseExpression(tokens, objectTable);
	}
}

//-----------------------------------------------------------------------------

float ArithmeticExpression::evaluate() const
{
	// FIXME Due the lack of operator precedence in the grammar, non-
	//       commutative operations (i.e. subtraction and division) are not
	//       evaluated properly when expressions contain more than two operands

	// e.g. <arithmetic_expression> ::= <object> "+" <arithmetic_expression>
	if ((operand_ != NULL) && (operation_ != NULL) && (expression_ != NULL)) {
		assert(operation_ != NULL);

		return operation_->execute(operand_->getValue(), expression_->evaluate());

	}
	// e.g. <arithmetic_expression> ::= <constant> "+" <arithmetic_expression>
	else if ((operand_ == NULL) && (operation_ != NULL) && (expression_ != NULL)) {
		assert(operation_ != NULL);

		return operation_->execute(constant_, expression_->evaluate());

	}
	// i.e. <arithmetic_expression> ::= <object>
	else if ((operand_ != NULL) && (operation_ == NULL) && (expression_ == NULL)) {
		return operand_->getValue();

	}
	// i.e. <arithmetic_expression> ::= <constant>
	else { // ((operand_ == NULL) && (expression_ != NULL))
		return constant_;

	}
}

//-----------------------------------------------------------------------------

void ArithmeticExpression::parseOperand(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(operand_ == NULL);

	shared_ptr<Token> operandToken = tokens[0];
	switch (operandToken->getType()) {
		// The production rule is <arithmetic_expression> ::= <object>
		case TOKEN_TYPE_OBJECT: {
			const string &objectName = operandToken->getValue();
			operand_ = objectTable.getFloatingObject(objectName);
			if (operand_ == NULL) {
				throw SyntacticErrorException(lineNumber_);
			}
			break;
		}
		// The production rule is <arithmetic_expression> ::= <constant>
		case TOKEN_TYPE_NUMERIC_CONSTANT: {
			string numericValue = operandToken->getValue();
			istringstream stream(numericValue);
			stream >> constant_;
			break;
		}
		default:
			throw SyntacticErrorException(lineNumber_);
			break;
	}

	// Remove the operand token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ArithmeticExpression::parseArithmeticOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	shared_ptr<Token> operatorToken = tokens[0];
	switch (operatorToken->getType()) {
		case TOKEN_TYPE_ARITHMETIC_OPERATOR: {
			string operationSymbol = operatorToken->getValue();
			operation_ = OperationTable::getOperation(operationSymbol);
			assert(operation_ != NULL);
			break;
		}
		default:
			throw SyntacticErrorException(lineNumber_);
			break;
	}
	// Remove the operator token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ArithmeticExpression::parseExpression(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(expression_ == NULL); // Avoid dangling pointers (and memory leak)

	expression_.reset(new ArithmeticExpression(lineNumber_));
	assert(expression_ != NULL);
	expression_->parse(tokens, objectTable);
}

//-----------------------------------------------------------------------------


} // namespace luxoft
