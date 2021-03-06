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
#ifndef SELECTION_STATEMENT_H
#define SELECTION_STATEMENT_H

#include <vector>

#include "statement.h"
#include "condition_expression.h"
#include "object.h"
#include "object_table.h"
#include "token.h"


namespace luxoft {

//-----------------------------------------------------------------------------
// SelectionStatement class
//-----------------------------------------------------------------------------

/**
 * \brief Selection production rule
 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
 *                             
 *
 * This is a one-line conditional!
 */
class SelectionStatement : public Statement {
public:
	explicit SelectionStatement(const int lineNumber);

	virtual ~SelectionStatement();

	virtual void parse(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	virtual void evaluate();

private:
	/**
	 * Parse the "if" keyword token from the production rule
	 *
	 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	 */
	void parseSelectionKeyword(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * Parse the <condition_expression> token from the production rule
	 *
	 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	 */
	void parseConditionExpression(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	/**
	 * Parse the "then" keyword token from the production rule
	 *
	 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	 */
	void parseSelectionBeginOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * Parse the "end" keyword token from the production rule
	 *
	 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	 */
	void parseSelectionEndOperator(
		std::vector< std::tr1::shared_ptr<Token> > &tokens);

	/**
	 * Parse the <statement> non-terminal tokens from the production rule
	 *
	 *    <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"
	 */
	void parseStatement(
		std::vector< std::tr1::shared_ptr<Token> > &tokens,
		ObjectTable &objectTable);

	std::tr1::shared_ptr<Expression> conditionExpression_;
	std::tr1::shared_ptr<Statement> ifStatement_;

};


} // namespace luxoft

#endif /* SELECTION_STATEMENT_H */
