/* 
 * testDriver.cpp
 *
 * Description: Test drive the Data Collection ADT class.
 *
 * Author: AL
 * Date: Oct. 2023
 */
 
#include <iostream>
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::endl;


int main () {
   DataCollection * aDC1 = new DataCollection( );
   DataCollection * aDC2 = new DataCollection( );
   DataCollection * aDC3 = new DataCollection( );
      
// Test case 1 - Empty DataCollection 1
   cout << "Test Case 1 - Just constructed a DataCollection 1:" << endl;
   cout << "Empty DataCollection 1: " << *aDC1 << endl;

// Test case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1
   cout << "Test Case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1:" << endl;
   cout << "              expecting: 6 5 4 3 2 1 in DataCollection 1:" << endl;


   for (unsigned int i = 1; i <= 6; i++) {
      try {
	    cout << "Prepending " << i << " to DataCollection 1" << endl;
            aDC1->prepend( i );
      }
      catch ( UnableToInsertException & anException ) {
	    cout << "prepend() unsuccessful because " << anException.what() << endl;
      }
   }
   cout << "Content of DataCollection 1: " << *aDC1 << endl;
   

// Test case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2
   cout << "Test Case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2:" << endl;
   cout << "              expecting: 1 2 3 4 5 6  in DataCollection 2:" << endl;


   for (unsigned int i = 1; i <= 6; i++) {
      try {
         cout << "Appending " << i << " to DataCollection 2" << endl;
         aDC2->append( i );
      }
      catch ( UnableToInsertException & anException ) {
         cout << "append() unsuccessful because " << anException.what() << endl;
      }
   }
   cout << "Content of DataCollection 2: " << *aDC2 << endl;


// Test case 4 - Prepending and Appending a few elements to DataCollection 3
   cout << "Test Case 3 - Prepending and Appending a few elements to DataCollection 3:" << endl;
   cout << "              expecting: 3 4 1 2 5 6  in DataCollection 3:" << endl;


   try {
      cout << "Appending 1 to DataCollection 3" << endl;
      aDC3->append( 1 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 2 to DataCollection 3" << endl;
      aDC3->append( 2 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Prepending 4 to DataCollection 3" << endl;
      aDC3->prepend( 4 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Prepending 3 to DataCollection 3" << endl;
      aDC3->prepend( 3 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 5 to DataCollection 3" << endl;
      aDC3->append( 5 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 6 to DataCollection 3" << endl;
      aDC3->append( 6 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   cout << "Content of DataCollection 3: " << *aDC3 << endl;
   cout<<aDC3->removeMiddle()<<endl;
   

   cout<< "this is new Data "<<endl;
   DataCollection * aDC4 = new DataCollection( );

   aDC4->append(9);
   aDC4->append(8);
   aDC4->append(11);
   aDC4->append(12);
   aDC4->append(13);
   aDC4->append(15);
   cout << "Content of DataCollection 4: " << *aDC4<< endl;
   
   aDC4->removeMiddle();
   cout << "Content of DataCollection 4: " << *aDC4 << endl;
   

   delete aDC1;
   aDC1 = nullptr;
    
   delete aDC2;
   aDC2 = nullptr;
    
   delete aDC3;
   aDC3 = nullptr;
    
   return 0;
}
