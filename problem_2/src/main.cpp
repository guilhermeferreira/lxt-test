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

#include "missing_letters.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using luxoft::getMissingLetters;

int main(int argc, char *argv[])
{
	cout << "Problem #2" << endl;

	string sentence;

	// The user provided the strings in the command line
	if (argc >= 2) {
		sentence = argv[1];
	}
	// The user didn't provide the strings in the command line
	else {
		cout << "Enter sentence: ";
		cin >> sentence;
	}

	string missing_letters = getMissingLetters(sentence);

	cout << "There are " << missing_letters.size()
	     << " missing letters: " << missing_letters << endl;

	return EXIT_SUCCESS;
}
