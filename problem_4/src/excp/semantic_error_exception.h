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
#ifndef SEMANTIC_ERROR_EXCEPTION_H
#define SEMANTIC_ERROR_EXCEPTION_H

#include "compilation_error_exception.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// SemanticErrorException class
//-----------------------------------------------------------------------------

/**
 * \brief Semantic error that occur during syntax analysis
 */
class SemanticErrorException: public CompilationErrorException
{
public:
	explicit SemanticErrorException(int lineNumber)
	: CompilationErrorException(lineNumber, "Semantic error")
	{
	}

	virtual ~SemanticErrorException() throw()
	{
	}

};


} // namespace luxoft

#endif /* SEMANTIC_ERROR_EXCEPTION_H */
