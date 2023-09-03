CC = gcc -std=c++17 -g -Wall -Werror -Wextra
OS = $(shell uname)

LIST = tests/s21_test_list.cc
MAP = tests/s21_test_map.cc
QUEUE = tests/s21_test_queue.cc
SET = tests/s21_test_set.cc
STACK = tests/s21_test_stack.cc
VECTOR = tests/s21_test_vector.cc
ARRAY = tests/s21_test_array.cc
MULTISET = tests/s21_test_multiset.cc

ifeq ($(OS), Linux)
CHECKFLAGS = -lgtest -lgtest_main -lrt -lm -lstdc++ -pthread 
else
CHECKFLAGS = -lgtest -lgtest_main -lm -lpthread  -lstdc++
endif

all: test clean

build_test:
	$(CC) $(FLAGS) $(MAP) $(SET) $(LIST) $(QUEUE) $(STACK) $(VECTOR) $(ARRAY) $(MULTISET) -o test $(CHECKFLAGS)

test_array:
	$(CC) $(FLAGS) $(ARRAY) -o test_array $(CHECKFLAGS)
	./test_array

test_list:
	$(CC) $(FLAGS) $(LIST) -o test_list $(CHECKFLAGS)
	./test_list

test_map:
	$(CC) $(FLAGS) $(MAP) -o test_map $(CHECKFLAGS)
	./test_map

test_multiset:
	$(CC) $(FLAGS) $(MULTISET) -o test_multiset $(CHECKFLAGS)
	./test_multiset

test_queue:
	$(CC) $(FLAGS) $(QUEUE) -o test_queue $(CHECKFLAGS)
	./test_queue

test_set:
	$(CC) $(FLAGS) $(SET) -o test_set $(CHECKFLAGS)
	./test_set

test_stack:
	$(CC) $(FLAGS) $(STACK) -o test_stack $(CHECKFLAGS)
	./test_stack

test_vector:
	$(CC) $(FLAGS) $(VECTOR) -o test_vector $(CHECKFLAGS)
	./test_vector

test: build_test
	./test

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

docker_check:
	docker build -t "valgrind:1.0" .
	docker run --rm -v $(PWD):/tmp -w /tmp valgrind:1.0

clean:
	rm -rf report \
	lib_s21_matrix_oop.a \
	report.info \
	*.gcda \
	*.gcno \
	s21_matrix_oop.o \
	test.dSYM \
	test \
	test_*
