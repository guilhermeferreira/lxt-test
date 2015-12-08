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
#include "rotation.h"

#include <cassert>

#include <algorithm>
#include <iostream>


namespace luxoft {

bool isRotation(
	const std::string &s1,
	const std::string &s2)
{
	// If we imagine that s1 and s2 are two sets of characters, this problem
	// can be reduced to know if both sets have the same elements. We might
	// perform a lexicographical ordering on both sets and check if the
	// resulting sets are equal.
	std::string sorted_s1 = s1;
	std::string sorted_s2 = s2;

	std::sort(sorted_s1.begin(), sorted_s1.end());
	std::sort(sorted_s2.begin(), sorted_s2.end());

	std::cout << "sorted s1 = '" << sorted_s1 << "'" << std::endl;
	std::cout << "sorted s2 = '" << sorted_s2 << "'" << std::endl;

	return (sorted_s1.compare(sorted_s2) == 0);
}

} // namespace luxoft
