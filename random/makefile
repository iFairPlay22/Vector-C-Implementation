all : monprogramme

monprogramme : test_random.o random.o
	gcc random.o test_random.o -o monprogramme

random.o : random.c random.h
	gcc random.c -c -o random.o

test_random.o : test_random.c
	gcc test_random.c -c -o test_random.o

clean :
	rm -f *.o monprogramme
