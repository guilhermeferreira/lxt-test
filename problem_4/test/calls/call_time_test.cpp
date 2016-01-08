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
#include "call_time_test.h"

#include <iostream>
#include <limits>

using namespace std;
using namespace luxoft;


//-----------------------------------------------------------------------------
// CallTimeTest class
//-----------------------------------------------------------------------------

CallTimeTest::CallTimeTest()
{
	TEST_ADD(CallTimeTest::minusOperator_Test);
	TEST_ADD(CallTimeTest::extractionOperator_Test);
	TEST_ADD(CallTimeTest::insertionOperator_Test);
}

//-----------------------------------------------------------------------------

void CallTimeTest::minusOperator_Test()
{
	CallTime ct1(12,  0,  0); // 12:00:00
	CallTime ct2(12, 20,  0); // 12:20:00

	TEST_ASSERT(((ct1 - ct2) - -20) < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct2 - ct1) - 20)  < numeric_limits<float>::epsilon());


	CallTime ct3(17,  5,  0); // 17:05:00
	CallTime ct4(18, 45,  0); // 18:45:00

	TEST_ASSERT(((ct3 - ct4) - -100)  < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct4 - ct3) - 100)  < numeric_limits<float>::epsilon());


	CallTime ct5( 7,  9, 30); // 07:09:30
	CallTime ct6(13,  9, 40); // 13:09:40

	TEST_ASSERT(((ct5 - ct6) - -360)  < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct6 - ct5) - 360)  < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void CallTimeTest::extractionOperator_Test()
{
	stringstream time1("12:00:00");
	CallTime ct1;
	time1 >> ct1;

	stringstream time2("12:20:00");
	CallTime ct2;
	time2 >> ct2;

	TEST_ASSERT(((ct1 - ct2) - -20)  < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct2 - ct1) - 20)  < numeric_limits<float>::epsilon());


	stringstream time3("17:05:00");
	CallTime ct3;
	time3 >> ct3;

	stringstream time4("18:45:00");
	CallTime ct4;
	time4 >> ct4;

	TEST_ASSERT(((ct3 - ct4) - -100)  < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct4 - ct3) - 100)  < numeric_limits<float>::epsilon());


	stringstream time5("07:09:30");
	CallTime ct5;
	time5 >> ct5;

	stringstream time6("13:09:40");
	CallTime ct6;
	time6 >> ct6;

	TEST_ASSERT(((ct5 - ct6) - -360)  < numeric_limits<float>::epsilon());
	TEST_ASSERT(((ct6 - ct5) - 360)  < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void CallTimeTest::insertionOperator_Test()
{
	stringstream time1;
	CallTime callTime1(12, 40, 20);
	time1 << callTime1;

	string stringTime1;
	time1 >> stringTime1;

	TEST_ASSERT(stringTime1 == "12:40:20");
}
