/* 
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: None!
 *
 * Author: AL
 * Date: Oct. 2023
 */
 
#ifndef DATA_COLLECTION_H
#define DATA_COLLECTION_H

using std::ostream;

class DataCollection {

   private:

      // Description:  Nodes for a singly-linked list
      class Node {
         public:
            int data;
            Node * next = nullptr;
         
         Node(int theData): data(theData) {}
      };
     
      
      // Data member: 
      Node * head = nullptr;  // head is the pointer to the first node


   public:

      // Description: Default constructor. Constructs a DataCollection object.
      DataCollection();

      // Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
      DataCollection(const DataCollection & DC);

      // Description: Destructs a DataCollection object, releasing all heap-allocated memory.
      ~DataCollection();
      
      // Description: Appends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void append(int newElement);

      // Description: Prepends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void prepend(int newElement);

      // Description: Prints the content of this DataCollection "thisDC".
      friend ostream & operator<<(ostream & os, const DataCollection & thisDC); 
      
};
#endif
