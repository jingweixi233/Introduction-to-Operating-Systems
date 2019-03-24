#!/bin/bash

mystr="name.email phone.address.remarks"

IFS='.'" "

for word in ${mystr[@]}; do
    echo $word
done

IFS=" "