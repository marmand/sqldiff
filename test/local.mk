check_PROGRAMS = hello
hello_SOURCES =  \
%reldir%/hello.cc

hello_LDFLAGS = libsqldiff.la ${GTEST_LIBS}
hello_CXXFLAGS = -I${srcdir}/include ${PTHREAD_CFLAGS}

TESTS = $(check_PROGRAMS)
