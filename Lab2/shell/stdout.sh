#!/bin/bash

# capture stdout

#We may capture and store the output of a command to a variable, e.g. to execute the commandlsand store the result into the variableoutput

#output=$(ls)

#Note that the syntax$(command)means executingcommand(which is different from$((expression))for evaluating arithmetic expressions).

#The exit status of the last executed command is always stored in$?.


output=$(ls)
echo ""
echo "Output of ls: ${output}"

# where is the exit status

echo ""
haha; echo "haha gives $?";

echo ""
echo "Hello world"; echo "echo gives $?"s