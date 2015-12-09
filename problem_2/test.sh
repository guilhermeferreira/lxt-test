#!/bin/sh

DEBUGGER=""
if test "$1" = "DEBUG"; then
	DEBUGGER+="valgrind --leak-check=full"
fi

# Pangrams
$DEBUGGER ./problem_2 "A quick brown fox jumps over the lazy dog"
$DEBUGGER ./problem_2 "Pack my box with five dozen liquor jugs."
$DEBUGGER ./problem_2 "Despite having an excellent breakfast, Jacques was amazingly slow."

# Not pangrams
$DEBUGGER ./problem_2 "This sentence contains A-Z but not the whole alphabet."
$DEBUGGER ./problem_2 "Guadalajara seems to be a very promising place to work."
$DEBUGGER ./problem_2 "I can speak bit of german. Ich moechte ein Brezel bitte. Ich mag das"
