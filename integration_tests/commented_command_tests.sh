#!/bin/sh

INPUTS=("echo hello #world" "echo hello world" "exit")

for input in "${INPUTS[@]}"
do
	echo "executing .././rshell ${input}"
	.././rshell ${input}
done
