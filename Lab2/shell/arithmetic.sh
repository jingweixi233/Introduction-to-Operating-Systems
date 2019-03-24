#!/bin/bash
## + - * / ++ --
##To summarize,$(())works whenAis either a number or an arithmetic expression, while${}works only whenAis a number.
a=2
b=3+2

mysum=$((b))
echo ${mysum}