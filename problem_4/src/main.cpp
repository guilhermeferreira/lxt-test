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
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <vector>

#include "rules.h"

using namespace std;
using namespace luxoft;

//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	cout << "Problem #4" << endl;

	string rulesFile;
	vector<string> callFiles;

	// ./program_4 rules.c3l input1.call input2.call ... inputn.call
	if (argc >= 3) {
		rulesFile = argv[1]; // i.e. rules.c3l

		for (int callFileIdx = 2; callFileIdx < argc; ++callFileIdx) {
			callFiles.push_back(argv[callFileIdx]); // i.e. inputx.call
		}

		Rules rules;
		rules.tokenize(rulesFile);
		rules.parse();

		for (vector<string>::iterator it = callFiles.begin(); it != callFiles.end(); ++it) {
			rules.execute(*it);
		}

	} else {
		cerr << "Usage: " << argv[0]
		     << " <rules-file> <call-file-1> [<call-file-2> ... <call-file-n>]"
		     << endl;
	}

	return EXIT_SUCCESS;
}
