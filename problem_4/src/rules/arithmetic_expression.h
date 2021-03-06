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
#ifndef ARITHMETIC_EXPRESSION_H
#define ARITHMETIC_EXPRESSION_H

#include <tr1/memory>
#include <vector>

#include "expression.h"
#include "object.h"
#include "object_table.h"
#include "operation.h"
#include "token.h"

namespace luxoft {

//-----------------------------------------------------------------------------
// ArithmeticExpression class
//-----------------------------------------------------------------------------

/**
 * \brief The <arithmetic_expression> non-terminal symbol
 *
 *    <arithmetic_expression> ::= <operand> "+" <arithmetic_expression>
 *                              | <operand> "-" <arithmetic_expression>
 *                              | <operand> "*" <arithmetic_expression>
 *                              | <operand> "/" <arithmetic_expression>
 *                              | <operand>
 */
class ArithmeticExpression : public Expression {
public:
	explicit ArithmeticExpression(const int lineNumber);

	virtual ~ArithmeticExpression();

	/**
	 * \brief Recursively build the <arithmetic_expression> non-terminal parsing-tree
	 */
	void parse(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	/**
	 * \brief Evaluate recursively the expression (and its sub-expressions) value
	 */
	float evaluate() const;

private:
	/**
	 * \brief Parse the <operand> token from the production rule
	 *
	 *     <arithmetic_expression> ::= <operand> "op" <arithmetic_expression>
	 */
	void parseOperand(
			std::vector< std::tr1::shared_ptr<Token> > &tokens,
			ObjectTable &objectTable);

	/**
	 * \brief Parse the operator "op" token from the production rule
	 *
	 *     <arithmetic_expression> ::= <operand> "op" <arithmetic_expression>
	 */
	void parseArithmeticOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * \brief Parse the <arithmetic_expression> token from the production rule
	 *
	 *     <arithmetic_expression> ::= <operand> "op" <arithmetic_expression>
	 */
	void parseExpression(
			std::vector< std::tr1::shared_ptr<Token> > &tokens,
			ObjectTable &objectTable);

	std::tr1::shared_ptr<FloatingObject> operand_;
	std::tr1::shared_ptr<ArithmeticExpression> expression_;
	std::tr1::shared_ptr<Operation> operation_;
	float constant_;

};


} // namespace luxoft

#endif /* ARITHMETIC_EXPRESSION_H */
