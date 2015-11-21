#!/bin/sh

DEBUGGER=""
if [ "$1" == "DEBUG" ]; then
	DEBUGGER+="valgrind --leak-check=full"
fi

$DEBUGGER ./problem_3 "..R...." 2
$DEBUGGER ./problem_3 "RR..LRL" 3
$DEBUGGER ./problem_3 "LRLR.LRLR" 2
$DEBUGGER ./problem_3 "RLRLRLRLRL" 10
$DEBUGGER ./problem_3 "..." 1
$DEBUGGER ./problem_3 "LRRL.LR.LRR.R.LRRL." 1
