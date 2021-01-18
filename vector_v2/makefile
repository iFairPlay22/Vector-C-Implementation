all : monprogramme

monprogramme : test_vector.o vector.o
	gcc vector.o test_vector.o -o monprogramme

vector.o : vector.c vector.h
	gcc vector.c -c -o vector.o

test_vector.o : test_vector.c
	gcc test_vector.c -c -o test_vector.o

clean :
	rm -f *.o monprogramme
