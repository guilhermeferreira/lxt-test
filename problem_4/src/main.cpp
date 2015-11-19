/**
 * Copyright (c) 2015 Guilherme M. Ferreira <guilherme.maciel.ferreira at gmail dot com>
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

#include "rules.h"

using namespace std;

//-----------------------------------------------------------------------------

//
// General: code for simplified billing of a mobile network operator.
//
int main(int argc, char *argv[])
{
	cout << "Problem #4" << endl;

	string callStartDate;
	string callEndDate;
	string phoneDestination;
	string phoneSource;

	// input: call start date and time
	//        call end date and time
	//        number called
	//        subscriber account information
	if (argc >= 3) {
		callStartDate = argv[1];
		callEndDate = argv[2];
		phoneDestination = argv[3];
		phoneSource = argv[4];
	}

	// objective: calculate call cost

	// rules:
	// - "connection-fee" is added to any call cost;
	// - "minute-fee" is charged at the beginning of each minute, so if call
	//    duration is 1:03, two minutes cost should be paid;
	// - Each subscriber has "minutes-free" equal to 30 minutes of free talking
	//   inside his operator network, valid for 30 days since the date when
	//   last credit was added;
	// - After free minutes expire, calls inside home operator network are
	//   charged 0.50 per minute;
	// - When calling numbers outside of home network, minute cost is 0.95;
	// - On weekends, first five minutes of every call are free.
	Rules rules("rules.conf");
	rules.parse();

	return EXIT_SUCCESS;
}
