#!/bin/sh

DEBUGGER=""
if [ "$1" == "DEBUG" ]; then
	DEBUGGER+="valgrind --leak-check=full"
fi

# Success
$DEBUGGER ./problem_1 helloworld elloworldh
$DEBUGGER ./problem_1 helloworld lloworldhe
$DEBUGGER ./problem_1 helloworld loworldhel
$DEBUGGER ./problem_1 helloworld oworldhell
$DEBUGGER ./problem_1 helloworld worldhello

# Failure
$DEBUGGER ./problem_1 helloworld alloworldh
$DEBUGGER ./problem_1 helloworld llowurldhe
$DEBUGGER ./problem_1 helloworld loworfdhel
$DEBUGGER ./problem_1 helloworld owcrldhell
$DEBUGGER ./problem_1 helloworld worldhillo
