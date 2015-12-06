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
#include <tr1/memory>

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

	std::tr1::shared_ptr<FloatingObject> getFloatingObject(const std::string &objectName);
	std::tr1::shared_ptr<StringObject> getStringObject(const std::string &objectName);

private:
	// When we reference "call_total_cost", for example, we reference
	// one single object
	std::map<std::string, std::tr1::shared_ptr<FloatingObject> > floatingObjectTable_;
	std::map<std::string, std::tr1::shared_ptr<StringObject> > stringObjectTable_;

};

} // namespace luxoft

#endif /* OBJECT_TABLE_H */
