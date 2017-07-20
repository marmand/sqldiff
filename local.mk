lib_LTLIBRARIES += libsqldiff.la
sqldiffdir = ${includedir}/sqldiff
sqldiff_HEADERS = %reldir%/include/sqldiff.hh
libsqldiff_la_SOURCES = %reldir%/src/sqldiff.cc
libsqldiff_la_LDFLAGS = -version-info 0:0:0

include %reldir%/test/local.mk
