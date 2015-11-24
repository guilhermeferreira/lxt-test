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
#include "expression.h"

#include <cassert>

#include <sstream>

#include "operation_table.h"
#include "syntactic_error_exception.h"


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// Expression class
//-----------------------------------------------------------------------------

Expression::Expression()
: object_(NULL), expression_(NULL), operation_(NULL), constant_(0)
{
}

//-----------------------------------------------------------------------------

Expression::~Expression()
{
	if (expression_ != NULL) {
		delete expression_;
		expression_ = NULL;
	}
}

//-----------------------------------------------------------------------------

void Expression::parse(
	const vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());

	// This loop process only the first 1 or 2 elements:
	//
	//    <object>
	//    <object> "+"
	//    <object> "-"
	//    <object> "*"
	//    <object> "/"
	//    <constant>
	//
	// The remaining <expression> is processed recursively (i.e. it's a context-
	// free grammar anyways)


	// Process expressions with a single operand, variable (object) or constant
	Token *firstToken = tokens[0];
	switch (firstToken->getType()) {
		// The production rule is <expression> ::= <object>
		case TOKEN_TYPE_OBJECT: {
			string objectName = firstToken->getValue();
			object_ = objectTable.getObject(objectName);
			break;
		}
		// The production rule is <expression> ::= <constant>
		case TOKEN_TYPE_NUMERIC_CONSTANT: {
			string numericValue = firstToken->getValue();
			istringstream stream(numericValue);
			stream >> constant_;
			break;
		}
		default:
			throw SyntacticErrorException(0);
			break;
	}

	// Process expressions that have operand, arithmetic operator and another
	// expression (i.e. <expression> ::= <object> "+" <expression>)
	if (tokens.size() > 1) {
		Token *secondToken = tokens[1];
		switch (secondToken->getType()) {
			case TOKEN_TYPE_ARITHMETIC_OPERATOR: {
				string operationSymbol = secondToken->getValue();
				operation_ = OperationTable::getOperation(operationSymbol);
				break;
			}
			default:
				throw SyntacticErrorException(0);
				break;
		}

		vector<Token*> remainingTokens(tokens.begin() + 2, tokens.end());
		assert(expression_ == NULL); // Avoid dangling pointers (and memory leak)
		expression_ = new Expression;
		expression_->parse(remainingTokens, objectTable);
	}

}

//-----------------------------------------------------------------------------

float Expression::evaluate() const
{
	// i.e. <expression> ::= <object> "+" <expression>
	if ((object_ != NULL) && (operation_ != NULL) && (expression_ != NULL)) {
		assert(operation_ != NULL);

		return operation_->execute(object_->getValue(), expression_->evaluate());

	}
	// i.e. <expression> ::= <constant> "+" <expression>
	else if ((object_ == NULL) && (operation_ != NULL) && (expression_ != NULL)) {
		assert(operation_ != NULL);

		return operation_->execute(constant_, expression_->evaluate());

	}
	// i.e. <expression> ::= <object>
	else if ((object_ != NULL) && (operation_ == NULL) && (expression_ == NULL)) {
		return object_->getValue();

	}
	// i.e. <expression> ::= <constant>
	else { // ((object_ == NULL) && (expression_ != NULL))
		return constant_;

	}
}


} // namespace luxoft
