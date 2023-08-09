CC = gcc -std=c++17 -g
FLAGS = -Wall -Werror -Wextra
OS = $(shell uname)
LIBSOURCES = s21_vector.cc tests.cc

ifeq ($(OS), Linux)
	CHECKFLAGS=-lgtest -lgtest_main -lrt -lm -lstdc++ -pthread -fprofile-arcs -ftest-coverage
else
	CHECKFLAGS=-lgtest -lgtest_main -lm -lpthread -fprofile-arcs -ftest-coverage -lstdc++
endif

all: test

test:
	$(CC) $(FLAGS) $(LIBSOURCES) -o run $(CHECKFLAGS) -lgcov --coverage
	./run
