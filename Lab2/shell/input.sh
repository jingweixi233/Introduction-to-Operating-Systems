#!/bin/bash

##The input arguments are obtainable from$@.

##The number of arguments is obtainable from$#.

##To specify the n-th argument, use$n, e.g. first argument is$1.$0is a special argument that stores the name of the script. For example, this script (argument.sh) prints the arguments to the script.

echo "You called $0, with"

if [ $# -eq 0 ]; then
    echo "No arguments ..."
    exit 0
fi

counter=0

for i in "$@"; do
    ((counter++))
    echo "Arg[${counter}] = ${i}"
done