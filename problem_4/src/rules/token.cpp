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
#include "token.h"

#include <cassert>


namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// Token class
//-----------------------------------------------------------------------------

Token::Token(const string &value, TokenType type)
: value_(value), type_(type)
{
}

//-----------------------------------------------------------------------------

string Token::getValue() const
{
	return value_;
}

//-----------------------------------------------------------------------------

TokenType Token::getType() const
{
	return type_;
}

//-----------------------------------------------------------------------------

TokenType Token::discoverType(const string &value)
{
	assert(!value.empty());

	string operators = "+-*/=";
	string numeric_literal = "0123456789";

	if (value.find_first_of(operators) != string::npos) {
		return TOKEN_TYPE_ARITHMETIC_OPERATOR;

	} else if (value.find_first_of(numeric_literal) != string::npos) {
		return TOKEN_TYPE_NUMERIC_CONSTANT;

	} else {
		return TOKEN_TYPE_OBJECT;
	}
}


} // namespace luxoft
