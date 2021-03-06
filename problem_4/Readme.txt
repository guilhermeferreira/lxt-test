------------------------------------------------------------------------------
 Problem #4
------------------------------------------------------------------------------

Job Application Test #4
Company: Luxoft
Author: Guilherme Maciel Ferreira <guilherme.maciel.ferreira@gmail.com>


------------------------------------------------------------------------------
 1. Problem description
------------------------------------------------------------------------------

Test task is to create code for simplified billing of a mobile network operator.
We use the following rules for calculating call cost:

 - Fixed connection fee of 0.33 that is added to any call cost;

 - Minute fee is charged at the beginning of each minute, so if call duration
   is 1:03, two minutes cost should be paid;

 - Each subscriber has 30 minutes of free talking inside his operator network,
   valid for 30 days since the date when last credit was added;

 - After free minutes expire, calls inside home operator network are charged
   0.50 per minute;

 - When calling numbers outside of home network, minute cost is 0.95;

 - On weekends, first five minutes of every call are free.

We define home network of the operator as a set of phone numbers starting with
one of the given prefixes (050, 066, 095, and 099).

Your main objective is to create code calculating call cost, given date and
time for its start and end, number called, and subscriber account information.

Please make your code readable and easy to configure, maintain and modify. We
expect some kind of demo application allowing testing your code with some
example data, but do not make it overly complicated.


------------------------------------------------------------------------------
 2. Solution description
------------------------------------------------------------------------------

These are the options that I'm aware to solve this problem (i.e. define rules
for calculating call cost):

- Use of hardcoded rules and the variable values in the code;

- Use of configuration files to parameterize the variable values, but still
  having hardcoded rules;

- Use of a domain specific language to parameterize both rules and variable
  values.

In order to make the rules easy to extend and modify, I created a very simple
interpreted domain language called "Call Cost Calculation Language", or C3L.
This principle follows the ones presented in sections 12 (Domain Languages) and
20 (Code Generators) of the book "The Pragmatic Programmer". As stated in the
task document: "Design architecture in the most scalable way, especially
concerning calls cost calculation algorithm"; the most scalable way to define
algothms is to leave the definition outside of the compiled code.

The user specify the calls records through a serie of input files. Section 2.1
explains how to use the program.

The call cost rules are described through a file in which the user has high
degree of freedom to define call cost formula. Each line represents a statement
in the rules file. Basically, each language element has three methods:
 - tokenize() that performs the lexical analysis, breaking the input string into
   tokens recognized by the language;
 - parse() that performs the syntactic analysis of the tokens, creating a parse-
   tree as result; and
 - evaluate() that performs the semantic analysis.
Section 2.2 describes the C3L grammar.

The other input is a file with a list of call records. Each line in this file
represents a unique call. Section 2.3 describes the calls record file.

My solution consists to interpret the call cost calculation rules (i.e. create
a parse-tree of the rules) and apply these rules to each call record.


------------------------------------------------------------------------------
 2.1. Program usage
------------------------------------------------------------------------------

Enter a input file with list of calls

  $ ./problem_4 <call-rules-file> <list-of-call-input>

Example command line:
  $ ./problem_4 rules.c3l call1.rec call2.rec


------------------------------------------------------------------------------
 2.2. Call rules file
------------------------------------------------------------------------------

The rules are defined in the Call Cost Calculation Language (C3L). This is a
simple context-free grammar I created for this sample application.


------------------------------------------------------------------------------
 2.2.1. C3L Grammar
------------------------------------------------------------------------------

