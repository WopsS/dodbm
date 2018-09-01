#!/bin/sh
for f in $1/*-tests; do
    echo $(basename $f)
    $f

    error_code="$?"
    if [ $error_code -ne 0 ]; then
        exit $error_code
    fi
done