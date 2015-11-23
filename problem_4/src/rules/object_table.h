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
 * TODO
 */
class ObjectTable {
public:
	static const std::string CALL_CONNECTION_COST_TOTAL;
	static const std::string CALL_BONUS_AMOUNT_MINUTE;
	static const std::string CALL_BONUS_DURATION_MINUTE;
	static const std::string CALL_BONUS_PERIOD_DAY;
	static const std::string CALL_INSIDE_ITEMS;
	static const std::string CALL_INSIDE_BONUS_AMOUNT_MINUTE;
	static const std::string CALL_INSIDE_COST_MINUTE;
	static const std::string CALL_OUTSIDE_COST_MINUTE;
	static const std::string CALL_DURATION_MINUTE;
	static const std::string CALL_COST_MINUTE;
	static const std::string CALL_COST_TOTAL;

public:
	ObjectTable();
	virtual ~ObjectTable();

	Object *getObject(const std::string &objectName);

private:
	// When we reference "call_bonus_duration_minute", for example, we reference
	// one single object
	std::map<std::string, Object*> symbolTable_;

	Object callConnectionCostTotal;
	Object callBonusAmountMinute;
	Object callBonusDurationMinute;
	Object callBonusPeriodDay;
	Object callInsideItems;
	Object callInsideBonusAmountMinute;
	Object callInsideCostMinute;
	Object callOutsideCostMinute;
	Object callDurationMinute;
	Object callCostMinute;
	Object callCostTotal;
};

} // namespace luxoft

#endif /* OBJECT_TABLE_H */
