#!/bin/bash
cp -f in.txt src/
cd src
rm *.o
gcc main.c -o main
./main
cd ..
gcc test.c -o test
./test $1