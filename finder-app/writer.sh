#!/bin/bash

writefile=$1
writestr=$2

directory=$(dirname $writefile)

if [ $# -lt 2 ]
then
    echo "Error. Usage: writer.sh <writefile> <writestr> "
    exit 1
fi

if [ ! -d $directory ]
then
    mkdir -p $directory
fi

echo $writestr > $writefile

if [ ! -e $writefile ]
then 
    echo "Error: writefile.sh could not make file >>>$writefile<<< ."
    exit 1
fi
exit 0
