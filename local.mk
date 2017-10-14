lib_LTLIBRARIES += libsqldiff.la
sqldiffdir = ${includedir}/sqldiff
sqldiff_HEADERS = %reldir%/include/sqldiff.hh
libsqldiff_la_SOURCES =         \
%reldir%/src/column.hh          \
%reldir%/src/diff.cc            \
%reldir%/src/diff.hh            \
%reldir%/src/sql.hh             \
%reldir%/src/sql_grammar.hh     \
%reldir%/src/sqldiff.cc         \
%reldir%/src/statement.hh       \
%reldir%/src/table.hh           \
%reldir%/src/type.hh            \
%reldir%/src/type.cc            \
%reldir%/src/integer.hh         \
%reldir%/src/integer.cc

libsqldiff_la_LDFLAGS = -version-info 0:0:0
libsqldiff_la_CXXFLAGS = -I${top_srcdir}/include/

bin_PROGRAMS += sqldiff
sqldiff_LDADD = libsqldiff.la
sqldiff_SOURCES =               \
%reldir%/src/sqldiff_main.cc

include %reldir%/test/local.mk
