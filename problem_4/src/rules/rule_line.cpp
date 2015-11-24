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

#include "assignment_statement.h"
#include "command_statement.h"
#include "syntactic_error_exception.h"


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

RuleLine::RuleLine(int lineNumber)
: statement_(NULL), lineNumber_(lineNumber)
{
}

//-----------------------------------------------------------------------------

RuleLine::~RuleLine()
{
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

	string consumableLine = line;

	// Place a symbol at the end so the algorithm can find the last token.
	// This has the same purpose as the ';' at the end of C++ statements
	const string tokenDelimiters = " ";
	consumableLine.push_back(tokenDelimiters[0]);

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

	const string firstToken = tokens_[0]->getValue();
	size_t firstTokenPrefixEndPos = firstToken.find_first_of("_");
	if (firstTokenPrefixEndPos == string::npos) {
		firstTokenPrefixEndPos = firstToken.length();
	}

	const string firstTokenPrefix = firstToken.substr(0, firstTokenPrefixEndPos);
	if (firstTokenPrefix == "call") {
		statement_ = new AssignmentStatement;
		statement_->parse(tokens_, objectTable);
	} else if (firstTokenPrefix == "print") {
		statement_ = new CommandStatement;
		statement_->parse(tokens_, objectTable);
	} else {
		throw SyntacticErrorException(lineNumber_);
	}


}

//-----------------------------------------------------------------------------

void RuleLine::execute()
{
	assert(!tokens_.empty());
	assert(statement_ != NULL);

	statement_->execute();
}


} // namespace luxoft
