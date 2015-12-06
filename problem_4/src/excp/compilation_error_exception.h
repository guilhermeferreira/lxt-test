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
#ifndef COMPILATION_ERROR_EXCEPTION_H
#define COMPILATION_ERROR_EXCEPTION_H

#include <stdexcept>
#include <string>
#include <sstream>


namespace luxoft {

//-----------------------------------------------------------------------------
// CompilationErrorException class
//-----------------------------------------------------------------------------

/**
 * \brief Generic compilation error
 */
class CompilationErrorException: public std::runtime_error
{
public:
	CompilationErrorException(
		int lineNumber,
		const std::string &errorMsg)
	: runtime_error(errorMsg), lineNumber_(lineNumber)
	{
	}

	virtual ~CompilationErrorException() throw()
	{
	}

	virtual const char *what() const throw()
	{
		std::stringstream ss;
		ss << lineNumber_;
		ss << ": ";
		ss << runtime_error::what();

		std::string msg = ss.str();

		return msg.c_str();
	}

private:
	int lineNumber_;

};


} // namespace luxoft

#endif /* COMPILATION_ERROR_EXCEPTION_H */
