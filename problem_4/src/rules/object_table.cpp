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

const string ObjectTable::CALL_CONNECTION_COST_TOTAL = "call_connection_cost_total";
const string ObjectTable::CALL_BONUS_AMOUNT_MINUTE = "call_bonus_amount_minute";
const string ObjectTable::CALL_BONUS_DURATION_MINUTE = "call_bonus_duration_minute";
const string ObjectTable::CALL_BONUS_PERIOD_DAY = "call_bonus_period_day";
const string ObjectTable::CALL_INSIDE_ITEMS = "call_inside_items";
const string ObjectTable::CALL_INSIDE_BONUS_AMOUNT_MINUTE = "call_inside_bonus_amount_minute";
const string ObjectTable::CALL_INSIDE_COST_MINUTE = "call_inside_cost_minute";
const string ObjectTable::CALL_OUTSIDE_COST_MINUTE = "call_outside_cost_minute";
const string ObjectTable::CALL_DURATION_MINUTE = "call_duration_minute";
const string ObjectTable::CALL_COST_MINUTE = "call_cost_minute";
const string ObjectTable::CALL_COST_TOTAL = "call_cost_total";

//-----------------------------------------------------------------------------

ObjectTable::ObjectTable()
: callConnectionCostTotal(ObjectTable::CALL_CONNECTION_COST_TOTAL),
  callBonusAmountMinute(ObjectTable::CALL_BONUS_AMOUNT_MINUTE),
  callBonusDurationMinute(ObjectTable::CALL_BONUS_DURATION_MINUTE),
  callBonusPeriodDay(ObjectTable::CALL_BONUS_PERIOD_DAY),
  callInsideItems(ObjectTable::CALL_INSIDE_ITEMS),
  callInsideBonusAmountMinute(ObjectTable::CALL_INSIDE_BONUS_AMOUNT_MINUTE),
  callInsideCostMinute(ObjectTable::CALL_INSIDE_COST_MINUTE),
  callOutsideCostMinute(ObjectTable::CALL_OUTSIDE_COST_MINUTE),
  callDurationMinute(ObjectTable::CALL_DURATION_MINUTE),
  callCostMinute(ObjectTable::CALL_COST_MINUTE),
  callCostTotal(ObjectTable::CALL_COST_TOTAL)
{
	symbolTable_[ObjectTable::CALL_CONNECTION_COST_TOTAL] = &callConnectionCostTotal;
	symbolTable_[ObjectTable::CALL_BONUS_AMOUNT_MINUTE] = &callBonusAmountMinute;
	symbolTable_[ObjectTable::CALL_BONUS_DURATION_MINUTE] = &callBonusDurationMinute;
	symbolTable_[ObjectTable::CALL_BONUS_PERIOD_DAY] = &callBonusPeriodDay;
	symbolTable_[ObjectTable::CALL_INSIDE_ITEMS] = &callInsideItems;
	symbolTable_[ObjectTable::CALL_INSIDE_BONUS_AMOUNT_MINUTE] = &callInsideBonusAmountMinute;
	symbolTable_[ObjectTable::CALL_INSIDE_COST_MINUTE] = &callInsideCostMinute;
	symbolTable_[ObjectTable::CALL_OUTSIDE_COST_MINUTE] = &callOutsideCostMinute;
	symbolTable_[ObjectTable::CALL_DURATION_MINUTE] = &callDurationMinute;
	symbolTable_[ObjectTable::CALL_COST_MINUTE] = &callCostMinute;
	symbolTable_[ObjectTable::CALL_COST_TOTAL] = &callCostTotal;
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
