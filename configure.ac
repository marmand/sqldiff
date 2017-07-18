#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([SQLDiff], [0.0.1], [armand@leclercq.site])
AC_CONFIG_SRCDIR([src/sqldiff.cc])
AC_CONFIG_HEADERS([config.hh])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror subdir-objects])
AM_SILENT_RULES([yes])

# Checks for programs.
AC_PROG_CXX
AM_PROG_AR

# Create Libraries
LT_PREREQ([2.4.2])
LT_INIT()

# Checks for libraries.
AX_BOOST_BASE([1.55])
AX_BOOST_PROGRAM_OPTIONS

# Checks for header files.
AC_LANG_PUSH([C++])
AC_CHECK_HEADER([gtest/gtest.h],
                [AC_DEFINE([HAVE_GTEST], [1], [Define to 1 if you have <gtest/gtest.h>.])],
                [AC_MSG_ERROR([Missing gtest.h, install google test library])])
AC_LANG_POP([C++])

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11([noext])
AX_APPEND_COMPILE_FLAGS([-Wall],              [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Werror],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic],          [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic-errors],   [CXXFLAGS])

# Checks for library functions.

AC_OUTPUT
