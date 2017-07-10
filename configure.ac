#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([SQLDiff], [0.0.1], [armand@leclercq.site])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/sqldiff.cc])
AC_CONFIG_HEADERS([config.hh])
AC_CONFIG_FILES([Makefile])

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

# Checks for typedefs, structures, and compiler characteristics.
AX_CXX_COMPILE_STDCXX_11([noext])
AX_APPEND_COMPILE_FLAGS([-Wall],              [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Wextra],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-Werror],            [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic],          [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pedantic-errors],   [CXXFLAGS])

# Checks for library functions.

AC_OUTPUT
