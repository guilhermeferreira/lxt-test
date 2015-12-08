bin_PROGRAMS = problem_1
bin_PROGRAMS += problem_1_test

problem_1_SOURCES  = src/main.cpp
problem_1_SOURCES += src/rotation.cpp

problem_1_test_SOURCES  = test/main.cpp
problem_1_test_SOURCES += src/rotation.cpp

problem_1_CPPFLAGS  = -I./src
problem_1_CPPFLAGS += -Wall
problem_1_CPPFLAGS += -Wextra
problem_1_CPPFLAGS += -Weffc++
problem_1_CPPFLAGS += -Wshadow
problem_1_CPPFLAGS += -Wabi
problem_1_CPPFLAGS += -Winline
problem_1_CPPFLAGS += -Wmissing-declarations
problem_1_CPPFLAGS += -Wmissing-format-attribute
problem_1_CPPFLAGS += -Woverloaded-virtual
problem_1_CPPFLAGS += -Wpacked
problem_1_CPPFLAGS += -Wredundant-decls
problem_1_CPPFLAGS += -Wsign-promo
problem_1_CPPFLAGS += -Wstack-protector -fstack-protector
problem_1_CPPFLAGS += -Wswitch-default
problem_1_CPPFLAGS += -Wfloat-equal
problem_1_CPPFLAGS += -Wcast-qual
problem_1_CPPFLAGS += -Wconversion

problem_1_test_CPPFLAGS  = ${problem_1_CPPFLAGS}
problem_1_test_CPPFLAGS += -I../cpptest-install/inc

###############################################################################
# Linking Flags
###############################################################################

problem_1_test_LDADD = -L../cpptest-install/lib -lcpptest