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

AssignmentStatement::AssignmentStatement(const int lineNumber)
: lvalueObject_(NULL),
  rvalueExpression_(NULL),
  lineNumber_(lineNumber)
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
	const vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(lvalueObject_ == NULL);
	assert(rvalueExpression_ == NULL);

	// Parse the production rule:
	//     <assignment_statement> ::= <readwrite_object> "=" <expression>

	// Consume left hand side token, that is the variable (object) name
	string objectName = tokens[0]->getValue();
	lvalueObject_ = objectTable.getObject(objectName);
	if (lvalueObject_ == NULL) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(lvalueObject_ != NULL);

	// Consume the assignment operator
	string operatorSymbol = tokens[1]->getValue();
	assert(operatorSymbol == "=");

	// Expression can consume only the right hand side tokens
	vector<Token*> remainingTokens(tokens.begin() + 2, tokens.end());
	rvalueExpression_ = new Expression(lineNumber_);
	assert(rvalueExpression_ != NULL);
	rvalueExpression_->parse(remainingTokens, objectTable);
}

//-----------------------------------------------------------------------------

void AssignmentStatement::evaluate()
{
	assert(lvalueObject_ != NULL);
	assert(rvalueExpression_ != NULL);

	lvalueObject_->setValue(rvalueExpression_->evaluate());
}


} // namespace luxoft
