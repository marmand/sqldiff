AM_LDFLAGS = ${GTEST_LDFLAGS}
AM_CXXFLAGS = ${GTEST_CXXFLAGS} ${PTHREAD_CFLAGS}
AM_CPPFLAGS = -I${top_srcdir}/include -I${top_srcdir}/src ${GTEST_CPPFLAGS}
LDADD = libsqldiff.la ${GTEST_LIBS}

AM_DEFAULT_SOURCE_EXT = .cc

check_PROGRAMS += %reldir%/construct
check_PROGRAMS += %reldir%/create
check_PROGRAMS += %reldir%/grammar
check_PROGRAMS += %reldir%/distance

TESTS += $(check_PROGRAMS)
