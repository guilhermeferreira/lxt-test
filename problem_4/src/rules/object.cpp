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
#include "object.h"

#include <cassert>

#include <limits>


namespace luxoft {

using namespace std;


//-----------------------------------------------------------------------------
// Object template
//-----------------------------------------------------------------------------

template class Object<float>;
template class Object<std::string>;

//-----------------------------------------------------------------------------

template <typename T>
Object<T>::Object()
: name_(""),
  value_(),
  isRulesReadOnly_(false)
{
}
template Object<float>::Object();
template Object<string>::Object();

//-----------------------------------------------------------------------------

template <typename T>
Object<T>::Object(string name, T value, bool rulesReadOnly)
: name_(name),
  value_(value),
  isRulesReadOnly_(rulesReadOnly)
{
	assert(!name_.empty());
}
template Object<float>::Object(string name, float value, bool rulesReadOnly);
template Object<string>::Object(string name, string value, bool rulesReadOnly);


//-----------------------------------------------------------------------------

template <typename T>
Object<T>::~Object()
{
}
template Object<float>::~Object();
template Object<string>::~Object();

//-----------------------------------------------------------------------------

template <typename T>
string Object<T>::getName() const
{
	assert(!name_.empty());

	return name_;
}
template string Object<float>::getName() const;
template string Object<string>::getName() const;

//-----------------------------------------------------------------------------

template <typename T>
bool Object<T>::isRulesReadOnly() const
{
	assert(!name_.empty());

	return isRulesReadOnly_;
}
template bool Object<float>::isRulesReadOnly() const;
template bool Object<string>::isRulesReadOnly() const;

//-----------------------------------------------------------------------------

template <typename T>
T Object<T>::getValue() const
{
	assert(!name_.empty());

	return value_;
}
template float Object<float>::getValue() const;
template string Object<string>::getValue() const;

//-----------------------------------------------------------------------------

template <typename T>
void Object<T>::setValue(const T &value)
{
	assert(!name_.empty());

	value_ = value;
}
template void Object<float>::setValue(const float &value);
template void Object<string>::setValue(const string &value);

//-----------------------------------------------------------------------------


} // namespace luxoft
