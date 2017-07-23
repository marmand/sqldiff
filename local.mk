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
%reldir%/src/table.hh

libsqldiff_la_LDFLAGS = -version-info 0:0:0
libsqldiff_la_CXXFLAGS = -I${top_srcdir}/include/

include %reldir%/test/local.mk
