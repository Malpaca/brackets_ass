CC = gcc
CFLAGS = -Wall -std=c99

all: test_stack check_brackets

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

test_stack: stack.o  test_stack.c
	$(CC) $(CFLAGS) -o test_stack stack.o test_stack.c

check_brackets: stack.o check_brackets.c
	$(CC) $(CFLAGS) -o check_brackets stack.o check_brackets.c

clean:
	rm stack.o test_stack check_brackets
