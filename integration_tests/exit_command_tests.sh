#!/bin/sh

INPUTS=("echo not exit" "echo still not exit" "echo almost exit" "exit")

for input in "${INPUTS[@]}"
do
	echo "executing .././rshell ${input}"
	.././rshell ${input}
done


