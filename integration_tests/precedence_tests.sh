#!/bin/sh

INPUTS=("(echo hello && echas world) || echo bye" "echo hello world || (echo goodbye || echo world)")

for input in "${INPUTS[@]}"
do
        echo "executing .././rshell ${input}"
        .././rshell ${input}
done
