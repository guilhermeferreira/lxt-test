#!/bin/sh

. ${PWD}/../cpptest_build.conf

TOOL=""
if test "$1" = "DYN_ANALYSIS"; then
	TOOL+="valgrind --leak-check=full"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $TOOL ./problem_1_test

if test "$1" = "FUZZ_TEST"; then
	COUNTER=0
	while [  $COUNTER -lt 10 ]; do
		blab -e '[a-z]{5} " " [a-z]{5}' | xargs ./problem_1
		let COUNTER=COUNTER+1
	done
else
	# Success
	$TOOL ./problem_1 helloworld elloworldh
	$TOOL ./problem_1 helloworld lloworldhe
	$TOOL ./problem_1 helloworld loworldhel
	$TOOL ./problem_1 helloworld oworldhell
	$TOOL ./problem_1 helloworld worldhello

	# Failure
	$TOOL ./problem_1 helloworld alloworldh
	$TOOL ./problem_1 helloworld llowurldhe
	$TOOL ./problem_1 helloworld loworfdhel
	$TOOL ./problem_1 helloworld owcrldhell
	$TOOL ./problem_1 helloworld worldhillo
	$TOOL ./problem_1 hello      helol
fi
