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
#include "condition_expression.h"

#include <cassert>

#include <string>
#include <sstream>
#include <vector>

#include "operation_table.h"
#include "syntactic_error_exception.h"


namespace luxoft {

using namespace std;
using namespace std::tr1;

//-----------------------------------------------------------------------------
// ConditionExpression class
//-----------------------------------------------------------------------------

static const char MEMBERSHIP_OPERATOR[] = "in";
static const char CONDITION_BEGIN_OPERATOR[] = "[";
static const char CONDITION_END_OPERATOR[] = "]";
static const char CONDITION_SEPARATOR_OPERATOR[] = " ";

//-----------------------------------------------------------------------------

ConditionExpression::ConditionExpression(const int lineNumber)
: Expression(lineNumber),
  stringOperand_()
{
}

//-----------------------------------------------------------------------------

ConditionExpression::~ConditionExpression()
{
}

//-----------------------------------------------------------------------------

void ConditionExpression::parse(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(stringOperand_ == NULL);
	assert(constantList_.empty());

	// The production rule is
	//    <condition_expression> ::= <operand> "in" "[" <constant_list> "]"

	// Process the single operand variable <operand>
	parseOperand(tokens, objectTable);

	// Process the operator "in"
	parseMembershipOperator(tokens);

	// Process the operator "["
	parseConditionBeginOperator(tokens);

	// Process the <constant_list>
	parseConstantList(tokens);

	// Process the operator "]"
	parseConditionEndOperator(tokens);
}

//-----------------------------------------------------------------------------

float ConditionExpression::evaluate() const
{
	assert(stringOperand_ != NULL);
	assert(!constantList_.empty());

	string item = stringOperand_->getValue();
	bool memberOf = (constantList_.find(item) != string::npos);

	return (memberOf ? 1 : 0);
}

//-----------------------------------------------------------------------------

void ConditionExpression::parseOperand(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(stringOperand_ == NULL);

	shared_ptr<Token> operandToken = tokens[0];
	if (operandToken->getType() == TOKEN_TYPE_OBJECT) {
		string objectName = operandToken->getValue();
		stringOperand_ = objectTable.getStringObject(objectName);
		if (stringOperand_ == NULL) {
			throw SyntacticErrorException(lineNumber_);
		}
	} else {
		throw SyntacticErrorException(lineNumber_);
	}

	// Remove the operand token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ConditionExpression::parseMembershipOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string membershipOperator = tokens[0]->getValue();
	if (membershipOperator != MEMBERSHIP_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(membershipOperator == MEMBERSHIP_OPERATOR);

	// Remove the operator token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ConditionExpression::parseConditionBeginOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string listBeginOperator = tokens[0]->getValue();
	if (listBeginOperator != CONDITION_BEGIN_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(listBeginOperator == CONDITION_BEGIN_OPERATOR);

	// Remove the operator token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ConditionExpression::parseConditionEndOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string listEndOperator = tokens[0]->getValue();
	if (listEndOperator != CONDITION_END_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(listEndOperator == CONDITION_END_OPERATOR);

	// Remove the operator token from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void ConditionExpression::parseConstantList(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());
	assert(constantList_.empty());

	while (tokens[0]->getValue() != CONDITION_END_OPERATOR) {
		string item = tokens[0]->getValue();
		constantList_.append(item);
		constantList_.append(CONDITION_SEPARATOR_OPERATOR);

		// Remove a constant token from the <constant_list> list of tokens
		tokens.erase(tokens.begin());
	}

	assert(!constantList_.empty());
}


} // namespace luxoft
