AM_LDFLAGS = ${GTEST_LIBS}
AM_CXXFLAGS = -I${top_srcdir}/include -I${top_srcdir}/src ${PTHREAD_CFLAGS}
LDADD = libsqldiff.la

check_PROGRAMS =        \
construct               \
create                  \
distance                \
grammar

construct_SOURCES       = %reldir%/construct.cc
create_SOURCES          = %reldir%/create.cc
grammar_SOURCES         = %reldir%/grammar.cc
distance_SOURCES        = %reldir%/distance.cc

TESTS = $(check_PROGRAMS)
