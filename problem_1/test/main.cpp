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
#include "rotation.h"

#include <cstdlib>

#include <iostream>
#include <cpptest.h>

using namespace std;

class RotationTest: public Test::Suite
{
public:
	RotationTest();

private:
	void isRotation_true_Test();
	void isRotation_false_Test();

};

//-----------------------------------------------------------------------------

RotationTest::RotationTest()
{
	TEST_ADD(RotationTest::isRotation_true_Test);
	TEST_ADD(RotationTest::isRotation_false_Test);
}

//-----------------------------------------------------------------------------

void RotationTest::isRotation_true_Test()
{
	TEST_ASSERT(luxoft::isRotation("helloworld", "elloworldh"));
	TEST_ASSERT(luxoft::isRotation("helloworld", "lloworldhe"));
	TEST_ASSERT(luxoft::isRotation("helloworld", "loworldhel"));
	TEST_ASSERT(luxoft::isRotation("helloworld", "oworldhell"));
	TEST_ASSERT(luxoft::isRotation("helloworld", "worldhello"));
}

//-----------------------------------------------------------------------------

void RotationTest::isRotation_false_Test()
{
	TEST_ASSERT(!luxoft::isRotation("helloworld", "alloworldh"));
	TEST_ASSERT(!luxoft::isRotation("helloworld", "llowurldhe"));
	TEST_ASSERT(!luxoft::isRotation("helloworld", "loworfdhel"));
	TEST_ASSERT(!luxoft::isRotation("helloworld", "owcrldhell"));
	TEST_ASSERT(!luxoft::isRotation("helloworld", "worldhillo"));
	TEST_ASSERT(!luxoft::isRotation("hello", "helol"));
}

//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	cout << "Problem #1 Test" << endl;

	Test::TextOutput output(Test::TextOutput::Verbose);

	RotationTest test;
	test.run(output, false);

	return EXIT_SUCCESS;
}
