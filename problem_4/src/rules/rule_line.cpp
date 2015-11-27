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
#include "rule_line.h"

#include <cassert>

#include "statement_factory.h"
#include "syntactic_error_exception.h"


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

RuleLine::RuleLine(const int lineNumber)
: statement_(NULL),
  lineNumber_(lineNumber)
{
}

//-----------------------------------------------------------------------------

RuleLine::~RuleLine()
{
	// This class creates the Tokens, so it must destroy them!
	assert(!tokens_.empty());

	// TODO This a place where a std::shared_ptr or a boost::shared_ptr would
	//      save us from deleting all pointers. Because the vector::~vector()
	//      destroys the elements (pointer), not the element it points to!
	for (vector<Token*>::iterator it = tokens_.begin(); it != tokens_.end(); ++it) {
		Token *token = *it;

		delete token;
	}

	if (statement_ != NULL) {
		delete statement_;
		statement_ = NULL;
	}
}

//-----------------------------------------------------------------------------

void RuleLine::tokenize(const string &line)
{
	assert(tokens_.empty());
	assert(statement_ == NULL);

	// Don't modify the original line, use a consumable copy instead
	string consumableLine = removeLeadingWhitespaces(line);

	// Place a symbol at the end so the algorithm can find the last token.
	// This has the same purpose as the ';' at the end of C++ statements
	const string tokenDelimiters = " ";
	consumableLine = addTrailingWhitespaces(line, tokenDelimiters);

	size_t tokenEndPos = consumableLine.find_first_of(tokenDelimiters);
	while (tokenEndPos != string::npos) {
		const string &tokenValue = consumableLine.substr(0, tokenEndPos);
		TokenType tokenType = Token::discoverType(tokenValue);
		Token *token = new Token(tokenValue, tokenType);

		tokens_.push_back(token);

		consumableLine.erase(0, tokenEndPos + 1);

		tokenEndPos = consumableLine.find_first_of(tokenDelimiters);
	}
}

//-----------------------------------------------------------------------------

void RuleLine::parse(ObjectTable &objectTable)
{
	assert(!tokens_.empty());
	assert(statement_ == NULL);

	const string keyword = StatementFactory::getStatementKeyword(tokens_);
	statement_ = StatementFactory::createStatement(keyword, lineNumber_);
	if (statement_ == NULL) {
		// TODO What about create an InvalidStatement object that throws errors
		//      when parsed or evaluated?
		throw SyntacticErrorException(lineNumber_);
	}

	assert(statement_ != NULL);
	statement_->parse(tokens_, objectTable);
}

//-----------------------------------------------------------------------------

void RuleLine::evaluate()
{
	assert(!tokens_.empty());
	assert(statement_ != NULL);

	statement_->evaluate();
}

//-----------------------------------------------------------------------------

string RuleLine::removeLeadingWhitespaces(const string &line) const
{
	size_t nonWhitespacePos = line.find_first_not_of(" \t");
	if (nonWhitespacePos != std::string::npos) {
		return line.substr(nonWhitespacePos);
	}

	return line;
}

//-----------------------------------------------------------------------------

string RuleLine::addTrailingWhitespaces(
	const string &line,
	const string &lineDelimiter) const
{
	string terminatedLine = line;
	terminatedLine.push_back(lineDelimiter[0]);

	return terminatedLine;
}

//-----------------------------------------------------------------------------


} // namespace luxoft
