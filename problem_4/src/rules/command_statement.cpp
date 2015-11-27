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
#include "command_statement.h"

#include <cassert>

#include <iostream>

#include "syntactic_error_exception.h"
#include "semantic_error_exception.h"

namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// CommandStatement class
//-----------------------------------------------------------------------------

const string CommandStatement::COMMAND_KEYWORD = "print";

//-----------------------------------------------------------------------------

CommandStatement::CommandStatement(const int lineNumber)
: Statement(lineNumber),
  floatingObject_(NULL),
  stringObject_(NULL)
{
}

//-----------------------------------------------------------------------------

CommandStatement::~CommandStatement()
{
	// FIXME Don't destroy the object_, because this class has not
	//       instantiated it. This a place where a std::shared_ptr or a
	//       boost::shared_ptr would save us from deleting the object_.
}

//-----------------------------------------------------------------------------

void CommandStatement::parse(
	vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert((floatingObject_ == NULL) && (stringObject_ == NULL));

	// Production rules:
	//
	//  <command_statement>    ::= <command> <arithmetic_expression>
	//  <command>              ::= "print"
	//  <arithmetic_expression>::= <operand>
	//  <operand>              ::= <readwrite_object>
	//                           | <readonly_object>
	//                           | <constant>
	parseCommandKeyword(tokens);

	parseExpression(tokens, objectTable);
}

//-----------------------------------------------------------------------------

void CommandStatement::evaluate()
{
	assert((floatingObject_ != NULL) || (stringObject_ != NULL));

	if (floatingObject_ != NULL) {
		assert(!floatingObject_->getName().empty());

		cout << floatingObject_->getName() << " = " << floatingObject_->getValue() << endl;
	}
	else if (stringObject_ != NULL) {
		assert(!stringObject_->getName().empty());

		cout << stringObject_->getName() << " = " << stringObject_->getValue() << endl;
	}
	else {
		throw SemanticErrorException(lineNumber_);
	}
}

//-----------------------------------------------------------------------------

void CommandStatement::parseCommandKeyword(vector<Token*> &tokens)
{
	assert(!tokens.empty());

	string commandKeyword = tokens[0]->getValue();
	if (commandKeyword != COMMAND_KEYWORD) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(commandKeyword == COMMAND_KEYWORD);

	// Remove the keyword from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void CommandStatement::parseExpression(
	vector<Token*> &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert((floatingObject_ == NULL) && (stringObject_ == NULL));

	// FIXME This rule is limited to one single operand, not a recursive
	//       expression:
	//             <arithmetic_expression> ::= <operand>
	//
	// FIXME  May we get a generic pointer to any Object specialization?
	//
	string objectName = tokens[0]->getValue();
	floatingObject_ = objectTable.getFloatingObject(objectName);
	if (floatingObject_ == NULL) {
		stringObject_ = objectTable.getStringObject(objectName);
		if (stringObject_ == NULL) {
			throw SyntacticErrorException(lineNumber_);
		}
	}
	assert((floatingObject_ != NULL) || (stringObject_ != NULL));

	// Remove the operand from the list of tokens
	tokens.erase(tokens.begin());
}


} // namespace luxoft
