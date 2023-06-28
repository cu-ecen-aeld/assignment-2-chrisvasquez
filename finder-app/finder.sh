#!/bin/sh

display_error () {
  echo "ERROR: Invalid number of arguments."
  echo "Total number of arguments should be 2."
  echo "The order of the arguments should be:"
  echo "  1) File Directory or Path."
  echo "  2) String to be searched in the specified directory path."
}

if [ "$#" -eq 2 ]; then
  if [ -d "$1" ]; then
    numFiles=`find $1 -type f | wc -l`
    numLines=`grep -r -o -s $2 $1 | wc -l`
    echo "The number of files are $numFiles and the number of matching lines are $numLines"
    exit 0
  else
    display_error
    exit 1
  fi
  exit 0
else
  display_error
  exit 1
fi