#!/bin/bash

myarray=("three" 1 "five" 0)

echo "myarray 0 ${myarray[0]}"
echo "myarray 1 ${myarray[1]}"
echo "myarray all  ${myarray[@]}"
echo "myarray number ${#myarray[@]}"
echo "myarray key${!myarray[@]}"



