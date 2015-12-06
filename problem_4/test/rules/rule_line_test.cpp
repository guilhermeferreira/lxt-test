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
#include "rule_line_test.h"

#include <cmath>
#include <limits>

using namespace std;
using namespace std::tr1;
using namespace luxoft;


//-----------------------------------------------------------------------------
// RuleLineTest class
//-----------------------------------------------------------------------------

RuleLineTest::RuleLineTest()
{
	TEST_ADD(RuleLineTest::constantAssignmentStatement_Test);
	TEST_ADD(RuleLineTest::expressionAssignmentStatement_Test);
	TEST_ADD(RuleLineTest::trueSelectionStatement_Test);
	TEST_ADD(RuleLineTest::falseSelectionStatement_Test);
}

//-----------------------------------------------------------------------------

void RuleLineTest::constantAssignmentStatement_Test()
{
	ObjectTable objTable;

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	RuleLine rl1(1);
	rl1.tokenize("call_total_cost = 14.2");
	rl1.parse(objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) > numeric_limits<float>::epsilon());
	rl1.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callMinuteCost = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	RuleLine rl2(2);
	rl2.tokenize("call_minute_cost = 35.8");
	rl2.parse(objTable);
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) > numeric_limits<float>::epsilon());
	rl2.evaluate();
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callConnectionCost = objTable.getFloatingObject(ObjectTable::CALL_CONNECTION_COST);
	RuleLine rl3(3);
	rl3.tokenize("call_connection_cost = 45.7");
	rl3.parse(objTable);
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) > numeric_limits<float>::epsilon());
	rl3.evaluate();
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusQuantityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_QUANTITY_MINUTE);
	RuleLine rl4(4);
	rl4.tokenize("call_bonus_quantity_minute = 74.5");
	rl4.parse(objTable);
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) > numeric_limits<float>::epsilon());
	rl4.evaluate();
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusValidityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_VALIDITY_MINUTE);
	RuleLine rl5(5);
	rl5.tokenize("call_bonus_validity_minute = 62.3");
	rl5.parse(objTable);
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) > numeric_limits<float>::epsilon());
	rl5.evaluate();
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void RuleLineTest::expressionAssignmentStatement_Test()
{
	ObjectTable objTable;

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	RuleLine rl1(1);
	rl1.tokenize("call_total_cost = 14.2 + 5.8");
	rl1.parse(objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 20.0f) > numeric_limits<float>::epsilon());
	rl1.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 20.0f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callMinuteCost = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	RuleLine rl2(2);
	rl2.tokenize("call_minute_cost = 10.5 + call_total_cost * 2");
	rl2.parse(objTable);
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 50.5f) > numeric_limits<float>::epsilon());
	rl2.evaluate();
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 50.5f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callConnectionCost = objTable.getFloatingObject(ObjectTable::CALL_CONNECTION_COST);
	RuleLine rl3(3);
	rl3.tokenize("call_connection_cost = 9.5 + call_minute_cost");
	rl3.parse(objTable);
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 60.0f) > numeric_limits<float>::epsilon());
	rl3.evaluate();
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 60.0f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusQuantityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_QUANTITY_MINUTE);
	RuleLine rl4(4);
	rl4.tokenize("call_bonus_quantity_minute = call_connection_cost - 30.0");
	rl4.parse(objTable);
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 30.0f) > numeric_limits<float>::epsilon());
	rl4.evaluate();
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 30.0f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusValidityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_VALIDITY_MINUTE);
	RuleLine rl5(5);
	rl5.tokenize("call_bonus_validity_minute = 100.0 + 1.5 * call_bonus_quantity_minute");
	rl5.parse(objTable);
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 145.0f) > numeric_limits<float>::epsilon());
	rl5.evaluate();
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 145.0f) < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void RuleLineTest::trueSelectionStatement_Test()
{
	ObjectTable objTable;

	shared_ptr<StringObject> callPeriodDay = objTable.getStringObject(ObjectTable::CALL_PERIOD_DAY);
	callPeriodDay->setValue("monday");

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	RuleLine rl1(1);
	rl1.tokenize("if call_period_day in [ sunday monday wednesday ] then call_total_cost = 14.2 end");
	rl1.parse(objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) > numeric_limits<float>::epsilon());
	rl1.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callMinuteCost = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	RuleLine rl2(2);
	rl2.tokenize("if call_period_day in [ sunday monday wednesday ] then call_minute_cost = 35.8 end");
	rl2.parse(objTable);
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) > numeric_limits<float>::epsilon());
	rl2.evaluate();
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callConnectionCost = objTable.getFloatingObject(ObjectTable::CALL_CONNECTION_COST);
	RuleLine rl3(3);
	rl3.tokenize("if call_period_day in [ sunday monday wednesday ] then call_connection_cost = 45.7 end");
	rl3.parse(objTable);
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) > numeric_limits<float>::epsilon());
	rl3.evaluate();
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusQuantityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_QUANTITY_MINUTE);
	RuleLine rl4(4);
	rl4.tokenize("if call_period_day in [ sunday monday wednesday ] then call_bonus_quantity_minute = 74.5 end");
	rl4.parse(objTable);
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) > numeric_limits<float>::epsilon());
	rl4.evaluate();
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) < numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusValidityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_VALIDITY_MINUTE);
	RuleLine rl5(5);
	rl5.tokenize("if call_period_day in [ sunday monday wednesday ] then call_bonus_validity_minute = 62.3 end");
	rl5.parse(objTable);
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) > numeric_limits<float>::epsilon());
	rl5.evaluate();
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) < numeric_limits<float>::epsilon());
}

