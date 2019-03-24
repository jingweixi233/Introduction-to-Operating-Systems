#!/bin/bash

#split str with -F.. and use it as an array

mystr="name.email.phone.address.remarks"

echo "${mystr}" | awk -F'.' '{print $1" "$3}'

