#!/bin/sh

display_error () {
  echo "ERROR: Invalid number of arguments."
  echo "Total number of arguments should be 2."
  echo "The order of the arguments should be:"
  echo "  1) File Path."
  echo "  2) String to be written in the specified file path."
}

if [ "$#" -eq 2 ]; then
  dirPath="$(dirname $1)"
  if ! [ -d "$dirPath" ]; then
    mkdir -p $dirPath
  fi
  echo $2 > $1
  if [ $? -eq 0 ]; then
    exit 0
  else
    display_error
    exit 1
  fi
else
  display_error
  exit 1
fi