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
#include "calls.h"

#include <cassert>

#include <fstream>
#include <string>

#include "rules.h"


namespace luxoft {

using namespace std;
using namespace std::tr1;

//-----------------------------------------------------------------------------
// Calls class
//-----------------------------------------------------------------------------

Calls::Calls()
{
}

//-----------------------------------------------------------------------------

Calls::~Calls()
{
}

//-----------------------------------------------------------------------------

void Calls::process(istream &callsStream, Rules &rules)
{
	assert(records_.empty());

	string line;
	int lineNumber = 1;
	while (getline(callsStream, line)) {
		shared_ptr<CallRecord> record(new CallRecord(lineNumber));

		// WARNING: MAKE A COPY OF OBJECT TABLE for each CallRecord !!!
		//          DO NOT modify the objects' values, otherwise the next
		//          record will be computed using the objects' values from
		//          the previous record computation
		ObjectTable copyObjTable = rules.getObjectTable();

		// If we can't process a record, go to the next. Does NOT halt
		// the program! Keep going!
		try {
			record->process(line, copyObjTable);

			rules.evaluate();

			records_.push_back(record);
		} catch (exception &ex) {
			cerr << "Error: " << ex.what() << endl;
		}

		++lineNumber;
	}

}

//-----------------------------------------------------------------------------


} // namespace luxoft
