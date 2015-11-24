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
#include "rules.h"

#include <cassert>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// Rules class
//-----------------------------------------------------------------------------

Rules::Rules()
{
}

//-----------------------------------------------------------------------------

Rules::~Rules()
{
	// TODO This a place where a std::shared_ptr or a boost::shared_ptr would
	//      save us from deleting all pointers. Because the vector::~vector()
	//      destroys the elements (pointer), not the element it points to!
	for (vector<RuleLine*>::iterator it = ruleLines_.begin(); it != ruleLines_.end(); ++it) {
		RuleLine *ruleLine = *it;

		delete ruleLine;
	}
}

//-----------------------------------------------------------------------------

void Rules::tokenize(std::istream &ruleStream) /* throws SyntacticErrorException */
{
	/*
	 1. Lexical analysis breaks the source code text into small pieces called tokens.
	    Each token is a single atomic unit of the language, for instance a keyword,
	    identifier or symbol name. The token syntax is typically a regular language,
	    so a finite state automaton constructed from a regular expression can be used
	    to recognize it. This phase is also called lexing or scanning, and the software
	    doing lexical analysis is called a lexical analyzer or scanner. This may not
	    be a separate step it can be combined with the parsing step in scannerless
	    parsing, in which case parsing is done at the character level, not the token level.
	 */

	string line;
	int lineNumber = 1;
	while (getline(ruleStream, line)) {
		// Discard comments and white space characters
		if (isValidLine(line)) {

			RuleLine *ruleLine = new RuleLine(lineNumber);
			ruleLine->tokenize(line);

			ruleLines_.push_back(ruleLine);

			++lineNumber;
		}
	}
}

//-----------------------------------------------------------------------------

void Rules::parse()  /* throws SyntacticErrorException */
{
	/*
	2. Syntax analysis involves parsing the token sequence to identify the syntactic
	   structure of the program. This phase typically builds a parse tree, which replaces
	   the linear sequence of tokens with a tree structure built according to the rules of
	   a formal grammar which define the language's syntax. The parse tree is often
	   analyzed, augmented, and transformed by later phases in the compiler.
	*/

	assert(!ruleLines_.empty());

	string line;
	for (vector<RuleLine*>::iterator it = ruleLines_.begin(); it != ruleLines_.end(); ++it) {
		RuleLine *ruleLine = *it;
		ruleLine->parse(objectTable_);
	}

}

//-----------------------------------------------------------------------------

void Rules::execute() /* throws SemanticErrorException */
{
	/*
	3. Semantic analysis is the phase in which the compiler adds semantic information
	   to the parse tree and builds the symbol table. This phase performs semantic checks
	   such as type checking (checking for type errors), or object binding (associating
	   variable and function references with their definitions), or definite assignment
	   (requiring all local variables to be initialized before use), rejecting incorrect
	   programs or issuing warnings. Semantic analysis usually requires a complete parse
	   tree, meaning that this phase logically follows the parsing phase, and logically
	   precedes the code generation phase, though it is often possible to fold multiple
	   phases into one pass over the code in a compiler implementation.
	 */

	assert(!ruleLines_.empty());

	string line;
	for (vector<RuleLine*>::iterator it = ruleLines_.begin(); it != ruleLines_.end(); ++it) {
		RuleLine *ruleLine = *it;
		ruleLine->execute();
	}

}

//-----------------------------------------------------------------------------

bool Rules::isValidLine(const string &line)
{
	bool isComment = (line[0] == '#');
	bool isBlankLine = (line.empty() || (line[0] == '\n'));

	return (!isComment && !isBlankLine);
}

//-----------------------------------------------------------------------------

} // namespace luxoft
