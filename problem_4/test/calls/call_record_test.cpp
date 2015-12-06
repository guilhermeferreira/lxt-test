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
#include "call_record_test.h"

using namespace std;
using namespace std::tr1;
using namespace luxoft;


//-----------------------------------------------------------------------------
// CallRecordTest class
//-----------------------------------------------------------------------------

CallRecordTest::CallRecordTest()
{
	TEST_ADD(CallRecordTest::process_Test);
	TEST_ADD(CallRecordTest::getFields_Test);
	TEST_ADD(CallRecordTest::getCallDurationInMin_Test);
	TEST_ADD(CallRecordTest::setObjects_Test);
}

//-----------------------------------------------------------------------------

void CallRecordTest::process_Test()
{
	CallRecord callRecord(1);
	ObjectTable objTable;
	shared_ptr<FloatingObject> callDurationObject = objTable.getFloatingObject(ObjectTable::CALL_DURATION_MINUTE);
	shared_ptr<StringObject> callDestNumberObject = objTable.getStringObject(ObjectTable::CALL_DESTINATION_PREFIX);
	shared_ptr<StringObject> callDayObject = objTable.getStringObject(ObjectTable::CALL_PERIOD_DAY);
	string recLine;

	recLine = "sunday-02:00:00;sunday-12:40:00;01011111111;02022222222;";
	callRecord.process(recLine, objTable);
	TEST_ASSERT(callDurationObject->getValue() == 640);
	TEST_ASSERT(callDayObject->getValue() == "sunday");
	TEST_ASSERT(callDestNumberObject->getValue() == "010");

	recLine = "thursday-20:10:00;thursday-21:00:00;03033333333;04044444444;";
	callRecord.process(recLine, objTable);
	TEST_ASSERT(callDurationObject->getValue() == 50.0);
	TEST_ASSERT(callDayObject->getValue() == "thursday");
	TEST_ASSERT(callDestNumberObject->getValue() == "030");
}

//-----------------------------------------------------------------------------

void CallRecordTest::getFields_Test()
{
	string recLine;
	string startDate;
	string endDate;
	string destNumber;
	string srcNumber;

	recLine = "sunday-13:40:20;sunday-13:45:30;05099876765;05099875634;";
	TEST_ASSERT(CallRecord::getFields(recLine, &startDate, &endDate, &destNumber, &srcNumber));
	TEST_ASSERT(startDate == "sunday-13:40:20");
	TEST_ASSERT(endDate == "sunday-13:45:30");
	TEST_ASSERT(destNumber == "05099876765");
	TEST_ASSERT(srcNumber == "05099875634");

	recLine = "thursday-20:10:20;thursday-21:00:05;05099876765;05099875634;";
	TEST_ASSERT(CallRecord::getFields(recLine, &startDate, &endDate, &destNumber, &srcNumber));
	TEST_ASSERT(startDate == "thursday-20:10:20");
	TEST_ASSERT(endDate == "thursday-21:00:05");
	TEST_ASSERT(destNumber == "05099876765");
	TEST_ASSERT(srcNumber == "05099875634");
}

//-----------------------------------------------------------------------------

void CallRecordTest::getCallDurationInMin_Test()
{
	string time1 = "06:40:20";
	string time2 = "08:20:30";
	TEST_ASSERT(CallRecord::getCallDurationInMin(time1, time2) == 100);
	TEST_ASSERT(CallRecord::getCallDurationInMin(time2, time1) == -100);


	string time3 = "20:49:20";
	string time4 = "23:59:00";
	TEST_ASSERT(CallRecord::getCallDurationInMin(time3, time4) == 189);
	TEST_ASSERT(CallRecord::getCallDurationInMin(time4, time3) == -189);

	string time5 = "07:35:50";
	string time6 = "14:05:10";
	TEST_ASSERT(CallRecord::getCallDurationInMin(time5, time6) == 390);
	TEST_ASSERT(CallRecord::getCallDurationInMin(time6, time5) == -390);
}

//-----------------------------------------------------------------------------

void CallRecordTest::setObjects_Test()
{
	ObjectTable objTable;
	shared_ptr<FloatingObject> callDurationObject = objTable.getFloatingObject(ObjectTable::CALL_DURATION_MINUTE);
	shared_ptr<StringObject> callDestNumberObject = objTable.getStringObject(ObjectTable::CALL_DESTINATION_PREFIX);
	shared_ptr<StringObject> callDayObject = objTable.getStringObject(ObjectTable::CALL_PERIOD_DAY);

	float callDuration = 16.4;
	string callDestNumber = "011";
	string callDay = "sunday";
	CallRecord::setObjects(callDuration, callDestNumber, callDay, objTable);
	TEST_ASSERT(callDuration == callDurationObject->getValue());
	TEST_ASSERT(callDestNumber == callDestNumberObject->getValue());
	TEST_ASSERT(callDay == callDayObject->getValue());


	callDuration = 567.4;
	callDestNumber = "048";
	callDay = "wednesday";
	CallRecord::setObjects(callDuration, callDestNumber, callDay, objTable);
	TEST_ASSERT(callDuration == callDurationObject->getValue());
	TEST_ASSERT(callDestNumber == callDestNumberObject->getValue());
	TEST_ASSERT(callDay == callDayObject->getValue());
}
