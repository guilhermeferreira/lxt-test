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
#include "rules_file.h"

#include <cassert>

#include <fstream>
#include <iostream>
#include <string>

#include "rules.h"


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// RulesFile class
//-----------------------------------------------------------------------------

RulesFile::RulesFile(string rulesFileName)
: rulesFileName_(rulesFileName)
{
}

//-----------------------------------------------------------------------------

RulesFile::~RulesFile()
{
}

//-----------------------------------------------------------------------------

void RulesFile::tokenize() /* throws SyntacticErrorException */
{
	assert(!rulesFileName_.empty());

	ifstream rulesFile(rulesFileName_.c_str());
	if (!rulesFile) {
		cerr << "File '" << rulesFileName_ << "' not found" << endl;
	}

	if (!rulesFile.is_open()) {
		cerr << "File '" << rulesFileName_ << "' could not be open" << endl;
	}

	rules_.tokenize(rulesFile);

	rulesFile.close();
}

//-----------------------------------------------------------------------------

void RulesFile::parse()  /* throws SyntacticErrorException */
{
	assert(!rulesFileName_.empty());

	rules_.parse();
}

//-----------------------------------------------------------------------------

void RulesFile::execute() /* throws SemanticErrorException */
{
	assert(!rulesFileName_.empty());

	rules_.execute();
}

//-----------------------------------------------------------------------------

} // namespace luxoft
