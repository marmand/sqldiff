check_PROGRAMS = hello
hello_SOURCES = %reldir%/hello.cc
hello_LDFLAGS = ${GTEST_LIBS}
hello_CXXFLAGS = ${PTHREAD_CFLAGS}

TESTS = $(check_PROGRAMS)
