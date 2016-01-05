#!/bin/sh

. ${PWD}/../cpptest_build.conf

TOOL=""
if test "$1" = "DYN_ANALYSIS"; then
	TOOL+="valgrind --leak-check=full"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $DEBUGGER ./problem_3_test

if test "$1" = "FUZZ_TEST"; then
	COUNTER=0
	while [  $COUNTER -lt 10 ]; do
		blab -e '[LR.]{24} " " [1-9]{1}' | xargs ./problem_3
		let COUNTER=COUNTER+1
	done
else
	$TOOL ./problem_3 "..R...." 2
	$TOOL ./problem_3 "RR..LRL" 3
	$TOOL ./problem_3 "LRLR.LRLR" 2
	$TOOL ./problem_3 "RLRLRLRLRL" 10
	$TOOL ./problem_3 "..." 1
	$TOOL ./problem_3 "LRRL.LR.LRR.R.LRRL." 1
fi
