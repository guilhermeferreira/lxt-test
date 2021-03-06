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
#ifndef ASSIGNMENT_STATEMENT_H
#define ASSIGNMENT_STATEMENT_H

#include <tr1/memory>
#include <vector>

#include "statement.h"
#include "arithmetic_expression.h"
#include "object.h"
#include "object_table.h"
#include "token.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// AssignmentStatement class
//-----------------------------------------------------------------------------

/**
 * \brief Assignment productions rule
 *
 *    <assignment_statement> ::= <object> "=" <arithmetic_expression>
 */
class AssignmentStatement : public Statement {
public:
	explicit AssignmentStatement(const int lineNumber);

	virtual ~AssignmentStatement();

	virtual void parse(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	virtual void evaluate();

private:
	/**
	 * Parse the <readwrite_object> token from the production rule
	 *
	 *    <assignment_statement> ::= <readwrite_object> "=" <arithmetic_expression>
	 */
	void parseObject(
			std::vector< std::tr1::shared_ptr<Token> > &tokens,
			ObjectTable &objectTable);

	/**
	 * Parse the "=" operator token from the production rule
	 *
	 *    <assignment_statement> ::= <readwrite_object> "=" <arithmetic_expression>
	 */
	void parseAssignmentOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * Parse the <arithmetic_expression> token from the production rule
	 *
	 *    <assignment_statement> ::= <readwrite_object> "=" <arithmetic_expression>
	 */
	void parseExpression(
			std::vector< std::tr1::shared_ptr<Token> > &tokens,
			ObjectTable &objectTable);

	std::tr1::shared_ptr<FloatingObject> lvalueObject_;
	std::tr1::shared_ptr<ArithmeticExpression> rvalueExpression_;

};


} // namespace luxoft

#endif /* ASSIGNMENT_STATEMENT_H */
