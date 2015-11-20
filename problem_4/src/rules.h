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

#include <map>
#include <string>
#include <vector>

namespace luxoft {

//-----------------------------------------------------------------------------
// Token class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
enum TokenType {
	TOKEN_TYPE_OBJECT,
	TOKEN_TYPE_NUMERIC_CONSTANT,
	TOKEN_TYPE_ARITHMETIC_OPERATOR,
};

/**
 * TODO
 */
class Token {
public:
	Token(const std:: string &value, TokenType type);

	std::string getValue() const;
	void setValue(const std::string &value);

	TokenType getType() const;
	void setType(const TokenType type);

	static TokenType discoverType(const std::string &name);

private:
	std::string value_;
	TokenType type_;

};

//-----------------------------------------------------------------------------
// Object class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class Object {
public:
	Object();
	Object(std::string name, float value = 0);
	virtual ~Object();

	std::string getName() const;
	void setName(const std::string &name);

	float getValue() const;
	void setValue(const float value);

private:
	std::string name_;
	float value_;

};


//-----------------------------------------------------------------------------
// ObjectTable class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class ObjectTable {
public:
	static const std::string callConnectionCostTotal;
	static const std::string callBonusAmountMinute;
	static const std::string callBonusDurationMinute;
	static const std::string callBonusPeriodDay;
	static const std::string callInsideItems;
	static const std::string callInsideBonusAmountMinute;
	static const std::string callInsideCostMinute;
	static const std::string callOutsideCostMinute;
	static const std::string callCostTotal;
	static const std::string callDurationMinute;
	static const std::string callCostMinute;

public:
	ObjectTable();
	virtual ~ObjectTable();

	Object *getObject(const std::string &objectName);

private:
	// When we reference "call_bonus_duration_minute", for example, we reference
	// one single object
	std::map<std::string, Object*> symbolTable_;
};


//-----------------------------------------------------------------------------
// Operation class
//-----------------------------------------------------------------------------

/**
 * Arithmetic operation
 */
class Operation {
public:
	Operation();
	virtual ~Operation();

	virtual float execute(const float a, const float b) const = 0;

};


//-----------------------------------------------------------------------------
// AdditionOperation class
//-----------------------------------------------------------------------------

/**
 * Arithmetic addition operation
 */
class AdditionOperation : public Operation {
public:
	virtual float execute(const float a, const float b) const;

};


//-----------------------------------------------------------------------------
// SubtractionOperation class
//-----------------------------------------------------------------------------

/**
 * Arithmetic subtraction operation
 */
class SubtractionOperation : public Operation {
public:
	virtual float execute(const float a, const float b) const;

};


//-----------------------------------------------------------------------------
// MultiplicationOperation class
//-----------------------------------------------------------------------------

/**
 * Arithmetic multiplication operation
 */
class MultiplicationOperation : public Operation {
public:
	virtual float execute(const float a, const float b) const;

};


//-----------------------------------------------------------------------------
// DivisionOperation class
//-----------------------------------------------------------------------------

/**
 * Arithmetic division operation
 */
class DivisionOperation : public Operation {
public:
	virtual float execute(const float a, const float b) const;

};


//-----------------------------------------------------------------------------
// OperationTable class
//-----------------------------------------------------------------------------

/**
 * This class maps std::string to Operation instances
 */
class OperationTable {
public:
	/**
	 * \brief Get the operation corresponding to the symbol
	 *
	 * \param symbol Arithmetic operation symbol
	 *
	 * \return An Operation subclass
	 */
	static Operation *getOperation(const std::string &symbol);

};

//-----------------------------------------------------------------------------
// Expression class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class Expression {
public:
	Expression();

	virtual ~Expression();

	void parse(
		ObjectTable *objectTable,
		const std::vector<Token*> &tokens);

	float getValue() const;

private:
	Object *object_;
	Expression *expression_;
	Operation *operation_;
	float constant_;

};


//-----------------------------------------------------------------------------
// Statement class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class Statement {
public:
	Statement();

	virtual ~Statement();

	virtual void parse(
		ObjectTable *objectTable,
		const std::vector<Token*> &tokens) = 0;

	virtual void execute() = 0;

};


//-----------------------------------------------------------------------------
// CommandStatement class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class CommandStatement : public Statement {
public:
	CommandStatement();

	virtual ~CommandStatement();

	virtual void parse(
		ObjectTable *objectTable,
		const std::vector<Token*> &tokens);

	virtual void execute();

private:
	Object *object_;

};


//-----------------------------------------------------------------------------
// AssignmentStatement class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class AssignmentStatement : public Statement {
public:
	AssignmentStatement();

	virtual ~AssignmentStatement();

	virtual void parse(
		ObjectTable *objectTable,
		const std::vector<Token*> &tokens);

	virtual void execute();

private:
	Object *lvalueObject_;
	Expression *rvalueExpression_;

};

//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class RuleLine {
public:
	/**
	 * TODO
	 */
	RuleLine();

	/**
	 * TODO
	 */
	virtual ~RuleLine();

	/**
	 * \brief Separate (tokenize) all elements of a line
	 */
	void tokenize(const std::string &line);

	/**
	 * TODO
	 */
	void parse(ObjectTable *objectTable) /* TODO throws SyntaxError */;

	/**
	 * TODO
	 */
	void execute() /* TODO throws SemanticError */;

private:
	std::vector<Token*> tokens_;
	Statement *statement_;

};


//-----------------------------------------------------------------------------
// Rules class
//-----------------------------------------------------------------------------

/**
 * TODO
 */
class Rules {
public:

	/**
	 * TODO
	 */
	Rules();

	/**
	 * TODO
	 */
	virtual ~Rules();

	/**
	 * \brief Perform the lexical analysis
	 *
	 * Read the rules file to build a list of tokens
	 */
	void tokenize(const std::string &fileName);

	/**
	 * \brief Parse the rules file to build a Parse-Tree
	 */
	void parse() /* TODO throws SyntaxError */;

	/**
	 * \brief Apply the rules into the call record file
	 */
	void execute(const std::string &callFileName) /* TODO throws SemanticError */;

private:
	bool isValidLine(const std::string &line);


	std::vector<RuleLine*> ruleLines_;
	ObjectTable *objectTable_;

};

} // namespace luxoft

#endif /* RULES_H */
