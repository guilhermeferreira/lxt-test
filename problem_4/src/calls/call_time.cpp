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
#include "call_time.h"

#include <cassert>
#include <cmath>

#include <sstream>

namespace luxoft {

using namespace std;


//-----------------------------------------------------------------------------
// Time class
//-----------------------------------------------------------------------------

CallTime::CallTime()
: hour_(0),
  minutes_(0),
  seconds_(0)
{
}

//-----------------------------------------------------------------------------

CallTime::CallTime(const int hh, const int mm, const int ss)
: hour_(hh),
  minutes_(mm),
  seconds_(ss)
{
}

//-----------------------------------------------------------------------------

CallTime::~CallTime()
{
}

//-----------------------------------------------------------------------------

float CallTime::operator-(const CallTime& other)
{
	// Convert all units to minutes and then subtract

	// NOTE: Minute fee is charged at the beginning of each minute, so if call
	//       duration is 1:03, two minutes cost should be paid.
	//
	//       I solve this by ceiling the seconds division. Because the unit used
	//       to compute the difference is minutes, the seconds must be converted
	//       to minutes. This conversion must evaluate to floating-point, thus
	//       the use of the 60.0 (floating-point literal) constant instead of
	//       60 (integer literal).
	float min1 = (static_cast<float>(hour_) * 60.0f) +
	              static_cast<float>(minutes_) +
	              ceil(static_cast<float>(seconds_) / 60.0f);

	float min2 = (static_cast<float>(other.hour_) * 60.0f) +
	              static_cast<float>(other.minutes_) +
	              ceil(static_cast<float>(other.seconds_) / 60.0f);

	return (min1 - min2);
}

//-----------------------------------------------------------------------------

istream& operator>>(istream &is, CallTime& dt)
{
	is.seekg(0, is.end);
	streampos length = is.tellg();
	is.seekg(0, is.beg);
	assert(length == (sizeof("hh:mm:ss") - 1));

	char colon[2];

	is >> dt.hour_;
	is.getline(colon, sizeof(colon), ':');

	is >> dt.minutes_;
	is.getline(colon, sizeof(colon), ':');

	is >> dt.seconds_;

	return is;
}

//-----------------------------------------------------------------------------

ostream& operator<<(ostream &os, const CallTime& dt)
{
	os << dt.hour_ << ":" << dt.minutes_ << ":" << dt.seconds_;

	return os;
}

//-----------------------------------------------------------------------------


} // namespace luxoft
