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
using namespace std::tr1;

//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

static const char TOKEN_DELIMITER_CHARACTERS[] = " ";
static const char TOKEN_ESCAPE_CHARACTERS[] = " \t";

//-----------------------------------------------------------------------------

RuleLine::RuleLine(const int lineNumber)
: statement_(),
  lineNumber_(lineNumber)
{
}

//-----------------------------------------------------------------------------

RuleLine::~RuleLine()
{
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
	consumableLine = addTrailingWhitespaces(consumableLine);

	size_t tokenEndPos = consumableLine.find_first_of(TOKEN_DELIMITER_CHARACTERS);
	while (tokenEndPos != string::npos) {
		const string &tokenValue = consumableLine.substr(0, tokenEndPos);
		TokenType tokenType = Token::discoverType(tokenValue);
		shared_ptr<Token> token(new Token(tokenValue, tokenType));

		tokens_.push_back(token);

		consumableLine.erase(0, tokenEndPos + 1);

		tokenEndPos = consumableLine.find_first_of(TOKEN_DELIMITER_CHARACTERS);
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
	vector< shared_ptr<Token> > consumableTokens(tokens_);
	statement_->parse(consumableTokens, objectTable);
	// Statements MUST consume all tokens, otherwise the rule is mal-formed
	// and should throw an exception
	assert(consumableTokens.empty());
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
	size_t nonWhitespacePos = line.find_first_not_of(TOKEN_ESCAPE_CHARACTERS);
	if (nonWhitespacePos != std::string::npos) {
		return line.substr(nonWhitespacePos);
	}

	return line;
}

//-----------------------------------------------------------------------------

string RuleLine::addTrailingWhitespaces(const string &line) const
{
	string terminatedLine = line;
	terminatedLine.push_back(TOKEN_DELIMITER_CHARACTERS[0]);

	return terminatedLine;
}

//-----------------------------------------------------------------------------


} // namespace luxoft
