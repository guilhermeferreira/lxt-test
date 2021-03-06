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
#ifndef CALLS_FILE_H
#define CALLS_FILE_H

#include <string>
#include <vector>

#include "calls.h"
#include "rules.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// CallsFile class
//-----------------------------------------------------------------------------

/**
 * \brief Represent file with a set of call record lines
 */
class CallsFile {
public:

	/**
	 * \brief Create a calls records file with the given name
	 */
	explicit CallsFile(std::string callsFilesNames);

	virtual ~CallsFile();

	/**
	 * \brief Apply the given rules to each call record line of this file
	 */
	void process(Rules &rules);

private:
	std::string fileName_;
	Calls calls;

};

} // namespace luxoft

#endif /* CALLS_FILE_H */
