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

const string ObjectTable::CALL_TOTAL_COST = "call_total_cost";
const string ObjectTable::CALL_MINUTE_COST = "call_minute_cost";
const string ObjectTable::CALL_CONNECTION_COST = "call_connection_cost";
const string ObjectTable::CALL_DURATION_MINUTE = "call_duration_minute";
const string ObjectTable::CALL_BONUS_QUANTITY_MINUTE = "call_bonus_quantity_minute";
const string ObjectTable::CALL_BONUS_VALIDITY_MINUTE = "call_bonus_validity_minute";
const string ObjectTable::CALL_DESTINATION_PREFIX = "call_destination_prefix";
const string ObjectTable::CALL_PERIOD_DAY = "call_period_day";


//-----------------------------------------------------------------------------

ObjectTable::ObjectTable()
: callTotalCost(ObjectTable::CALL_TOTAL_COST, 0.0),
  callMinuteCost(ObjectTable::CALL_MINUTE_COST, 0.0),
  callConnectionCost(ObjectTable::CALL_CONNECTION_COST, 0.0),
  callDurationMinute(ObjectTable::CALL_DURATION_MINUTE, 0, true),
  callBonusQuantityMinute(ObjectTable::CALL_BONUS_QUANTITY_MINUTE, 0),
  callBonusValityMinute(ObjectTable::CALL_BONUS_VALIDITY_MINUTE, 0),
  callDestinationPrefix(ObjectTable::CALL_DESTINATION_PREFIX, "", true),
  callPeriodDay(ObjectTable::CALL_PERIOD_DAY, "", true)
{
	symbolTable_[ObjectTable::CALL_TOTAL_COST] = &callTotalCost;
	symbolTable_[ObjectTable::CALL_MINUTE_COST] = &callMinuteCost;
	symbolTable_[ObjectTable::CALL_CONNECTION_COST] = &callConnectionCost;

	symbolTable_[ObjectTable::CALL_DURATION_MINUTE] = &callDurationMinute;
	symbolTable_[ObjectTable::CALL_BONUS_QUANTITY_MINUTE] = &callBonusQuantityMinute;
	symbolTable_[ObjectTable::CALL_BONUS_VALIDITY_MINUTE] = &callBonusValityMinute;

	detailSymbolTable_[ObjectTable::CALL_DESTINATION_PREFIX] = &callDestinationPrefix;
	detailSymbolTable_[ObjectTable::CALL_PERIOD_DAY] = &callPeriodDay;
}

//-----------------------------------------------------------------------------

ObjectTable::~ObjectTable()
{
}

//-----------------------------------------------------------------------------

FloatingObject *ObjectTable::getFloatingObject(const string &objectName)
{
	assert(!objectName.empty());
	assert(!symbolTable_.empty());

	return symbolTable_[objectName];
}

//-----------------------------------------------------------------------------

StringObject *ObjectTable::getStringObject(const string &objectName)
{
	assert(!objectName.empty());
	assert(!detailSymbolTable_.empty());

	return detailSymbolTable_[objectName];
}

//-----------------------------------------------------------------------------


} // namespace luxoft
