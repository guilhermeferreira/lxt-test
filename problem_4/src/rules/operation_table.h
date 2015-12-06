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
#ifndef OPERATION_TABLE_H
#define OPERATION_TABLE_H

#include <tr1/memory>
#include <string>

#include "operation.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// OperationTable class
//-----------------------------------------------------------------------------

/**
 * This class maps std::string to Operation instances
 */
class OperationTable {
public:
	/**
	 * \brief Get the operation corresponding to the symbol
	 *
	 * \param symbol Arithmetic operation symbol
	 *
	 * \return An Operation subclass
	 */
	static std::tr1::shared_ptr<Operation> getOperation(
		const std::string &symbol);

};


} // namespace luxoft

#endif /* OPERATION_TABLE_H */
