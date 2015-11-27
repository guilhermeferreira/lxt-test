#!/bin/sh

LD_LIBRARY_PATH=. ./problem_4_test

$DEBUGGER ./problem_4 sample/rules-assignments.c3l sample/calls1.rec
$DEBUGGER ./problem_4 sample/rules-arithmetic_operations.c3l sample/calls1.rec
$DEBUGGER ./problem_4 sample/rules-conditional_assignment.c3l sample/calls1.rec
$DEBUGGER ./problem_4 sample/rules-problem_4.c3l sample/calls1.rec
