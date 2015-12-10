#!/bin/sh

. ${PWD}/../cpptest_build.conf

DEBUGGER=""
if test "$1" = "DEBUG"; then
	DEBUGGER+="valgrind --leak-check=full"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $DEBUGGER ./problem_1_test

# Success
$DEBUGGER ./problem_1 helloworld elloworldh
$DEBUGGER ./problem_1 helloworld lloworldhe
$DEBUGGER ./problem_1 helloworld loworldhel
$DEBUGGER ./problem_1 helloworld oworldhell
$DEBUGGER ./problem_1 helloworld worldhello

# Failure
$DEBUGGER ./problem_1 helloworld alloworldh
$DEBUGGER ./problem_1 helloworld llowurldhe
$DEBUGGER ./problem_1 helloworld loworfdhel
$DEBUGGER ./problem_1 helloworld owcrldhell
$DEBUGGER ./problem_1 helloworld worldhillo
$DEBUGGER ./problem_1 hello      helol
