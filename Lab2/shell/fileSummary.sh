#!/bin/bash

for f in "$@"; do
    counter=0
    wc -l ${f}
    while read line; do
        ((counter ++ ))
        chars=$(echo -n ${line} | wc -c)
        words=$(echo -n ${line} | wc -w)
        echo "chars = ${chars} and words = ${words}"
    done < ${f}
done