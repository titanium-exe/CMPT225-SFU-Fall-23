all: tdQ

tdQ:  Main.o Queue.h Event.o 
	g++ -o tdQ -Wall  Main.o Event.o 

Main.o:  Main.cpp 
	g++ -c -Wall  Main.cpp
	
Event.o: Event.cpp Event.h
	g++ -c -Wall Event.cpp


clean:	
	rm -f tdQ *.o
