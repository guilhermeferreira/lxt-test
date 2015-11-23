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
#ifndef CALL_RECORD_H
#define CALL_RECORD_H

#include <string>
#include <vector>

#include "object.h"
#include "object_table.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// CallRecord class
//-----------------------------------------------------------------------------

/**
 * This class represents a line of the call records file
 */
class CallRecord {
public:

	explicit CallRecord(const int lineNumber);

	virtual ~CallRecord();

	/**
	 * \brief Parse the record line and place the values into the object table
	 */
	void process(
		const std::string &recordLine,
		ObjectTable &objectTable);

private:

	/**
	 * \brief Extract the values from a record line
	 */
	bool getFields(
		const std::string &recordLine,
		std::string *callStartDate,
		std::string *callEndDate,
		std::string *callDestNumber,
		std::string *callSrcNumber) const;

	/**
	 * \brief Get the difference in minutes of the end and start time of the call
	 */
	float getCallDuration(
		std::string &callStartTime,
		std::string &callEndTime) const;

	/**
	 * \brief Place the given values into their respective objects of the table
	 */
	void setObjects(
		const float callDuration,
		const std::string &callDestNumber,
		const std::string &callDay,
		ObjectTable &objectTable);


	int lineNumber_;

};

} // namespace luxoft

#endif /* CALL_RECORD_H */
