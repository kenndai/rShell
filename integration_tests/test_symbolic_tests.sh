#!/bin/sh

INPUTS=("[-asd ../header]" "[-e ../src]" "[   -e ../rshell]")

for input in "${INPUTS[@]}"
do
	echo "executing .././rshell ${input}"
	.././rshell ${input}
done
