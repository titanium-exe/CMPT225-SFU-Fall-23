all: tdQ

tdQ:  Main.o BinaryHeap.h 
	g++ -o tdQ -Wall  Main.o
Main.o:  Main.cpp BinaryHeap.h
	g++ -c -Wall  Main.cpp	

clean:	
	rm -f tdQ *.o
