#!/bin/sh

BASEDIR=$PWD

PROBLEMS='problem_1 problem_2 problem_3 problem_4'

for problem_x in $PROBLEMS; do
	echo ""
	echo "+-------------------------------------+";
	echo "|                                     |"
	echo "| $problem_x                           |"
	echo "|                                     |"
	echo "+-------------------------------------+";
	echo ""
	cd $BASEDIR/$problem_x && ./test.sh;
	cd $BASEDIR;
done

