------------------------------------------------------------------------------
 Problem #4
------------------------------------------------------------------------------

Luxoft job application test #4
Author: Guilherme Maciel Ferreira <guilherme.maciel.ferreira@gmail.com>


------------------------------------------------------------------------------
 Problem description
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
 Implementation details
------------------------------------------------------------------------------

In order to allow a easy modifiable set of rules. I moded it to a configuration
file. The rules file is a kind of domain language, where the user has a level
of freedom to define call cost formula.

Each variable name in rules.conf is composed of the following elements:
- Units (minute, day, etc) are suffix;
- Objects (call, call_inside, call_outside) are prefix;
- Object attributes (duration, period, fee, cost) are at the middle.

