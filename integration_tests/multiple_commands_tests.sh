#!/bin/sh

INPUTS=("echo first" "ls -a" "echo third")

for input in "${INPUTS[@]}"
do
        echo "executing .././rshell ${input}"
        .././rshell ${input}
done
