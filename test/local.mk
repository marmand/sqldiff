check_PROGRAMS = \
construct
construct_SOURCES =  \
%reldir%/construct.cc

construct_LDFLAGS = ${GTEST_LIBS}
construct_CXXFLAGS = -I${top_srcdir}/include ${PTHREAD_CFLAGS}
construct_LDADD = libsqldiff.la

TESTS = $(check_PROGRAMS)
