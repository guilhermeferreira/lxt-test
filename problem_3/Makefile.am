include ../cpptest_build.conf

bin_PROGRAMS = problem_3
bin_PROGRAMS += problem_3_test

problem_3_SOURCES  = src/main.cpp
problem_3_SOURCES += src/chamber.cpp
problem_3_SOURCES += src/linearchamber.cpp
problem_3_SOURCES += src/particle.cpp

problem_3_test_SOURCES  = test/main.cpp
problem_3_test_SOURCES += test/linearchamber_test.cpp
problem_3_test_SOURCES += test/particle_test.cpp
problem_3_test_SOURCES += src/chamber.cpp
problem_3_test_SOURCES += src/linearchamber.cpp
problem_3_test_SOURCES += src/particle.cpp

problem_3_CXXFLAGS  = -I./src
problem_3_CXXFLAGS += -Wall
problem_3_CXXFLAGS += -Wextra
problem_3_CXXFLAGS += -Weffc++
problem_3_CXXFLAGS += -Wshadow
problem_3_CXXFLAGS += -Wabi
problem_3_CXXFLAGS += -Winline
problem_3_CXXFLAGS += -Wmissing-declarations
problem_3_CXXFLAGS += -Wmissing-format-attribute
problem_3_CXXFLAGS += -Woverloaded-virtual
problem_3_CXXFLAGS += -Wpacked
problem_3_CXXFLAGS += -Wredundant-decls
problem_3_CXXFLAGS += -Wsign-promo
problem_3_CXXFLAGS += -Wstack-protector -fstack-protector
problem_3_CXXFLAGS += -Wswitch-default
problem_3_CXXFLAGS += -Wfloat-equal
problem_3_CXXFLAGS += -Wcast-qual
problem_3_CXXFLAGS += -Wconversion

problem_3_test_CXXFLAGS  = ${problem_3_CXXFLAGS}
problem_3_test_CXXFLAGS += -I./test
problem_3_test_CXXFLAGS += -I../${CPPTEST_INC_DIR}
problem_3_test_CXXFLAGS += -O0
problem_3_test_CXXFLAGS += -fprofile-arcs
problem_3_test_CXXFLAGS += -ftest-coverage

###############################################################################
# Linking Flags
###############################################################################

problem_3_test_LDADD = -L../${CPPTEST_LIB_DIR} -lcpptest
problem_3_test_LDADD += -lgcov