//-----------------------------------------------------------------------------

void RuleLineTest::falseSelectionStatement_Test()
{
	ObjectTable objTable;

	shared_ptr<StringObject> callPeriodDay = objTable.getStringObject(ObjectTable::CALL_PERIOD_DAY);
	callPeriodDay->setValue("saturday");

	shared_ptr<FloatingObject> callTotalCost = objTable.getFloatingObject(ObjectTable::CALL_TOTAL_COST);
	RuleLine rl1(1);
	rl1.tokenize("if call_period_day in [ sunday monday wednesday ] then call_total_cost = 14.2 end");
	rl1.parse(objTable);
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) > numeric_limits<float>::epsilon());
	rl1.evaluate();
	TEST_ASSERT(fabs(callTotalCost->getValue() - 14.2f) > numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callMinuteCost = objTable.getFloatingObject(ObjectTable::CALL_MINUTE_COST);
	RuleLine rl2(2);
	rl2.tokenize("if call_period_day in [ sunday monday wednesday ] then call_minute_cost = 35.8 end");
	rl2.parse(objTable);
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) > numeric_limits<float>::epsilon());
	rl2.evaluate();
	TEST_ASSERT(fabs(callMinuteCost->getValue() - 35.8f) > numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callConnectionCost = objTable.getFloatingObject(ObjectTable::CALL_CONNECTION_COST);
	RuleLine rl3(3);
	rl3.tokenize("if call_period_day in [ sunday monday wednesday ] then call_connection_cost = 45.7 end");
	rl3.parse(objTable);
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) > numeric_limits<float>::epsilon());
	rl3.evaluate();
	TEST_ASSERT(fabs(callConnectionCost->getValue() - 45.7f) > numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusQuantityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_QUANTITY_MINUTE);
	RuleLine rl4(4);
	rl4.tokenize("if call_period_day in [ sunday monday wednesday ] then call_bonus_quantity_minute = 74.5 end");
	rl4.parse(objTable);
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) > numeric_limits<float>::epsilon());
	rl4.evaluate();
	TEST_ASSERT(fabs(callBonusQuantityMinute->getValue() - 74.5f) > numeric_limits<float>::epsilon());

	shared_ptr<FloatingObject> callBonusValidityMinute = objTable.getFloatingObject(ObjectTable::CALL_BONUS_VALIDITY_MINUTE);
	RuleLine rl5(5);
	rl5.tokenize("if call_period_day in [ sunday monday wednesday ] then call_bonus_validity_minute = 62.3 end");
	rl5.parse(objTable);
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) > numeric_limits<float>::epsilon());
	rl5.evaluate();
	TEST_ASSERT(fabs(callBonusValidityMinute->getValue() - 62.3f) > numeric_limits<float>::epsilon());
}
