#!/bin/sh

. ${PWD}/cpptest_build.conf

BASE_DIR=${PWD}
SOURCE_DIR=${BASE_DIR}/${CPPTEST_SOURCE_DIR}
BUILD_DIR=${BASE_DIR}/${CPPTEST_BUILD_DIR}
INC_DIR=${BASE_DIR}/${CPPTEST_INC_DIR}
LIB_DIR=${BASE_DIR}/${CPPTEST_LIB_DIR}

# Initialize the submodule
git submodule init
git submodule update

mkdir ${BUILD_DIR}

cd ${SOURCE_DIR}

# Note: call cpptest/autogen.sh from bash, otherwise it might be executed
#       by dash or another shell that doesn't support conditional tests.
#       Which may end up using "glibtoolize" instead of "libtoolize"

# Build the submodule
bash ./autogen.sh
./configure --libdir=${LIB_DIR} --includedir=${INC_DIR}
make
make install

# Remove building artifacts in order to leave the submodule clean
git clean -fd .

cd -
