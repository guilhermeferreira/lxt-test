#!/bin/sh

INSTALL_DIR=cpptest-install

mkdir $INSTALL_DIR
cd cpptest-1.1.2
./autogen.sh
./configure --libdir=$PWD/../$INSTALL_DIR/lib  --includedir=$PWD/../$INSTALL_DIR/inc
make
make install
cd -
