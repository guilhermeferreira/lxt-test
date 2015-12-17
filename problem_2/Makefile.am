bin_PROGRAMS = problem_2
bin_PROGRAMS += problem_2_test

problem_2_SOURCES  = src/main.cpp
problem_2_SOURCES += src/missing_letters.cpp

problem_2_test_SOURCES  = test/main.cpp
problem_2_test_SOURCES += test/missing_letters_test.cpp
problem_2_test_SOURCES += src/missing_letters.cpp

problem_2_CPPFLAGS  = -I./src
problem_2_CPPFLAGS += -Wall
problem_2_CPPFLAGS += -Wextra
problem_2_CPPFLAGS += -Weffc++
problem_2_CPPFLAGS += -Wshadow
problem_2_CPPFLAGS += -Wabi
problem_2_CPPFLAGS += -Winline
problem_2_CPPFLAGS += -Wmissing-declarations
problem_2_CPPFLAGS += -Wmissing-format-attribute
problem_2_CPPFLAGS += -Woverloaded-virtual
problem_2_CPPFLAGS += -Wpacked
problem_2_CPPFLAGS += -Wredundant-decls
problem_2_CPPFLAGS += -Wsign-promo
problem_2_CPPFLAGS += -Wstack-protector -fstack-protector
problem_2_CPPFLAGS += -Wswitch-default
problem_2_CPPFLAGS += -Wfloat-equal
problem_2_CPPFLAGS += -Wcast-qual
problem_2_CPPFLAGS += -Wconversion

problem_2_test_CPPFLAGS  = ${problem_2_CPPFLAGS}
problem_2_test_CPPFLAGS += -I./test
problem_2_test_CPPFLAGS += -I../cpptest-install/inc

###############################################################################
# Linking Flags
###############################################################################

problem_2_test_LDADD = -L../cpptest-install/lib -lcpptest