#!/bin/sh

INPUTS=("echo first" "echo second" "echo third" "git status" "ls")

for input in "${INPUTS[@]}"
do
        echo "executing .././rshell ${input}"
        .././rshell ${input}
done
