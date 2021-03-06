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
#ifndef RULES_FILE_H
#define RULES_FILE_H

#include <vector>

#include "rules.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// RulesFile class
//-----------------------------------------------------------------------------

/**
 * \brief Represent a file with a set of C3L rules
 */
class RulesFile {
public:

	/**
	 * \brief Create a rules file with the given name
	 */
	explicit RulesFile(std::string rulesFileName);

	virtual ~RulesFile();

	/**
	 * \brief Perform the lexical analysis
	 *
	 * Read the rules file to build a list of tokens
	 */
	void tokenize() /* throws SyntacticErrorException */;

	/**
	 * \brief Parse the rules file to build a Parse-Tree
	 */
	void parse() /* throws SyntacticErrorException */;

	/**
	 * \brief Apply the rules into the call record file
	 */
	void evaluate() /* throws SemanticErrorException */;

	/**
	 * \brief Get a reference to the rules
	 */
	Rules &getRules();

private:
	std::string rulesFileName_;
	Rules rules_;

};

} // namespace luxoft

#endif /* RULES_FILE_H */
