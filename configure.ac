AC_INIT(luxoft-test, 1.0, guilherme.maciel.ferreira@gmail.com)
AM_INIT_AUTOMAKE(foreign -Wall subdir-objects)

AC_LANG_CPLUSPLUS
AC_PROG_CXX
AM_PROG_CC_C_O
AC_PROG_RANLIB

AC_SEARCH_LIBS([main], [stdc++], , AC_MSG_ERROR([missing libstdc++]))
AC_CHECK_HEADER([iostream], , AC_MSG_ERROR([missing STL iostream header]))
AC_CHECK_HEADER([algorithm], , AC_MSG_ERROR([missing STL algorithm header]))
AC_CHECK_HEADER([map], , AC_MSG_ERROR([missing STL map header]))
AC_CHECK_HEADER([memory], , AC_MSG_ERROR([missing STL memory header]))
AC_CHECK_HEADER([string], , AC_MSG_ERROR([missing STL string header]))
AC_CHECK_HEADER([vector], , AC_MSG_ERROR([missing STL vector header]))

AC_CHECK_HEADER([assert.h], , AC_MSG_ERROR([missing assert.h header]))
AC_CHECK_HEADER([stdlib.h], , AC_MSG_ERROR([missing stdlib.h header]))
AC_CHECK_HEADER([dlfcn.h], , AC_MSG_ERROR([missing dlfcn.h header]))

AC_CONFIG_FILES(\
	Makefile \
	problem_1/Makefile \
	problem_2/Makefile \
	problem_3/Makefile \
	problem_4/Makefile \
)

AC_OUTPUT
