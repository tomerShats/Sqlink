CFLAGS  = -pedantic -g -Wall 
aprog : darray_generic.o darray_genericTest.o
	gcc -o aprog darray_generic.o darray_genericTest.o
darray_generic.o : darray_generic.c darray_generic.h
	gcc -c $(CFLAGS) darray_generic.c
darray_genericTest.o : darray_genericTest.c darray_generic.h
	gcc -c $(CFLAGS) darray_genericTest.c

