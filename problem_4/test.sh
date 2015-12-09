#!/bin/sh

DEBUGGER=""
if test "$1" = "DEBUG"; then
	DEBUGGER+="valgrind --tool=memcheck --leak-check=full --track-origins=yes"
fi

LD_LIBRARY_PATH=../cpptest-install/lib $DEBUGGER ./problem_4_test

echo ""
echo "---------------------------------------";
echo ""

$DEBUGGER ./problem_4 sample/rules-assignments.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$DEBUGGER ./problem_4 sample/rules-arithmetic_operations.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$DEBUGGER ./problem_4 sample/rules-conditional_assignment.c3l sample/calls1.rec

echo ""
echo "---------------------------------------";
echo ""

$DEBUGGER ./problem_4 sample/rules-problem_4.c3l sample/calls1.rec
