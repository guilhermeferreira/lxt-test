#!/bin/sh

. ${PWD}/../cpptest_build.conf

TOOL=""
if test "$1" = "DYN_ANALYSIS"; then
	TOOL+="valgrind --tool=memcheck --leak-check=full --track-origins=yes"
fi

LD_LIBRARY_PATH=../${CPPTEST_LIB_DIR} $TOOL ./problem_4_test

echo ""
echo "---------------------------------------";
echo ""

$TOOL ./problem_4 sample/rules-assignments.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$TOOL ./problem_4 sample/rules-arithmetic_operations.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$TOOL ./problem_4 sample/rules-conditional_assignment.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$TOOL ./problem_4 sample/rules-problem_4.c3l sample/calls1.rec

if test "$1" = "COVERAGE"; then
	lcov -d src/rules/ -d src/calls/ --base-directory ./ --capture --output-file coverage.info
	genhtml coverage.info -o ./coverage
	firefox ./coverage/index.html
fi
