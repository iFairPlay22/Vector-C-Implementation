all : monprogramme

monprogramme : random.o my_struct.o test_vector.o vector.o
	gcc random.o my_struct.o vector.o test_vector.o -o monprogramme

vector.o : vector.c vector.h
	gcc vector.c -c -o vector.o

random.o : ../random/random.c ../random/random.h
	gcc ../random/random.c -c -o random.o

my_struct.o : ../my_struct/my_struct.c ../my_struct/my_struct.h
	gcc ../my_struct/my_struct.c -c -o my_struct.o

test_vector.o : test_vector.c
	gcc test_vector.c -c -o test_vector.o

clean :
	rm -f *.o monprogramme
