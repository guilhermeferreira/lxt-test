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
#include "object_table.h"

#include <cassert>


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// ObjectTable class
//-----------------------------------------------------------------------------

const string ObjectTable::callConnectionCostTotal = "call_connection_cost_total";
const string ObjectTable::callBonusAmountMinute = "call_bonus_amount_minute";
const string ObjectTable::callBonusDurationMinute = "call_bonus_duration_minute";
const string ObjectTable::callBonusPeriodDay = "call_bonus_period_day";
const string ObjectTable::callInsideItems = "call_inside_items";
const string ObjectTable::callInsideBonusAmountMinute = "call_inside_bonus_amount_minute";
const string ObjectTable::callInsideCostMinute = "call_inside_cost_minute";
const string ObjectTable::callOutsideCostMinute = "call_outside_cost_minute";
const string ObjectTable::callCostTotal = "call_cost_total";
const string ObjectTable::callDurationMinute = "call_duration_minute";
const string ObjectTable::callCostMinute = "call_cost_minute";

//-----------------------------------------------------------------------------

ObjectTable::ObjectTable() : symbolTable_()
{
	symbolTable_[ObjectTable::callConnectionCostTotal] = new Object(ObjectTable::callConnectionCostTotal);
	symbolTable_[ObjectTable::callBonusAmountMinute] = new Object(ObjectTable::callBonusAmountMinute);
	symbolTable_[ObjectTable::callBonusDurationMinute] = new Object(ObjectTable::callBonusDurationMinute);
	symbolTable_[ObjectTable::callBonusPeriodDay] = new Object(ObjectTable::callBonusPeriodDay);
	symbolTable_[ObjectTable::callInsideItems] = new Object(ObjectTable::callInsideItems);
	symbolTable_[ObjectTable::callInsideBonusAmountMinute] = new Object(ObjectTable::callInsideBonusAmountMinute);
	symbolTable_[ObjectTable::callInsideCostMinute] = new Object(ObjectTable::callInsideCostMinute);
	symbolTable_[ObjectTable::callOutsideCostMinute] = new Object(ObjectTable::callOutsideCostMinute);
	symbolTable_[ObjectTable::callCostTotal] = new Object(ObjectTable::callCostTotal);
	symbolTable_[ObjectTable::callDurationMinute] = new Object(ObjectTable::callDurationMinute);
	symbolTable_[ObjectTable::callCostMinute] = new Object(ObjectTable::callCostMinute);
}

//-----------------------------------------------------------------------------

ObjectTable::~ObjectTable()
{
}

//-----------------------------------------------------------------------------

Object *ObjectTable::getObject(const string &objectName)
{
	assert(!objectName.empty());
	assert(!symbolTable_.empty());

	return symbolTable_[objectName];
}

} // namespace luxoft
