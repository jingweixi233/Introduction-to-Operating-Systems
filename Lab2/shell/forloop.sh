##prints 1 to 10 and then 'a' to 'c', with each number or character on a new line.

#!/bin/bash

A=("a" "b" "c")

for i in {1..10}; do
    echo "${i}"
done

for char in ${A[@]}; do
    echo "${char}"
done