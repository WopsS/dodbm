#!/bin/sh
for f in $1/*-tests; do
    echo $(basename $f)
    ./$f
    if [ $? -ne 0 ]; then
        exit $?
    fi
done