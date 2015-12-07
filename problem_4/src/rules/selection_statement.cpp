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
#include "selection_statement.h"

#include <cassert>
#include <limits>

#include "statement_factory.h"
#include "syntactic_error_exception.h"
#include "semantic_error_exception.h"


namespace luxoft {

using namespace std;
using namespace std::tr1;

//-----------------------------------------------------------------------------
// SelectionStatement class
//-----------------------------------------------------------------------------

const string SelectionStatement::SELECTION_KEYWORD = "if";
const string SelectionStatement::SELECTION_BEGIN_OPERATOR = "then";
const string SelectionStatement::SELECTION_END_OPERATOR = "end";

//-----------------------------------------------------------------------------

SelectionStatement::SelectionStatement(const int lineNumber)
: Statement(lineNumber),
  conditionExpression_(),
  ifStatement_()
{
}

//-----------------------------------------------------------------------------

SelectionStatement::~SelectionStatement()
{
}

//-----------------------------------------------------------------------------

void SelectionStatement::parse(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(conditionExpression_ == NULL);
	assert(ifStatement_ == NULL);

	// Parse the production rule:
	//   <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	//                            

	// Consume leftmost token, the keyword "if"
	parseSelectionKeyword(tokens);

	// The <condition_expression> will consume all tokens that are part
	// of the condition (until the "]" operator), leaving the token
	// list with "then" token and those tokens that make up a <statement>
	parseConditionExpression(tokens, objectTable);

	// Consume the keyword "then"
	parseSelectionBeginOperator(tokens);

	// Consume the rightmost token, the "end" keyword, before the statement!!!
	// Then the <statement> will not try to compute the "end" keyword!!!
	parseSelectionEndOperator(tokens);

	// Consume the "if" <statement> non-terminal from the production
	//   <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	parseStatement(tokens, objectTable);
}

//-----------------------------------------------------------------------------

void SelectionStatement::evaluate()
{
	assert(conditionExpression_ != NULL);
	assert(ifStatement_ != NULL);

	if ((conditionExpression_->evaluate() - 0) >= numeric_limits<float>::epsilon()) {
		ifStatement_->evaluate();
	}
}

//-----------------------------------------------------------------------------

void SelectionStatement::parseSelectionKeyword(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string selectionKeyword = tokens[0]->getValue();
	if (selectionKeyword != SELECTION_KEYWORD) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(selectionKeyword == SELECTION_KEYWORD);

	// Remove the keyword from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void SelectionStatement::parseConditionExpression(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());
	assert(conditionExpression_ == NULL);

	conditionExpression_.reset(new ConditionExpression(lineNumber_));
	assert(conditionExpression_ != NULL);
	conditionExpression_->parse(tokens, objectTable);
}

//-----------------------------------------------------------------------------

void SelectionStatement::parseSelectionBeginOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string selectionBeginKeyword = tokens[0]->getValue();
	if (selectionBeginKeyword != SELECTION_BEGIN_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(selectionBeginKeyword == SELECTION_BEGIN_OPERATOR);

	// Remove the keyword from the list of tokens
	tokens.erase(tokens.begin());
}

//-----------------------------------------------------------------------------

void SelectionStatement::parseSelectionEndOperator(
	vector< shared_ptr<Token> > &tokens)
{
	assert(!tokens.empty());

	string selectionEndKeyword = tokens[tokens.size() - 1]->getValue();
	if (selectionEndKeyword != SELECTION_END_OPERATOR) {
		throw SyntacticErrorException(lineNumber_);
	}
	assert(selectionEndKeyword == SELECTION_END_OPERATOR);

	// Remove the keyword from the list of tokens
	tokens.erase(tokens.end() - 1, tokens.end());
}

//-----------------------------------------------------------------------------

void SelectionStatement::parseStatement(
	vector< shared_ptr<Token> > &tokens,
	ObjectTable &objectTable)
{
	assert(!tokens.empty());

	const string statementKeyword = StatementFactory::getStatementKeyword(tokens);
	ifStatement_ = StatementFactory::createStatement(statementKeyword, lineNumber_);
	if (ifStatement_ == NULL) {
		// TODO What about create an InvalidStatement object that throws errors
		//      when parsed or evaluated?
		throw SyntacticErrorException(lineNumber_);
	}
	assert(ifStatement_ != NULL);
	ifStatement_->parse(tokens, objectTable);
}


} // namespace luxoft
