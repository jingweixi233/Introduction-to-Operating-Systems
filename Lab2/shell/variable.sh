#!/bin/bash
## Don't use "space" to between "=", it will complier it as command

mynum=3150
course_code="csci"
mystr=${course_code}

echo "before: ${mystr}"
mystr+=${mynum}
echo "After: ${mystr}"

echo "${course_code}3150 is a course of OSprogramming"

