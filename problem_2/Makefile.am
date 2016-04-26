include ../cpptest_build.conf

bin_PROGRAMS = problem_2
bin_PROGRAMS += problem_2_test

problem_2_SOURCES  = src/main.cpp
problem_2_SOURCES += src/missing_letters.cpp

problem_2_test_SOURCES  = test/main.cpp
problem_2_test_SOURCES += test/missing_letters_test.cpp
problem_2_test_SOURCES += src/missing_letters.cpp

problem_2_CXXFLAGS  = -I./src
problem_2_CXXFLAGS += -Wall
problem_2_CXXFLAGS += -Wextra
problem_2_CXXFLAGS += -Weffc++
problem_2_CXXFLAGS += -Wshadow
problem_2_CXXFLAGS += -Wabi
problem_2_CXXFLAGS += -Winline
problem_2_CXXFLAGS += -Wmissing-declarations
problem_2_CXXFLAGS += -Wmissing-format-attribute
problem_2_CXXFLAGS += -Woverloaded-virtual
problem_2_CXXFLAGS += -Wpacked
problem_2_CXXFLAGS += -Wredundant-decls
problem_2_CXXFLAGS += -Wsign-promo
problem_2_CXXFLAGS += -Wstack-protector -fstack-protector
problem_2_CXXFLAGS += -Wswitch-default
problem_2_CXXFLAGS += -Wfloat-equal
problem_2_CXXFLAGS += -Wcast-qual
problem_2_CXXFLAGS += -Wconversion

problem_2_test_CXXFLAGS  = ${problem_2_CXXFLAGS}
problem_2_test_CXXFLAGS += -I./test
problem_2_test_CXXFLAGS += -I../${CPPTEST_INC_DIR}
problem_2_test_CXXFLAGS += -O0
problem_2_test_CXXFLAGS += -fprofile-arcs
problem_2_test_CXXFLAGS += -ftest-coverage

###############################################################################
# Linking Flags
###############################################################################

problem_2_test_LDADD = -L../${CPPTEST_LIB_DIR} -lcpptest
problem_2_test_LDADD += -lgcov
