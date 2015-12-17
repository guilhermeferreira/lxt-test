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
#include "missing_letters.h"

#include <cstring>

#include <algorithm>
#include <string>


namespace luxoft {

/**
 * The basic idea of this function is to treat both the sentence and the
 * alphabet as Sets. The set difference between the alphabet and the sentence
 * gives us the elements (letters) that are missing in the sentence.
 */
std::string getMissingLetters(const std::string &sentence)
{
	// Sorted set, without duplicate letters and with all lower case letters
	static const std::string english_alphabet("abcdefghijklmnopqrstuvwxyz");

	// We might have at most english_alphabet's length of missing letters
	std::string missing_letters = english_alphabet;

	// Convert sentence to lower case
	std::string copySentence = sentence;
	std::transform(copySentence.begin(), copySentence.end(), copySentence.begin(), ::tolower);

	// Sort the sentence
	std::sort(copySentence.begin(), copySentence.end());

	// The missing letters are those that are present in english_alphabet,
	// but not in sentence
	std::string::iterator it = set_difference(
			english_alphabet.begin(), english_alphabet.end(),
			copySentence.begin(), copySentence.end(),
			missing_letters.begin());

	missing_letters.resize(it - missing_letters.begin());

	// Convert sentence to upper case
	std::transform(missing_letters.begin(), missing_letters.end(), missing_letters.begin(), ::toupper);

	return missing_letters;
}

}
