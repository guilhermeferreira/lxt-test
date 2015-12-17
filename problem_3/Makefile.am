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

problem_3_CPPFLAGS  = -I./src
problem_3_CPPFLAGS += -Wall
problem_3_CPPFLAGS += -Wextra
problem_3_CPPFLAGS += -Weffc++
problem_3_CPPFLAGS += -Wshadow
problem_3_CPPFLAGS += -Wabi
problem_3_CPPFLAGS += -Winline
problem_3_CPPFLAGS += -Wmissing-declarations
problem_3_CPPFLAGS += -Wmissing-format-attribute
problem_3_CPPFLAGS += -Woverloaded-virtual
problem_3_CPPFLAGS += -Wpacked
problem_3_CPPFLAGS += -Wredundant-decls
problem_3_CPPFLAGS += -Wsign-promo
problem_3_CPPFLAGS += -Wstack-protector -fstack-protector
problem_3_CPPFLAGS += -Wswitch-default
problem_3_CPPFLAGS += -Wfloat-equal
problem_3_CPPFLAGS += -Wcast-qual
problem_3_CPPFLAGS += -Wconversion

problem_3_test_CPPFLAGS  = ${problem_3_CPPFLAGS}
problem_3_test_CPPFLAGS += -I./test
problem_3_test_CPPFLAGS += -I../${CPPTEST_INC_DIR}

###############################################################################
# Linking Flags
###############################################################################

problem_3_test_LDADD = -L../${CPPTEST_LIB_DIR} -lcpptest
