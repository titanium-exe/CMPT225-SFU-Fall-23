all: fb

fb: MyADTTestDriver.o MyADT.o Profile.o
	g++ -Wall -o fb MyADTTestDriver.o MyADT.o Profile.o

MyADTTestDriver.o : MyADTTestDriver.cpp MyADT.h Profile.h
	g++ -Wall -c MyADTTestDriver.cpp

MyADT.o: MyADT.h MyADT.cpp
	g++ -Wall -c MyADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

clean:
	rm -f fb *.o