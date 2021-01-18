all : monprogramme

monprogramme : test_vector_random.o random.o vector.o
	gcc random.o vector.o test_vector_random.o -o monprogramme

vector.o : ../vector_v2/vector.c ../vector_v2/vector.h
	gcc ../vector_v2/vector.c -c -o vector.o

random.o : ../random/random.c ../random/random.h
	gcc ../random/random.c -c -o random.o

test_vector_random.o : test_vector_random.c
	gcc test_vector_random.c -c -o test_vector_random.o

clean :
	rm -f *.o monprogramme
