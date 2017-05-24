#!/bin/sh
#stamp.sh


echo "time started: $(date +"%H %M %S")" 

make Prog

./a.out $1 $2 $3

echo "\ntime ended: $(date +"%H %M %S")"
