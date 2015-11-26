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
#include "call_record.h"

#include <cassert>
#include <cmath>

#include <iostream>
#include <sstream>

#include "call_time.h"


namespace luxoft {

using namespace std;


//-----------------------------------------------------------------------------
// CallRecord class
//-----------------------------------------------------------------------------

CallRecord::CallRecord(const int lineNumber)
: lineNumber_(lineNumber)
{
}

//-----------------------------------------------------------------------------

CallRecord::~CallRecord()
{
}

//-----------------------------------------------------------------------------

void CallRecord::process(
	const std::string &recordLine,
	ObjectTable &objectTable)
{
	assert(!recordLine.empty());

	string callStartDate;
	string callEndDate;
	string callDestNumber;
	string callSrcNumber;

	if (getFields(recordLine, &callStartDate, &callEndDate, &callDestNumber, &callSrcNumber)) {

		size_t callStartDayLen = callStartDate.find('-', 0);
		string callStartDay = callStartDate.substr(0, callStartDayLen);
		string callStartTime = callStartDate.substr(callStartDayLen + 1);

		size_t callEndDayLen = callEndDate.find('-', 0);
		string callEndDay = callEndDate.substr(0, callEndDayLen);
		string callEndTime = callEndDate.substr(callEndDayLen + 1);

		// FIXME The call duration computation is limited to calls on the same day.
		int callDuration = getCallDurationInMin(callStartTime, callEndTime);
		if (callDuration > 0.0) {

			setObjects(callDuration, callDestNumber, callStartDay, objectTable);

		} else {
			// Negative call durations are invalid
			cerr << "Error: "  << lineNumber_ << ": invalid call duration" << endl;
		}
	} else {
		// If the record is not well-formatted, do not proceed, but don't
		// throw an exception. So the next record can be processed
		cerr << "Error: "  << lineNumber_ << ": invalid record" << endl;
	}

}

//-----------------------------------------------------------------------------

bool CallRecord::getFields(
	const string &recordLine,
	string *callStartDate,
	string *callEndDate,
	string *callDestNumber,
	string *callSrcNumber)
{
	assert(!recordLine.empty());

	// Copy the line, do not modify the original
	string line = recordLine;

	// Line in the CSV format
	// Replace ';' by white space ' '. So the tokenizer can parse
	for (size_t pos = line.find(';', 0); pos != string::npos; pos = line.find(';', pos + 1)) {
		line.replace(pos, 1, 1, ' ');
	}

	stringstream lineTokenizer(line);
	lineTokenizer >> *callStartDate >> *callEndDate >> *callDestNumber >> *callSrcNumber;
	if(lineTokenizer.fail())
	{
		return false;
	}

	return true;
}

//-----------------------------------------------------------------------------

int CallRecord::getCallDurationInMin(
	std::string &callStartTime,
	std::string &callEndTime)
{
	assert(!callStartTime.empty());
	assert(callStartTime.length() == (sizeof("hh:mm:ss") - 1));
	assert(!callEndTime.empty());
	assert(callEndTime.length() == (sizeof("hh:mm:ss") - 1));

	stringstream startTimeTokenizer(callStartTime);
	CallTime startTime;
	startTimeTokenizer >> startTime;

	stringstream endDateTokenizer(callEndTime);
	CallTime endTime;
	endDateTokenizer >> endTime;

	int callDurationInMinutes = endTime - startTime;

	return callDurationInMinutes;
}

//-----------------------------------------------------------------------------

void CallRecord::setObjects(
	const float callDuration,
	const string &callDestNumber,
	const string &callDay,
	ObjectTable &objectTable)
{
	assert(callDuration > 0.0);
	assert(!callDestNumber.empty());
	assert(!callDay.empty());

	// The read-only objects are not writable by the rules at C3L, but must be
	// fulfilled by the call record.
	//
	//  <readonly_object>      ::= "call_duration_minute"
	//                           | "call_destination_prefix"
	//                           | "call_period_day"

	FloatingObject *callDurationMinute = objectTable.getObject(ObjectTable::CALL_DURATION_MINUTE);
	assert(callDurationMinute != NULL);
	callDurationMinute->setValue(callDuration);

	StringObject *callDestinationPrefix = objectTable.getDetailObject(ObjectTable::CALL_DESTINATION_PREFIX);
	assert(callDestinationPrefix != NULL);
	string callDestNumberPrefix = callDestNumber.substr(0, 3);
	callDestinationPrefix->setValue(callDestNumberPrefix);

	StringObject *callPeriodDay = objectTable.getDetailObject(ObjectTable::CALL_PERIOD_DAY);
	assert(callPeriodDay != NULL);
	callPeriodDay->setValue(callDay);
}


//-----------------------------------------------------------------------------


} // namespace luxoft
