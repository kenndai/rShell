#!/bin/sh

INPUTS=("echo first" "ls -a" "echo third")

for input in "{INPUTS[@]}"
do
        echo ".././rshell ${input}"
        output=$(.././rshell ${input})
        if [  "${output}" = "${input}" ]
        then
                echo "Test passed"
        else
                echo "Test failed"
        fi
done
