CFLAGS  = -pedantic -g -Wall 
aprog : bst.o bstTest.o
	gcc -o aprog bst.o bstTest.o
bst.o : bst.c bst.h
	gcc -c $(CFLAGS) bst.c
bstTest.o : bstTest.c bst.h
	gcc -c $(CFLAGS) bstTest.c

