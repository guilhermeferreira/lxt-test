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
#include "rules.h"

#include <cassert>

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

namespace luxoft {

using namespace std;

//-----------------------------------------------------------------------------
// Object class
//-----------------------------------------------------------------------------

Object::Object()
: name_(""), value_(0)
{
}

//-----------------------------------------------------------------------------

Object::Object(string name, float value)
: name_(name), value_(value)
{
}

//-----------------------------------------------------------------------------

Object::~Object()
{
}

//-----------------------------------------------------------------------------

string Object::getName() const
{
	return name_;
}

//-----------------------------------------------------------------------------

void Object::setName(const string &name)
{
	name_ = name;
}

//-----------------------------------------------------------------------------

float Object::getValue() const
{
	return value_;
}

//-----------------------------------------------------------------------------

void Object::setValue(const float value)
{
	value_ = value;
}


//-----------------------------------------------------------------------------
// ObjectTable class
//-----------------------------------------------------------------------------

const string ObjectTable::callConnectionCostTotal = "call_connection_cost_total";
const string ObjectTable::callBonusAmountMinute = "call_bonus_amount_minute";
const string ObjectTable::callBonusDurationMinute = "call_bonus_duration_minute";
const string ObjectTable::callBonusPeriodDay = "call_bonus_period_day";
const string ObjectTable::callInsideItems = "call_inside_items";
const string ObjectTable::callInsideBonusAmountMinute = "call_inside_bonus_amount_minute";
const string ObjectTable::callInsideCostMinute = "call_inside_cost_minute";
const string ObjectTable::callOutsideCostMinute = "call_outside_cost_minute";
const string ObjectTable::callCostTotal = "call_cost_total";
const string ObjectTable::callDurationMinute = "call_duration_minute";
const string ObjectTable::callCostMinute = "call_cost_minute";

//-----------------------------------------------------------------------------

ObjectTable::ObjectTable() : symbolTable_()
{
	symbolTable_[ObjectTable::callConnectionCostTotal] = new Object(ObjectTable::callConnectionCostTotal);
	symbolTable_[ObjectTable::callBonusAmountMinute] = new Object(ObjectTable::callBonusAmountMinute);
	symbolTable_[ObjectTable::callBonusDurationMinute] = new Object(ObjectTable::callBonusDurationMinute);
	symbolTable_[ObjectTable::callBonusPeriodDay] = new Object(ObjectTable::callBonusPeriodDay);
	symbolTable_[ObjectTable::callInsideItems] = new Object(ObjectTable::callInsideItems);
	symbolTable_[ObjectTable::callInsideBonusAmountMinute] = new Object(ObjectTable::callInsideBonusAmountMinute);
	symbolTable_[ObjectTable::callInsideCostMinute] = new Object(ObjectTable::callInsideCostMinute);
	symbolTable_[ObjectTable::callOutsideCostMinute] = new Object(ObjectTable::callOutsideCostMinute);
	symbolTable_[ObjectTable::callCostTotal] = new Object(ObjectTable::callCostTotal);
	symbolTable_["call_connection_cost_total"] = new Object("call_connection_cost_total");
	symbolTable_[ObjectTable::callDurationMinute] = new Object(ObjectTable::callDurationMinute);
	symbolTable_[ObjectTable::callCostMinute] = new Object(ObjectTable::callCostMinute);
}

//-----------------------------------------------------------------------------

ObjectTable::~ObjectTable()
{
}

//-----------------------------------------------------------------------------

Object *ObjectTable::getObject(const string &objectName)
{
	return symbolTable_[objectName];
}

//-----------------------------------------------------------------------------
// Operation class
//-----------------------------------------------------------------------------

Operation::Operation()
{
}

//-----------------------------------------------------------------------------

Operation::~Operation()
{
}


//-----------------------------------------------------------------------------
// AdditionOperation class
//-----------------------------------------------------------------------------

float AdditionOperation::execute(const float a, const float b) const
{
	return (a + b);
}


//-----------------------------------------------------------------------------
// SubtractionOperation class
//-----------------------------------------------------------------------------

float SubtractionOperation::execute(const float a, const float b) const
{
	return (a - b);
}


//-----------------------------------------------------------------------------
// MultiplicationOperation class
//-----------------------------------------------------------------------------

float MultiplicationOperation::execute(const float a, const float b) const
{
	return (a * b);
}


//-----------------------------------------------------------------------------
// DivisionOperation class
//-----------------------------------------------------------------------------

float DivisionOperation::execute(const float a, const float b) const
{
	return (a / b);
}


//-----------------------------------------------------------------------------
// OperationTable class
//-----------------------------------------------------------------------------

Operation *OperationTable::getOperation(const string &symbol)
{
	if (symbol == "+") {
		return new AdditionOperation;
	}
	else if (symbol == "-") {
		return new SubtractionOperation;
	}
	else if (symbol == "*") {
		return new MultiplicationOperation;
	}
	else if (symbol == "/") {
		return new DivisionOperation;
	}
	else {
		return NULL;
	}

}

//-----------------------------------------------------------------------------
// Expression class
//-----------------------------------------------------------------------------

Expression::Expression()
: object_(NULL), expression_(NULL), operation_(NULL), constant_(0)
{
}

//-----------------------------------------------------------------------------

Expression::~Expression()
{
}

//-----------------------------------------------------------------------------

void Expression::parse(
	ObjectTable *objectTable,
	const vector<Token*> &tokens)
{
	assert(objectTable != NULL);
	assert(!tokens.empty());

	// This loop process only the first 1 or 2 elements:
	//
	//    <object>
	//    <object> "+"
	//    <object> "-"
	//    <object> "*"
	//    <object> "/"
	//    <numeric_constant>
	//
	// The remaining <expression> is processed recursively (i.e. it's a context-
	// free grammar anyways)


	// process expressions with a single operand, variable (object) or constant
	Token *firstToken = tokens[0];
	switch (firstToken->getType()) {
		case TOKEN_TYPE_OBJECT: {
			string objectName = firstToken->getValue();
			object_ = objectTable->getObject(objectName);
			break;
		}
		case TOKEN_TYPE_NUMERIC_CONSTANT: {
			string numericValue = firstToken->getValue();
			istringstream stream(numericValue);
			stream >> constant_;
			break;
		}
		default:
			/* TODO throw MalformedExpression */
			break;
	}

	// process expressions that have an operand, an arithmetic operator and
	// another expression
	if (tokens.size() > 1) {
		Token *secondToken = tokens[1];
		switch (secondToken->getType()) {
			case TOKEN_TYPE_ARITHMETIC_OPERATOR: {
				string operationSymbol = secondToken->getValue();
				operation_ = OperationTable::getOperation(operationSymbol);
				break;
			}
			default:
				/* TODO throw MalformedExpression */
				break;
		}

		vector<Token*> remainingTokens(tokens.begin() + 2, tokens.end());
		expression_ = new Expression;
		expression_->parse(objectTable, remainingTokens);
	}

}

//-----------------------------------------------------------------------------

float Expression::getValue() const
{
	if ((object_ != NULL) && (expression_ != NULL)) {
		assert(operation_ != NULL);

		return operation_->execute(object_->getValue(), expression_->getValue());

	} else if ((object_ != NULL) && (expression_ == NULL)) {
		return object_->getValue();

	} else { // ((object_ == NULL) && (expression_ != NULL))
		return constant_;

	}
}


//-----------------------------------------------------------------------------
// Statement class
//-----------------------------------------------------------------------------

Statement::Statement()
{
}

//-----------------------------------------------------------------------------

Statement::~Statement()
{
}


//-----------------------------------------------------------------------------
// CommandStatement class
//-----------------------------------------------------------------------------

CommandStatement::CommandStatement()
: object_(NULL)
{
}

//-----------------------------------------------------------------------------

CommandStatement::~CommandStatement()
{
}

//-----------------------------------------------------------------------------

void CommandStatement::parse(
	ObjectTable *objectTable,
	const vector<Token*> &tokens)
{
	assert(objectTable != NULL);
	assert(!tokens.empty());
	assert(object_ == NULL);

	string commandName = tokens[0]->getValue();
	assert(commandName == "print");

	string objectName = tokens[1]->getValue();
	object_ = objectTable->getObject(objectName);
}

//-----------------------------------------------------------------------------

void CommandStatement::execute()
{
	assert(object_ != NULL);
	assert(!object_->getName().empty());

	cout << object_->getName() << " = " << object_->getValue() << endl;
}


//-----------------------------------------------------------------------------
// AssignmentStatement class
//-----------------------------------------------------------------------------

AssignmentStatement::AssignmentStatement()
: lvalueObject_(NULL), rvalueExpression_(NULL)
{
}

//-----------------------------------------------------------------------------

AssignmentStatement::~AssignmentStatement()
{
}

//-----------------------------------------------------------------------------

void AssignmentStatement::parse(
	ObjectTable *objectTable,
	const vector<Token*> &tokens)
{
	assert(objectTable != NULL);
	assert(!tokens.empty());
	assert(lvalueObject_ == NULL);
	assert(rvalueExpression_ == NULL);

	// Consume left hand side token, that is the variable (object) name
	string objectName = tokens[0]->getValue();
	lvalueObject_ = objectTable->getObject(objectName);

	// Consume the assignment operator
	string operatorSymbol = tokens[1]->getValue();
	assert(operatorSymbol == "=");

	// Expression can consume only the right hand side tokens
	vector<Token*> remainingTokens(tokens.begin() + 2, tokens.end());
	rvalueExpression_ = new Expression;
	rvalueExpression_->parse(objectTable, remainingTokens);
}

//-----------------------------------------------------------------------------

void AssignmentStatement::execute()
{
	assert(lvalueObject_ != NULL);
	assert(rvalueExpression_ != NULL);

	lvalueObject_->setValue(rvalueExpression_->getValue());
}


//-----------------------------------------------------------------------------
// Token class
//-----------------------------------------------------------------------------

Token::Token(const string &value, TokenType type)
: value_(value), type_(type)
{
}

//-----------------------------------------------------------------------------

string Token::getValue() const
{
	return value_;
}

//-----------------------------------------------------------------------------

void Token::setValue(const string &value)
{
	value_ = value;
}

//-----------------------------------------------------------------------------

TokenType Token::getType() const
{
	return type_;
}

//-----------------------------------------------------------------------------

void Token::setType(const TokenType type)
{
	type_ = type;
}

//-----------------------------------------------------------------------------

TokenType Token::discoverType(const string &name)
{
	string operators = "+-*/=";
	string numeric_literal = "0123456789";

	if (name.find_first_of(operators) != string::npos) {
		return TOKEN_TYPE_ARITHMETIC_OPERATOR;

	} else if (name.find_first_of(numeric_literal) != string::npos) {
		return TOKEN_TYPE_NUMERIC_CONSTANT;

	} else {
		return TOKEN_TYPE_OBJECT;
	}
}


//-----------------------------------------------------------------------------
// RuleLine class
//-----------------------------------------------------------------------------

RuleLine::RuleLine()
: tokens_(NULL), statement_(NULL)
{
}

//-----------------------------------------------------------------------------

RuleLine::~RuleLine()
{
}

//-----------------------------------------------------------------------------

void RuleLine::tokenize(const string &line)
{
	assert(tokens_.empty());
	assert(statement_ == NULL);

	string consumableLine = line;

	// Place a symbol at the end so the algorithm can find the last token.
	// This has the same purpose as the ';' at the end of C++ statements
	const string tokenDelimiters = " ";
	consumableLine.push_back(tokenDelimiters[0]);

	size_t tokenEndPos = consumableLine.find_first_of(tokenDelimiters);
	while (tokenEndPos != string::npos) {
		const string &tokenValue = consumableLine.substr(0, tokenEndPos);
		TokenType tokenType = Token::discoverType(tokenValue);
		Token *token = new Token(tokenValue, tokenType);

		tokens_.push_back(token);

		consumableLine.erase(0, tokenEndPos + 1);

		tokenEndPos = consumableLine.find_first_of(tokenDelimiters);
	}
}

//-----------------------------------------------------------------------------

void RuleLine::parse(ObjectTable *objectTable)
{
	assert(objectTable != NULL);
	assert(!tokens_.empty());
	assert(statement_ == NULL);

	const string firstToken = tokens_[0]->getValue();
	size_t firstTokenPrefixEndPos = firstToken.find_first_of("_");
	if (firstTokenPrefixEndPos == string::npos) {
		// TODO throw SyntaxError("")
	}

	const string firstTokenPrefix = firstToken.substr(0, firstTokenPrefixEndPos);
	if (firstTokenPrefix == "call") {
		statement_ = new AssignmentStatement;
		statement_->parse(objectTable, tokens_);
	} else if (firstTokenPrefix == "print") {
		statement_ = new CommandStatement;
		statement_->parse(objectTable, tokens_);
	} else {
		// TODO throw SyntaxError("Invalid statement prefix", firstTokenPrefix)
	}


}

//-----------------------------------------------------------------------------

void RuleLine::execute()
{
	assert(!tokens_.empty());
	assert(statement_ != NULL);

	statement_->execute();
}


//-----------------------------------------------------------------------------
// Rules class
//-----------------------------------------------------------------------------

Rules::Rules()
: ruleLines_(), objectTable_(new ObjectTable)
{
}

//-----------------------------------------------------------------------------

Rules::~Rules()
{
	delete objectTable_;
}

//-----------------------------------------------------------------------------

void Rules::tokenize(const string &fileName)
{
	/*
	 1. Lexical analysis breaks the source code text into small pieces called tokens.
	    Each token is a single atomic unit of the language, for instance a keyword,
	    identifier or symbol name. The token syntax is typically a regular language,
	    so a finite state automaton constructed from a regular expression can be used
	    to recognize it. This phase is also called lexing or scanning, and the software
	    doing lexical analysis is called a lexical analyzer or scanner. This may not
	    be a separate step it can be combined with the parsing step in scannerless
	    parsing, in which case parsing is done at the character level, not the token level.
	 */

	assert(!fileName.empty());

	// TODO openFile()
	ifstream rulesFile(fileName.c_str());
	if (!rulesFile) {
		cerr << "File '" << fileName << "' not found" << endl;
	}

	if (!rulesFile.is_open()) {
		cerr << "File '" << fileName << "' could not be open" << endl;
	}
	// TODO openFile()

	string line;
	while (getline(rulesFile, line)) {
		// Discard comments and white space characters
		if (isValidLine(line)) {

			RuleLine *ruleLine = new RuleLine;
			ruleLine->tokenize(line);

			ruleLines_.push_back(ruleLine);
		}
	}

	rulesFile.close();
}

//-----------------------------------------------------------------------------

void Rules::parse()  /* TODO throws SyntaxError */
{
	/*
	2. Syntax analysis involves parsing the token sequence to identify the syntactic
	   structure of the program. This phase typically builds a parse tree, which replaces
	   the linear sequence of tokens with a tree structure built according to the rules of
	   a formal grammar which define the language's syntax. The parse tree is often
	   analyzed, augmented, and transformed by later phases in the compiler.
	*/

	assert(!ruleLines_.empty());

	string line;
	for (vector<RuleLine*>::iterator it = ruleLines_.begin(); it != ruleLines_.end(); ++it) {
		RuleLine *ruleLine = *it;
		ruleLine->parse(objectTable_);
	}

}

//-----------------------------------------------------------------------------

void Rules::execute(const string &callFileName) /* TODO throws SemanticError */
{
	/*
	3. Semantic analysis is the phase in which the compiler adds semantic information
	   to the parse tree and builds the symbol table. This phase performs semantic checks
	   such as type checking (checking for type errors), or object binding (associating
	   variable and function references with their definitions), or definite assignment
	   (requiring all local variables to be initialized before use), rejecting incorrect
	   programs or issuing warnings. Semantic analysis usually requires a complete parse
	   tree, meaning that this phase logically follows the parsing phase, and logically
	   precedes the code generation phase, though it is often possible to fold multiple
	   phases into one pass over the code in a compiler implementation.
	 */

	assert(!ruleLines_.empty());

	string line;
	for (vector<RuleLine*>::iterator it = ruleLines_.begin(); it != ruleLines_.end(); ++it) {
		RuleLine *ruleLine = *it;
		ruleLine->execute();
	}

}

//-----------------------------------------------------------------------------

bool Rules::isValidLine(const string &line)
{
	bool isComment = (line[0] == '#');
	bool isBlankLine = (line.empty() || (line[0] == '\n'));

	return (!isComment && !isBlankLine);
}

//-----------------------------------------------------------------------------

} // namespace luxoft
