all : monprogramme

monprogramme : test_my_struct.o random.o my_struct.o
	gcc random.o my_struct.o test_my_struct.o -o monprogramme

my_struct.o : my_struct.c my_struct.h
	gcc my_struct.c -c -o my_struct.o

random.o : ../random/random.c ../random/random.h
	gcc ../random/random.c -c -o random.o
	
test_my_struct.o : test_my_struct.c
	gcc test_my_struct.c -c -o test_my_struct.o

clean :
	rm -f *.o monprogramme
