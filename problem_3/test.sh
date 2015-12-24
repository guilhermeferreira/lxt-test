#!/bin/sh

TOOL=""
if test "$1" = "DYN_ANALYSIS"; then
	TOOL+="valgrind --leak-check=full"
fi

$TOOL ./problem_3 "..R...." 2
$TOOL ./problem_3 "RR..LRL" 3
$TOOL ./problem_3 "LRLR.LRLR" 2
$TOOL ./problem_3 "RLRLRLRLRL" 10
$TOOL ./problem_3 "..." 1
$TOOL ./problem_3 "LRRL.LR.LRR.R.LRRL." 1
