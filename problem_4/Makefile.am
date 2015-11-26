bin_PROGRAMS  = problem_4
bin_PROGRAMS += problem_4_test

###############################################################################
# Source Code
###############################################################################

COMMON_SOURCES  = src/rules/rules_file.cpp
COMMON_SOURCES += src/rules/rules.cpp
COMMON_SOURCES += src/rules/rule_line.cpp
COMMON_SOURCES += src/rules/statement.cpp
COMMON_SOURCES += src/rules/assignment_statement.cpp
COMMON_SOURCES += src/rules/command_statement.cpp
COMMON_SOURCES += src/rules/object.cpp
COMMON_SOURCES += src/rules/object_table.cpp
COMMON_SOURCES += src/rules/operation.cpp
COMMON_SOURCES += src/rules/operation_table.cpp
COMMON_SOURCES += src/rules/token.cpp
COMMON_SOURCES += src/rules/expression.cpp
COMMON_SOURCES += src/rules/addition_operation.cpp
COMMON_SOURCES += src/rules/subtraction_operation.cpp
COMMON_SOURCES += src/rules/multiplication_operation.cpp
COMMON_SOURCES += src/rules/division_operation.cpp
COMMON_SOURCES += src/calls/calls_file.cpp
COMMON_SOURCES += src/calls/calls.cpp
COMMON_SOURCES += src/calls/call_record.cpp
COMMON_SOURCES += src/calls/call_time.cpp

problem_4_SOURCES  = src/main.cpp
problem_4_SOURCES += ${COMMON_SOURCES}

TEST_SOURCES  = test/rules/expression_test.cpp
TEST_SOURCES += test/calls/call_record_test.cpp
TEST_SOURCES += test/calls/call_time_test.cpp

problem_4_test_SOURCES  = test/main.cpp
problem_4_test_SOURCES += ${COMMON_SOURCES}
problem_4_test_SOURCES += ${TEST_SOURCES}


###############################################################################
# Compilation Flags
###############################################################################

COMMON_CPPFLAGS  = -I.
COMMON_CPPFLAGS += -I./src
COMMON_CPPFLAGS += -I./src/calls
COMMON_CPPFLAGS += -I./src/excp
COMMON_CPPFLAGS += -I./src/rules
COMMON_CPPFLAGS += -g
COMMON_CPPFLAGS += -Wall
COMMON_CPPFLAGS += -Wextra
#COMMON_CPPFLAGS += -Weffc++
COMMON_CPPFLAGS += -Wshadow
COMMON_CPPFLAGS += -Wabi
COMMON_CPPFLAGS += -Winline
COMMON_CPPFLAGS += -Wmissing-declarations
COMMON_CPPFLAGS += -Wmissing-format-attribute
COMMON_CPPFLAGS += -Woverloaded-virtual
COMMON_CPPFLAGS += -Wpacked
COMMON_CPPFLAGS += -Wredundant-decls
COMMON_CPPFLAGS += -Wsign-promo
COMMON_CPPFLAGS += -Wstack-protector -fstack-protector
COMMON_CPPFLAGS += -Wswitch-default
COMMON_CPPFLAGS += -Wfloat-equal
COMMON_CPPFLAGS += -Wcast-qual
COMMON_CPPFLAGS += -Wconversion

problem_4_CPPFLAGS  = ${COMMON_CPPFLAGS}

TEST_CPPFLAGS  = -I.
TEST_CPPFLAGS += -I./test
TEST_CPPFLAGS += -I./test/calls
TEST_CPPFLAGS += -I./test/rules

problem_4_test_CPPFLAGS  = ${COMMON_CPPFLAGS}
problem_4_test_CPPFLAGS += ${TEST_CPPFLAGS}


###############################################################################
# Linking Flags
###############################################################################

problem_4_test_LDFLAGS  = -L. -lcpptest