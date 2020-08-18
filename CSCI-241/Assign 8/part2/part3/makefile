#
#PROGRAM: Recursive Quicksort
#PROGRAMMER: Tristen Anderson
#ZID: z1820036
#


CCFLAGS = -ansi -Wall -std=c++11

Assign8: Assign8.o 
	g++ $(CCFLAGS) -o Assign8 Assign8.o 

Assign8.o: Assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c Assign8.cpp

clean:
	-rm *.o Assign8
