#!/bin/sh

. ${PWD}/../cpptest_build.conf

TOOL=""
if test "$1" = "DYN_ANALYSIS"; then
	TOOL+="valgrind --leak-check=full"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $TOOL ./problem_2_test

if test "$1" = "FUZZ_TEST"; then
	COUNTER=0
	while [  $COUNTER -lt 10 ]; do
		blab -e '[a-z]{24}' | xargs ./problem_2
		let COUNTER=COUNTER+1
	done
else
	# Pangrams
	$TOOL ./problem_2 "A quick brown fox jumps over the lazy dog"
	$TOOL ./problem_2 "Pack my box with five dozen liquor jugs."
	$TOOL ./problem_2 "Despite having an excellent breakfast, Jacques was amazingly slow."

	# Not pangrams
	$TOOL ./problem_2 "This sentence contains A-Z but not the whole alphabet."
	$TOOL ./problem_2 "Guadalajara seems to be a very promising place to work."
	$TOOL ./problem_2 "I can speak bit of german. Ich moechte ein Brezel bitte. Ich mag das"
fi
