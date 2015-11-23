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
	static const std::string callConnectionCostTotal;
	static const std::string callBonusAmountMinute;
	static const std::string callBonusDurationMinute;
	static const std::string callBonusPeriodDay;
	static const std::string callInsideItems;
	static const std::string callInsideBonusAmountMinute;
	static const std::string callInsideCostMinute;
	static const std::string callOutsideCostMinute;
	static const std::string callCostTotal;
	static const std::string callDurationMinute;
	static const std::string callCostMinute;

public:
	ObjectTable();
	virtual ~ObjectTable();

	Object *getObject(const std::string &objectName);

private:
	// When we reference "call_bonus_duration_minute", for example, we reference
	// one single object
	std::map<std::string, Object*> symbolTable_;
};

} // namespace luxoft

#endif /* OBJECT_TABLE_H */
