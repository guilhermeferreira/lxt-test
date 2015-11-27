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
#ifndef CALL_TIME_H
#define CALL_TIME_H

#include <istream>
#include <ostream>
#include <string>


namespace luxoft {

//-----------------------------------------------------------------------------
// Time class
//-----------------------------------------------------------------------------

/**
 * \brief Class to manipulate chronological dates
 *
 * References:
 *   Stroustrup, Bjarne. The C++ Programming Language, 4th Edition. Section D.4.4.2 - A Date Class.
 *   Stroustrup, Bjarne. The C++ Programming Language, Special 3rd Edition. Section 16.3 - Concrete Classes
 */
class CallTime {
public:
	/**
	 * \brief Build a call time with the default 00:00:00
	 */
	CallTime();

	/**
	 * \brief Build a call time with the given hh:mm:ss
	 */
	CallTime(const int hh, const int mm, const int ss);


	~CallTime();

	/**
	 * \brief Compute the difference in minutes between this and another Time
	 */
	int operator-(const CallTime& other);

	/**
	 * \brief Extraction operator reads from the input stream a time in "hh:mm:ss" format
	 */
	friend std::istream& operator>>(std::istream &is, CallTime& dt);

	/**
	 * \brief Insertion operator writes into the output stream a time in "hh:mm:ss" format
	 */
	friend std::ostream& operator<<(std::ostream &os, const CallTime& dt);

private:
	int hour_;
	int minutes_;
	int seconds_;

};


} // namespace luxoft

#endif /* CALL_TIME_H */
