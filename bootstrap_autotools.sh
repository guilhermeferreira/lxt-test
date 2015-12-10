#!/bin/sh

./cpptest_build.sh

aclocal
libtoolize --automake
automake --add-missing
autoconf

