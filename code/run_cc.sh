#!/bin/bash
# compile a c++ file, run it, and then remove the executable

filename=$1
output=`echo $filename | sed 's/\.cc$//'`
g++ $filename -o $output -Wall -std=c++11
./$output
rm $output

