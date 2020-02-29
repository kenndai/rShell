#!/bin/sh

INPUTS=("test -f ../rshell" "test -d ../rshell" "test -f ../src" "     test -f ../src/CMD.h" "test -f ../src/CMD.cpp")

for input in "${INPUTS[@]}"
do
	echo "executing .././rshell ${input}"
	.././rshell ${input}
done
