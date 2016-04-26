include ../cpptest_build.conf

bin_PROGRAMS = problem_1
bin_PROGRAMS += problem_1_test

problem_1_SOURCES  = src/main.cpp
problem_1_SOURCES += src/rotation.cpp

problem_1_test_SOURCES  = test/main.cpp
problem_1_test_SOURCES += test/rotation_test.cpp
problem_1_test_SOURCES += src/rotation.cpp

problem_1_CXXFLAGS  = -I./src
problem_1_CXXFLAGS += -Wall
problem_1_CXXFLAGS += -Wextra
problem_1_CXXFLAGS += -Weffc++
problem_1_CXXFLAGS += -Wshadow
problem_1_CXXFLAGS += -Wabi
problem_1_CXXFLAGS += -Winline
problem_1_CXXFLAGS += -Wmissing-declarations
problem_1_CXXFLAGS += -Wmissing-format-attribute
problem_1_CXXFLAGS += -Woverloaded-virtual
problem_1_CXXFLAGS += -Wpacked
problem_1_CXXFLAGS += -Wredundant-decls
problem_1_CXXFLAGS += -Wsign-promo
problem_1_CXXFLAGS += -Wstack-protector -fstack-protector
problem_1_CXXFLAGS += -Wswitch-default
problem_1_CXXFLAGS += -Wfloat-equal
problem_1_CXXFLAGS += -Wcast-qual
problem_1_CXXFLAGS += -Wconversion

problem_1_test_CXXFLAGS  = ${problem_1_CXXFLAGS}
problem_1_test_CXXFLAGS += -I./test
problem_1_test_CXXFLAGS += -I../${CPPTEST_INC_DIR}
problem_1_test_CXXFLAGS += -O0
problem_1_test_CXXFLAGS += -fprofile-arcs
problem_1_test_CXXFLAGS += -ftest-coverage

###############################################################################
# Linking Flags
###############################################################################

problem_1_test_LDADD = -L../${CPPTEST_LIB_DIR} -lcpptest
problem_1_test_LDADD += -lgcov
