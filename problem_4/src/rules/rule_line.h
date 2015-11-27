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
#ifndef RULE_LINE_H
#define RULE_LINE_H

#include <string>
#include <vector>

#include "object_table.h"
#include "statement.h"
#include "token.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

/**
 * \brief A rule line in the C3L
 */
class RuleLine {
public:
	/**
	 * \brief Create a rule from a line
	 */
	explicit RuleLine(const int lineNumber);

	virtual ~RuleLine();

	/**
	 * \brief Separate (tokenize) all elements of a line
	 */
	void tokenize(const std::string &line);

	/**
	 * \brief Create a parse tree for a line
	 */
	void parse(ObjectTable &objectTable) /* throws SyntacticErrorException */;

	/**
	 * \brief Execute the rule at this line
	 */
	void evaluate() /* throws SemanticErrorException */;

private:
	/**
	 * \brief Get a COPY of the line without whitespace characters
	 */
	std::string removeLeadingWhitespaces(const std::string &line) const;

	/**
	 * \brief Get a COPY of the line with a symbol to mark the end of the line
	 */
	std::string addTrailingWhitespaces(
		const std::string &line,
		const std::string &lineDelimiter) const;

	std::vector<Token*> tokens_;
	Statement *statement_;
	int lineNumber_;

};


} // namespace luxoft

#endif /* RULE_LINE_H */