The C3L grammar is described bellow in Backus-Naur Form. A symbol delimited by
angle brackets (e.g. <non-terminal>) is a non terminal symbol. A symbol delimted
by double quotes (e.g. "terminal") is a terminal symbol. Each line must contain
one and only one rule:

  <rules>                ::= <rule_line> <rules>

  <rule_line>            ::= <statement>

  <statement>            ::= <command_statement>
                           | <assignment_statement>
                           | <selection_statement>

  <command_statement>    ::= <command> <arithmetic_expression>

  <assignment_statement> ::= <readwrite_object> "=" <arithmetic_expression>

  <selection_statement>  ::= "if" <condition_expression> "then" <statement> "end"

  <command>              ::= "print"

  <arithmetic_expression>::= <operand> "+" <arithmetic_expression>
                           | <operand> "-" <arithmetic_expression>
                           | <operand> "*" <arithmetic_expression>
                           | <operand> "/" <arithmetic_expression>
                           | <operand>

  <condition_expression> ::= <operand> "in" "[" <constant_list> "]"

  <operand>              ::= <readwrite_object>
                           | <readonly_object>
                           | <numeric_constant>

  <readwrite_object>     ::= "call_total_cost"
                           | "call_minute_cost"
                           | "call_connection_cost"
                           | "call_bonus_quantity_minute"
                           | "call_bonus_validity_minute"

  <readonly_object>      ::= "call_duration_minute"
                           | "call_destination_prefix"
                           | "call_period_day"

  <constant_list>        ::= <numeric_constant>
                           | <textual_constant>

  <numeric_constant>     ::= <floating_constant>
                           | <integer_constant>

  <floating_constant>    ::= <integer_constant> "." <digit>

  <integer_constant>     ::= <digit><integer_constant>
                           | <digit>

  <digit>                ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

  <textual_constant>     ::= <letter><textual_constant>
                           | <letter>

  <letter>               ::= "a" .. "z"


------------------------------------------------------------------------------
 2.2.1. C3L Objects
------------------------------------------------------------------------------

The meaning of each <object> is described bellow:

 - call_total_cost = the total cost of the call;

 - call_minute_cost = the cost of the call per minute;

 - call_connection_cost = the fixed connection fee (e.g. $0.33) that is
   added to any call cost;

 - call_bonus_quantity_minute = subscriber's minutes of free talking (e.g.
   30 minutes);

 - call_bonus_validity_minute = validity of subscriber's minutes of free
   talking (e.g. 30 days since the date when last credit was added);

 - call_duration_minute = the duration of the call;

 - call_destination_prefix = the callee phone number prefix;

 - call_period_day = the day of the call;


------------------------------------------------------------------------------
 2.2.3. C3L Assumptions
------------------------------------------------------------------------------

Some limitations, simplifications and assumptions regarding the C3L:

 - All keywords ("print", "if", "call_xxx", etc.) are at the begining of the
   statement.

 - Selection statements (i.e. "if") must be contained in one line. There is no
   support for multiple-line statements within a selection statement.


------------------------------------------------------------------------------
 2.3. Call records file
------------------------------------------------------------------------------

The call records is a comma-separated values (CSV) file. The separator is a
semicolon (';') instead of a comma (','). The format is in accordance with the
RFC 4180. Each line (call record) has the format:

                 Start;End;Destination;Source

Where:
 - Start is the week date and the time (hh:mm:ss) of the call start;
 - End indicates the week date and the time (hh:mm:ss) that the call has
   finished;
 - Destination contains the number called;
 - Source describes the caller phone number (subscriber account
   information).


------------------------------------------------------------------------------
 2.4. Implementation notes
------------------------------------------------------------------------------

a. I didn't use any STL smart pointers because std::auto_ptr ownership transfer
   issue is a huge headache. And I'm not sure if you have a C++11 compliant
   compiler to use std::shared_ptr and std::unique_ptr. Neither I used Boost's
   smart pointers (e.g. boost::shared_ptr and boost::scoped_ptr) because you
   said "Try to use only STL library".

b. I use assertation to ensure that code satisfies the methods pre-conditions.

c. I decided to use a 3rd party test suite. Simply because there are options
   much better (vesatile, robust and scalable) than what I can develope in a
   few days.

d. I chose the Autotools buildsystems instead of CMake because I'm not sure if
   you had the cmake installed. The automake and autoconf are more common in
   Unix systems.

e. The program is limited to parse 1-digit precision floating point constants
   (e.g. 2.5, 89.6, 14.8). This limitation is to avoid precision loss due the
   IEEE 754 floating-point used internally by the interpreter.

f. I'd limited the exception handling to language's syntax and semantic
   analysis. Because those steps are critical and it is better kill the
   program than run with incorrect parse-tree.

g. Once thou shalt "NOT use DB", the calls are recorded in a CSV (RFC 4180).
   This is the simpler format I'm aware of.

