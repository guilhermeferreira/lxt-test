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
#ifndef RULES_H
#define RULES_H

#include <iostream>
#include <string>
#include <vector>

#include "rule_line.h"
#include "object_table.h"

namespace luxoft {

//-----------------------------------------------------------------------------
// Rules class
//-----------------------------------------------------------------------------

/**
 * \brief Represent a set of C3L rules
 */
class Rules {
public:

	Rules();

	virtual ~Rules();

	/**
	 * \brief Perform the lexical analysis
	 *
	 * Read the rules file to build a list of tokens
	 */
	void tokenize(std::istream &ruleStream) /* throws SyntacticErrorException */;

	/**
	 * \brief Perform the syntax analysis, parsing the rules file to build a Parse-Tree
	 */
	void parse() /* throws SyntacticErrorException */;

	/**
	 * \brief Apply the rules into the call record file
	 */
	void evaluate() /* throws SemanticErrorException */;

	/**
	 * \brief Get a reference to the object symbol table
	 */
	ObjectTable &getObjectTable();

private:
	bool isValidLine(const std::string &line);

	std::vector<RuleLine*> ruleLines_;
	ObjectTable objectTable_;

};

} // namespace luxoft

#endif /* RULES_H */
