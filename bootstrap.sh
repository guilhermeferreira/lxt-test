#!/bin/sh

aclocal
libtoolize --automake
automake --add-missing
autoconf

./cpptest_install.sh
