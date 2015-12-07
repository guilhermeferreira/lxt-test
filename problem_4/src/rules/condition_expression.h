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
#ifndef CONDITION_EXPRESSION_H
#define CONDITION_EXPRESSION_H

#include <string>
#include <vector>

#include "expression.h"
#include "object.h"
#include "object_table.h"
#include "operation.h"
#include "token.h"

namespace luxoft {

//-----------------------------------------------------------------------------
// ConditionExpression class
//-----------------------------------------------------------------------------

/**
 * \brief The <condition_expression> non-terminal symbol
 */
class ConditionExpression : public Expression {
public:
	explicit ConditionExpression(const int lineNumber);

	virtual ~ConditionExpression();

	/**
	 * \brief Build the <condition_expression> non-terminal parsing-tree
	 */
	void parse(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	/**
	 * \brief Evaluate recursively the expression value
	 */
	float evaluate() const;

private:
	/**
	 * \brief Parse the <operand> token from the production rule
	 *
	 *     <condition_expression> ::= <operand> "in" "[" <constant_list> "]"
	 */
	void parseOperand(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	/**
	 * \brief Parse the "in" operator token from the production rule
	 *
	 *     <condition_expression> ::= <operand> "in" "[" <constant_list> "]"
	 */
	void parseMembershipOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * \brief Parse the "[" operator token from the production rule
	 *
	 *     <condition_expression> ::= <operand> "in" "[" <constant_list> "]"
	 */
	void parseConditionBeginOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * \brief Parse the "]" operator token from the production rule
	 *
	 *     <condition_expression> ::= <operand> "in" "[" <constant_list> "]"
	 */
	void parseConditionEndOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * \brief Parse the <constant_list> tokens from the production rule
	 *
	 *     <condition_expression> ::= <operand> "in" "[" <constant_list> "]"
	 *
	 *     <constant_list>        ::= <numeric_constant>
     *                              | <textual_constant>
	 */
	void parseConstantList(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	std::tr1::shared_ptr<StringObject> stringOperand_;
	std::string constantList_;

};


} // namespace luxoft

#endif /* CONDITION_EXPRESSION_H */
