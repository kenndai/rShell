#!/bin/sh

INPUTS=("echo hello #world" "echo hello world")

for input in "${INPUTS[@]}"
do
	echo "executing ./rshell ${input}"
	.././rshell ${input}
done
