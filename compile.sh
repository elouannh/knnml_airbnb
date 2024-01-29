#!/bin/bash

SOURCE="main.c"
EXECUTABLE="program"

gcc $SOURCE -o $EXECUTABLE

if [ $? eq 0 ]; then
    echo "Compilation successful."
    ./$EXECUTABLE
else
    echo "Compilation failed."
fi
