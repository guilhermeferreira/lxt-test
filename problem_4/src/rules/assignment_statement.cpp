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
#include "assignment_statement.h"

#include <cassert>

#include "syntactic_error_exception.h"
#include "semantic_error_exception.h"

namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// AssignmentStatement class
//-----------------------------------------------------------------------------

const string AssignmentStatement::ASSIGNMENT_OPERATOR = "=";

//-----------------------------------------------------------------------------

AssignmentStatement::AssignmentStatement(const int lineNumber)
: Statement(lineNumber),
  lvalueObject_(NULL),
  rvalueExpression_(NULL)
{
}

//-----------------------------------------------------------------------------

AssignmentStatement::~AssignmentStatement()
{
	// WARNING: Don't destroy the "lvalueObject_" pointer, because this
	//          class has not not instantiated it!

	if (rvalueExpression_ != NULL) {
		delete rvalueExpression_;
		rvalueExpression_ = NULL;
	}
}

//-----------------------------------------------------------------------------

void AssignmentStatement::parse(
	vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(lvalueObject_ == NULL);
	assert(rvalueExpression_ == NULL);

	// Parse the production rule:
	//     <assignment_statement> ::= <readwrite_object> "=" <arithmetic_expression>

	// Consume left hand side token, that is the variable (object) name
	parseObject(tokens, objectTable);

	// Consume the assignment operator
	parseAssignmentOperator(tokens);

	// Expression can consume only the right hand side tokens
	parseExpression(tokens, objectTable);
}

//-----------------------------------------------------------------------------

void AssignmentStatement::evaluate()
{
	assert(lvalueObject_ != NULL);
	assert(rvalueExpression_ != NULL);

	// Because <readonly_object> can't be lvalues!
	// We ensure that only <readwrite_object> are evaluated!
	if (lvalueObject_->isRulesReadOnly()) {
		throw SemanticErrorException(lineNumber_);
	}

	lvalueObject_->setValue(rvalueExpression_->evaluate());
}

//-----------------------------------------------------------------------------

void AssignmentStatement::parseObject(
	vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(lvalueObject_ == NULL);

	string objectName = tokens[0]->getValue();
	lvalueObject_ = objectTable.getFloatingObject(objectName);
	if (lvalueObject_ == NULL) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(lvalueObject_ != NULL);

	// Remove the operand from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void AssignmentStatement::parseAssignmentOperator(vector<Token*> &tokens)
{
	assert(!tokens.empty());

	string operatorSymbol = tokens[0]->getValue();
	if (operatorSymbol != ASSIGNMENT_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(operatorSymbol == ASSIGNMENT_OPERATOR);

	// Remove the operator from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void AssignmentStatement::parseExpression(
	vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(rvalueExpression_ == NULL);

	rvalueExpression_ = new ArithmeticExpression(lineNumber_);
	assert(rvalueExpression_ != NULL);
	rvalueExpression_->parse(tokens, objectTable);
}


} // namespace luxoft
