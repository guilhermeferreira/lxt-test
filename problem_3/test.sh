#!/bin/sh

. ${PWD}/../cpptest_build.conf

DEBUGGER=""
if test "$1" = "DEBUG"; then
	DEBUGGER+="valgrind --leak-check=full"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $DEBUGGER ./problem_3_test

$DEBUGGER ./problem_3 "..R...." 2
$DEBUGGER ./problem_3 "RR..LRL" 3
$DEBUGGER ./problem_3 "LRLR.LRLR" 2
$DEBUGGER ./problem_3 "RLRLRLRLRL" 10
$DEBUGGER ./problem_3 "..." 1
$DEBUGGER ./problem_3 "LRRL.LR.LRR.R.LRRL." 1
