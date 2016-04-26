include ../cpptest_build.conf

bin_PROGRAMS  = problem_4
bin_PROGRAMS += problem_4_test

###############################################################################
# Source Code
###############################################################################

COMMON_SOURCES  = src/rules/rules_file.cpp
COMMON_SOURCES += src/rules/rules.cpp
COMMON_SOURCES += src/rules/rule_line.cpp
COMMON_SOURCES += src/rules/statement.cpp
COMMON_SOURCES += src/rules/statement_factory.cpp
COMMON_SOURCES += src/rules/assignment_statement.cpp
COMMON_SOURCES += src/rules/command_statement.cpp
COMMON_SOURCES += src/rules/selection_statement.cpp
COMMON_SOURCES += src/rules/object.cpp
COMMON_SOURCES += src/rules/object_table.cpp
COMMON_SOURCES += src/rules/operation.cpp
COMMON_SOURCES += src/rules/operation_table.cpp
COMMON_SOURCES += src/rules/token.cpp
COMMON_SOURCES += src/rules/expression.cpp
COMMON_SOURCES += src/rules/arithmetic_expression.cpp
COMMON_SOURCES += src/rules/condition_expression.cpp
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

TEST_SOURCES  = test/rules/arithmetic_expression_test.cpp
TEST_SOURCES += test/rules/assignment_statement_test.cpp
TEST_SOURCES += test/rules/rule_line_test.cpp
TEST_SOURCES += test/calls/call_record_test.cpp
TEST_SOURCES += test/calls/call_time_test.cpp

problem_4_test_SOURCES  = test/main.cpp
problem_4_test_SOURCES += ${COMMON_SOURCES}
problem_4_test_SOURCES += ${TEST_SOURCES}


###############################################################################
# Compilation Flags
###############################################################################

COMMON_CXXFLAGS  = -I.
COMMON_CXXFLAGS += -I./src
COMMON_CXXFLAGS += -I./src/calls
COMMON_CXXFLAGS += -I./src/excp
COMMON_CXXFLAGS += -I./src/rules
COMMON_CXXFLAGS += -g
COMMON_CXXFLAGS += -Wall
COMMON_CXXFLAGS += -Wextra
#COMMON_CXXFLAGS += -Weffc++
COMMON_CXXFLAGS += -Wshadow
COMMON_CXXFLAGS += -Wabi
COMMON_CXXFLAGS += -Winline
COMMON_CXXFLAGS += -Wmissing-declarations
COMMON_CXXFLAGS += -Wmissing-format-attribute
COMMON_CXXFLAGS += -Woverloaded-virtual
COMMON_CXXFLAGS += -Wpacked
COMMON_CXXFLAGS += -Wredundant-decls
COMMON_CXXFLAGS += -Wsign-promo
COMMON_CXXFLAGS += -Wstack-protector -fstack-protector
COMMON_CXXFLAGS += -Wswitch-default
COMMON_CXXFLAGS += -Wfloat-equal
COMMON_CXXFLAGS += -Wcast-qual
COMMON_CXXFLAGS += -Wconversion

problem_4_CXXFLAGS  = ${COMMON_CXXFLAGS}

TEST_CXXFLAGS  = -I.
TEST_CXXFLAGS += -I./test
TEST_CXXFLAGS += -I./test/calls
TEST_CXXFLAGS += -I./test/rules
TEST_CXXFLAGS += -I../${CPPTEST_INC_DIR}

problem_4_test_CXXFLAGS  = ${COMMON_CXXFLAGS}
problem_4_test_CXXFLAGS += ${TEST_CXXFLAGS}
problem_4_test_CXXFLAGS += -O0
problem_4_test_CXXFLAGS += -fprofile-arcs
problem_4_test_CXXFLAGS += -ftest-coverage


###############################################################################
# Linking Flags
###############################################################################

problem_4_test_LDADD = -L../${CPPTEST_LIB_DIR} -lcpptest
problem_4_test_LDADD += -lgcov
