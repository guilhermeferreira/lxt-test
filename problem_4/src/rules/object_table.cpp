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
using namespace std::tr1;

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
{
	// Floating-point monetary costs
	FloatingObject *callTotalCost = new FloatingObject(ObjectTable::CALL_TOTAL_COST, 0.0);
	FloatingObject *callMinuteCost = new FloatingObject(ObjectTable::CALL_MINUTE_COST, 0.0);
	FloatingObject *callConnectionCost = new FloatingObject(ObjectTable::CALL_CONNECTION_COST, 0.0);
	floatingObjectTable_[ObjectTable::CALL_TOTAL_COST] = shared_ptr<FloatingObject>(callTotalCost);
	floatingObjectTable_[ObjectTable::CALL_MINUTE_COST] = shared_ptr<FloatingObject>(callMinuteCost);
	floatingObjectTable_[ObjectTable::CALL_CONNECTION_COST] = shared_ptr<FloatingObject>(callConnectionCost);

	// FIXME I decided to make the Minute objects floating-point because
	//       they are writable and must share the same methods as the costs.
	//       Otherwise I would have to make a special cases to handle
	//       integer or floating-point objects. This decision simplifies
	//       the code

	// Integer duration in minutes
	FloatingObject *callDurationMinute = new FloatingObject(ObjectTable::CALL_DURATION_MINUTE, 0, true);
	FloatingObject *callBonusQuantityMinute = new FloatingObject(ObjectTable::CALL_BONUS_QUANTITY_MINUTE, 0);
	FloatingObject *callBonusValityMinute = new FloatingObject(ObjectTable::CALL_BONUS_VALIDITY_MINUTE, 0);
	floatingObjectTable_[ObjectTable::CALL_DURATION_MINUTE] = shared_ptr<FloatingObject>(callDurationMinute);
	floatingObjectTable_[ObjectTable::CALL_BONUS_QUANTITY_MINUTE] = shared_ptr<FloatingObject>(callBonusQuantityMinute);
	floatingObjectTable_[ObjectTable::CALL_BONUS_VALIDITY_MINUTE] = shared_ptr<FloatingObject>(callBonusValityMinute);

	// String details
	StringObject *callDestinationPrefix = new StringObject(ObjectTable::CALL_DESTINATION_PREFIX, "", true);
	StringObject *callPeriodDay = new StringObject(ObjectTable::CALL_PERIOD_DAY, "", true);
	stringObjectTable_[ObjectTable::CALL_DESTINATION_PREFIX] = shared_ptr<StringObject>(callDestinationPrefix);
	stringObjectTable_[ObjectTable::CALL_PERIOD_DAY] = shared_ptr<StringObject>(callPeriodDay);
}

//-----------------------------------------------------------------------------

ObjectTable::~ObjectTable()
{
}

//-----------------------------------------------------------------------------

shared_ptr<FloatingObject> ObjectTable::getFloatingObject(const string &objectName)
{
	assert(!objectName.empty());
	assert(!floatingObjectTable_.empty());

	return floatingObjectTable_[objectName];
}

//-----------------------------------------------------------------------------

shared_ptr<StringObject> ObjectTable::getStringObject(const string &objectName)
{
	assert(!objectName.empty());
	assert(!stringObjectTable_.empty());

	return stringObjectTable_[objectName];
}

//-----------------------------------------------------------------------------


} // namespace luxoft
