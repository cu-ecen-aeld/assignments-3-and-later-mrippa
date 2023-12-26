#!/bin/bash

filesdir=$1
searchstr=$2

if [ $# -lt 2 ]
then
    echo "Error. Usage: finder.sh <filesdir> <searchstring> "
    exit 1
elif [ ! -d $filesdir ] 
then 
    echo "Error: Direcrory does not exist."
    exit 1
else 

    X=$( find `readlink -f $filesdir` -type f | wc -l )
    Y=$( grep -r $searchstr $filesdir | wc -l )
    echo "The number of files are $X and the number of matching lines are $Y"
    exit 0
fi