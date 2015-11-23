bin_PROGRAMS  = problem_4
bin_PROGRAMS += problem_4_test

problem_4_SOURCES  = src/main.cpp
problem_4_SOURCES += src/rules/rules_file.cpp
problem_4_SOURCES += src/rules/rules.cpp
problem_4_SOURCES += src/rules/rule_line.cpp
problem_4_SOURCES += src/rules/statement.cpp
problem_4_SOURCES += src/rules/assignment_statement.cpp
problem_4_SOURCES += src/rules/command_statement.cpp
problem_4_SOURCES += src/rules/object.cpp
problem_4_SOURCES += src/rules/object_table.cpp
problem_4_SOURCES += src/rules/operation.cpp
problem_4_SOURCES += src/rules/operation_table.cpp
problem_4_SOURCES += src/rules/token.cpp
problem_4_SOURCES += src/rules/expression.cpp
problem_4_SOURCES += src/rules/addition_operation.cpp
problem_4_SOURCES += src/rules/subtraction_operation.cpp
problem_4_SOURCES += src/rules/multiplication_operation.cpp
problem_4_SOURCES += src/rules/division_operation.cpp

problem_4_test_SOURCES  = ${problem_4_SOURCES}
problem_4_test_SOURCES += test/rules_test.cpp

problem_4_CPPFLAGS  = -I.
problem_4_CPPFLAGS += -I./src
problem_4_CPPFLAGS += -I./src/rules
problem_4_CPPFLAGS += -Wall
problem_4_CPPFLAGS += -Wextra
problem_4_CPPFLAGS += -Weffc++
problem_4_CPPFLAGS += -Wshadow
problem_4_CPPFLAGS += -Wabi
problem_4_CPPFLAGS += -Winline
problem_4_CPPFLAGS += -Wmissing-declarations
problem_4_CPPFLAGS += -Wmissing-format-attribute
problem_4_CPPFLAGS += -Woverloaded-virtual
problem_4_CPPFLAGS += -Wpacked
problem_4_CPPFLAGS += -Wredundant-decls
problem_4_CPPFLAGS += -Wsign-promo
problem_4_CPPFLAGS += -Wstack-protector -fstack-protector
problem_4_CPPFLAGS += -Wswitch-default
problem_4_CPPFLAGS += -Wfloat-equal
problem_4_CPPFLAGS += -Wcast-qual
problem_4_CPPFLAGS += -Wconversion

problem_4_test_CPPFLAGS  = ${problem_4_CPPFLAGS}