# Name: Sarah Depew

all: check_ptrs

check_ptrs: pointers.o check_ptrs.o
	gcc -o check_ptrs pointers.o check_ptrs.o -lcheck

pointers.o: pointers.c pointers.h
	gcc -c pointers.c

check_ptrs.o: check_ptrs.c pointers.h
	gcc -c check_ptrs.c
