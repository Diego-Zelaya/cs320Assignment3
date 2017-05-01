#!/bin/sh

set -e

if [ -f prog3_1 ]; then
    rm prog3_1
fi

g++ prog3_1.cpp -g -o0 -o prog3_1 -I lua-5.3.4/src -L lua-5.3.4/src -l lua -l m -l dl
