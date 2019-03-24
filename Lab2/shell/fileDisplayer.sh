#!/bin/bash

#The script prints the file specified as the first input argument, e.g. to printforloop.sh,

#$ ./file_displayer.sh forloop.sh

#Except that trailing spaces are trimmed, e.g. indentations beforeechoandexit(you may compare the output against that from$ cat forloop.shto see the difference).

#Thewhile-loop evaluatesread line, with content read (operator<) from the file named in$f. Note that if we omit both the redirection operator (<) and file name,readwill read input from standard input stream (stdin) instead.

if [ $# -lt 1 ]; then
    echo "$0 [file to display]"
    exit 1
fi

if [ ! -f $1 ]; then
    echo "Cannot display non-regular files"
    exit 1
fi

while read line; do
    echo "${line}"
done < $1