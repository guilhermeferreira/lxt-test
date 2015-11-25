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
#ifndef OBJECT_H
#define OBJECT_H

#include <string>


namespace luxoft {

//-----------------------------------------------------------------------------
// Object template
//-----------------------------------------------------------------------------

/**
 * Represent the non-terminal <object>
 */
template <typename T>
class Object {
public:
	Object();
	Object(std::string name, T value, bool rulesReadOnly = false);
	virtual ~Object();

	std::string getName() const;

	bool isRulesReadOnly() const;

	T getValue() const;
	void setValue(const T &value);

private:
	std::string name_;
	T value_;
	bool isRulesReadOnly_;

};


//-----------------------------------------------------------------------------
// FloatingObject specialization
//-----------------------------------------------------------------------------

typedef Object<float> FloatingObject;

//-----------------------------------------------------------------------------
// StringObject specialization
//-----------------------------------------------------------------------------

typedef Object<std::string> StringObject;

//-----------------------------------------------------------------------------


} // namespace luxoft

#endif /* OBJECT_H */
