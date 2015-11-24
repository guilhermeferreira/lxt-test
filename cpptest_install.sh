#!/bin/sh

cd cpptest-1.1.2
./autogen.sh
./configure --libdir=$PWD/../problem_4/  --includedir=$PWD/../problem_4/test
make
make install
cd -
