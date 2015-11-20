bin_PROGRAMS  = problem_4
bin_PROGRAMS += problem_4_test

problem_4_SOURCES  = src/main.cpp
problem_4_SOURCES += src/rules.cpp

problem_4_test_SOURCES  = ${problem_4_SOURCES}
problem_4_test_SOURCES += test/rules_test.cpp

problem_4_CPPFLAGS  = -I.
problem_4_CPPFLAGS += -I./src
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