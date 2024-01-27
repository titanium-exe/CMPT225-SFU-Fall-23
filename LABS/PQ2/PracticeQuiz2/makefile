
td:	testDriver.o DataCollection.o UnableToInsertException.o
	g++ -o td -Wall DataCollection.o testDriver.o UnableToInsertException.o

testDriver.o:	testDriver.cpp DataCollection.h UnableToInsertException.h
	g++ -c -Wall testDriver.cpp

DataCollection.o:	DataCollection.cpp DataCollection.h UnableToInsertException.h
	g++ -c -Wall DataCollection.cpp
	
UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h
	g++ -c -Wall UnableToInsertException.cpp

clean:	
	rm -f *.o td
