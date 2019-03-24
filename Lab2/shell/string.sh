#!/bin/bash

mylongstr="this is a long string"

echo "My string: ${mylongstr}"
echo ""

echo "The length of mystring is ${#mylongstr}"
echo ""

echo "Splitting my string"
for word in ${mylongstr[@]}; do
    echo "${word}"
done
echo ""