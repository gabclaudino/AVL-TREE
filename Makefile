all: avl.o
	gcc avl.o main.c -o myavl

avl.o: avl.h
	gcc -c avl.c

