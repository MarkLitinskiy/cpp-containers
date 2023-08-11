CC = gcc -std=c++17 -g
FLAGS = -Wall -Werror -Wextra
OS = $(shell uname)
LIBSOURCES = s21_vector.cc tests_vector.cc
ARRAYSOURCES = s21_array.cc tests_array.cc

ifeq ($(OS), Linux)
	CHECKFLAGS=-lgtest -lgtest_main -lrt -lm -lstdc++ -pthread -fprofile-arcs -ftest-coverage
else
	CHECKFLAGS=-lgtest -lgtest_main -lm -lpthread -fprofile-arcs -ftest-coverage -lstdc++
endif

all: test

test_vector:
	$(CC) $(FLAGS) $(LIBSOURCES) -o run $(CHECKFLAGS) -lgcov --coverage
	./run

test_array:
	$(CC) $(FLAGS) $(ARRAYSOURCES) -o run $(CHECKFLAGS) -lgcov --coverage
	./run

valgrind: test
	 CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./run
	 make clean

clean:
	rm -rf report \
	lib_s21_matrix_oop.a \
	report.info \
	*.gcda \
	*.gcno \
	s21_matrix_oop.o \
	run.dSYM \
	run

