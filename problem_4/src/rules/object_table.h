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
#ifndef OBJECT_TABLE_H
#define OBJECT_TABLE_H

#include <map>
#include <string>

#include "object.h"

namespace luxoft {

//-----------------------------------------------------------------------------
// ObjectTable class
//-----------------------------------------------------------------------------

/**
 * \brief The object store with all variable symbols
 */
class ObjectTable {
public:
	static const std::string CALL_TOTAL_COST;
	static const std::string CALL_MINUTE_COST;
	static const std::string CALL_CONNECTION_COST;
	static const std::string CALL_DURATION_MINUTE;
	static const std::string CALL_DESTINATION_PREFIX;
	static const std::string CALL_PERIOD_DAY;
	static const std::string CALL_BONUS_QUANTITY_MINUTE;
	static const std::string CALL_BONUS_VALIDITY_MINUTE;

public:
	ObjectTable();
	virtual ~ObjectTable();

	FloatingObject *getFloatingObject(const std::string &objectName);
	StringObject *getStringObject(const std::string &objectName);

private:
	// When we reference "call_total_cost", for example, we reference
	// one single object
	std::map<std::string, FloatingObject*> floatingObjectTable_;
	std::map<std::string, StringObject*> stringObjectTable_;

	// Floating-point monetary costs
	FloatingObject callTotalCost;
	FloatingObject callMinuteCost;
	FloatingObject callConnectionCost;

	// FIXME I decided to make the Minute objects floating-point because
	//       they are writable and must share the same methods as the costs.
	//       Otherwise I would have to make a special cases to handle
	//       integer or floating-point objects. This decision simplifies
	//       the code

	// Integer duration in minutes
	FloatingObject callDurationMinute;
	FloatingObject callBonusQuantityMinute;
	FloatingObject callBonusValityMinute;

	// String details
	StringObject callDestinationPrefix;
	StringObject callPeriodDay;

};

} // namespace luxoft

#endif /* OBJECT_TABLE_H */
