# Name: Sarah Depew

all: check_ptrs pointers 

check_ptrs: pointers.o check_ptrs.o
	gcc -o check_ptrs pointers.o check_ptrs.o -lcheck

pointers: pointers.o
	gcc -o pointers pointers.o

pointers.o: pointers.c pointers.h
	gcc -c pointers.c

check_ptrs.o: check_ptrs.c pointers.h
	gcc -c check_ptrs.c
