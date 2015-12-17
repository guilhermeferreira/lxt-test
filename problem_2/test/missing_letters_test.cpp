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
#include "missing_letters_test.h"

#include "missing_letters.h"


//-----------------------------------------------------------------------------
// MissingLettersTest class
//-----------------------------------------------------------------------------

MissingLettersTest::MissingLettersTest()
{
	TEST_ADD(MissingLettersTest::getMissingLetters_pangrams_Test);
	TEST_ADD(MissingLettersTest::getMissingLetters_not_pangrams_Test);
}

//-----------------------------------------------------------------------------

void MissingLettersTest::getMissingLetters_pangrams_Test()
{
	const std::string s1 = "A quick brown fox jumps over the lazy dog";
	const std::string m1 = luxoft::getMissingLetters(s1);
	TEST_ASSERT(m1.size() == 0);
	TEST_ASSERT(m1 == "");

	const std::string s2 = "Pack my box with five dozen liquor jugs.";
	const std::string m2 = luxoft::getMissingLetters(s2);
	TEST_ASSERT(m2.size() == 0);
	TEST_ASSERT(m2 == "");

	const std::string s3 = "Despite having an excellent breakfast, Jacques was amazingly slow.";
	const std::string m3 = luxoft::getMissingLetters(s3);
	TEST_ASSERT(m3.size() == 0);
	TEST_ASSERT(m3 == "");
}

//-----------------------------------------------------------------------------

void MissingLettersTest::getMissingLetters_not_pangrams_Test()
{
	std::string s1 = "This sentence contains A-Z but not the whole alphabet.";
	const std::string m1 = luxoft::getMissingLetters(s1);
	TEST_ASSERT(m1.size() == 11);
	TEST_ASSERT(m1 == "DFGJKMQRVXY");

	std::string s2 = "Guadalajara seems to be a very promising place to work.";
	const std::string m2 = luxoft::getMissingLetters(s2);
	TEST_ASSERT(m2.size() == 5);
	TEST_ASSERT(m2 == "FHQXZ");

	std::string s3 = "I can speak bit of german. Ich moechte ein Brezel bitte. Ich mag das";
	const std::string m3 = luxoft::getMissingLetters(s3);
	TEST_ASSERT(m3.size() == 7);
	TEST_ASSERT(m3 == "JQUVWXY");
}
