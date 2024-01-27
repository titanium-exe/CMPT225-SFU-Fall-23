td:	testDriver.o DataCollection.o UnableToInsertException.o EmptyDataCollectionException.o
	g++ -o td -Wall DataCollection.o testDriver.o UnableToInsertException.o EmptyDataCollectionException.o

testDriver.o: testDriver.cpp DataCollection.h UnableToInsertException.h EmptyDataCollectionException.h
	g++ -c -Wall testDriver.cpp

DataCollection.o: DataCollection.cpp DataCollection.h UnableToInsertException.h EmptyDataCollectionException.h
	g++ -c -Wall DataCollection.cpp
	
UnableToInsertException.o: UnableToInsertException.cpp UnableToInsertException.h
	g++ -c -Wall UnableToInsertException.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c -Wall EmptyDataCollectionException.cpp

clean:	
	rm -f *.o td
