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
#include "statement_factory.h"

#include <cassert>

#include "assignment_statement.h"
#include "command_statement.h"
#include "selection_statement.h"

namespace luxoft {

using namespace std;


//-----------------------------------------------------------------------------
// StatementFactory class
//-----------------------------------------------------------------------------

Statement *StatementFactory::createStatement(
	const string &keyword,
	const int lineNumber)
{
	Statement *statement = NULL;

	if (keyword == "call") {
		statement = new AssignmentStatement(lineNumber);
	} else if (keyword == "print") {
		statement = new CommandStatement(lineNumber);
	} else if (keyword == "if") {
		statement = new SelectionStatement(lineNumber);
	}
	/*
	// TODO What about create an invalid statement object that throws errors
	//      when parsed or evaluated?
	else {
		statement = new InvalidStatement(lineNumber);
	}
	*/

	return statement;
}

//-----------------------------------------------------------------------------

string StatementFactory::getStatementKeyword(
	const vector<Token*> &statementTokens)
{
	// According to C3L Grammar, all keywords are at the first position
	// in the line
	const string firstToken = statementTokens[0]->getValue();
	size_t firstTokenPrefixEndPos = firstToken.find_first_of("_");
	if (firstTokenPrefixEndPos == string::npos) {
		firstTokenPrefixEndPos = firstToken.length();
	}
	const string firstTokenPrefix = firstToken.substr(0, firstTokenPrefixEndPos);

	return firstTokenPrefix;
}

//-----------------------------------------------------------------------------


} // namespace luxoft
