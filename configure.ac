#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([SQLDiff], [0.0.1], [bugs@phabricator.leclercq.site], [sqldiff], [http://phabricator.leclercq.site])
AC_CONFIG_SRCDIR([src/sqldiff.cc])
AC_CONFIG_HEADERS([config.hh])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.14 foreign -Wall -Werror parallel-tests
                  subdir-objects color-tests
                  dist-bzip2 dist-xz])
AM_SILENT_RULES([yes])

# Checks for programs.
AC_LANG_PUSH([C++])
AC_PROG_CXX
AM_PROG_AR

# Create Libraries
LT_PREREQ([2.4.2])
LT_INIT()

# Checks for libraries.
# Boost
AX_BOOST_BASE([1.55])
AX_BOOST_PROGRAM_OPTIONS

# Gtest
AX_PTHREAD()
AS_TR_SH([gtest_save_CPPFLAGS])="$CPPFLAGS"
AS_TR_SH([gtest_save_CXXFLAGS])="$CXXFLAGS"
AS_TR_SH([gtest_save_LIBS])="$LIBS"
AS_TR_SH([gtest_save_LDFLAGS])="$LDFLAGS"
CPPFLAGS="-I${srcdir}/googletest/googletest/include $CPPFLAGS"
CXXFLAGS="$PTHREAD_CFLAGS $CXXFLAGS"
LIBS="-lgtest_main -lgtest $LIBS"
LDFLAGS="-L${srcdir}/googletest/_build/googlemock -L${srcdir}/googletest/_build/googlemock/gtest $LDFLAGS"
AC_LINK_IFELSE([AC_LANG_SOURCE(
[[
#include <gtest/gtest.h>

TEST(Principal, basic)
{
  ASSERT_TRUE(true);
}
]])]
, [AC_SUBST([GTEST_LIBS], ["-lgtest_main -lgtest"])]dnl
[AC_SUBST([GTEST_LDFLAGS], ["-L${srcdir}/googletest/_build/googlemock -L${srcdir}/googletest/_build/googlemock/gtest"])]
, [AC_MSG_FAILURE([Unable to link with gtest libraries])])
CPPFLAGS=${AS_TR_SH([gtest_save_CPPFLAGS])}
CXXFLAGS=${AS_TR_SH([gtest_save_CXXFLAGS])}
LIBS=${AS_TR_SH([gtest_save_LIBS])}
LDFLAGS=${AS_TR_SH([gtest_save_LDFLAGS])}

# Checks for header files.
AS_TR_SH([gtest_save_CPPFLAGS])="$CPPFLAGS"
CPPFLAGS="-I${srcdir}/googletest/googletest/include $CPPFLAGS"
AC_CHECK_HEADER([gtest/gtest.h],
                [AC_DEFINE([HAVE_GTEST], [1], [Define to 1 if you have <gtest/gtest.h>.])]dnl
                [AC_SUBST([GTEST_CPPFLAGS], ["-I${srcdir}/googletest/googletest/include"])],
                [AC_MSG_ERROR([Missing gtest.h, install google test library])])
CPPFLAGS=${AS_TR_SH([gtest_save_CPPFLAGS])}

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11([noext])
AX_APPEND_COMPILE_FLAGS([-Wall],              [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Werror],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic],          [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic-errors],   [CXXFLAGS])

# Checks for library functions.

AC_OUTPUT
