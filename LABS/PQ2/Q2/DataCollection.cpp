/*
 * D103+D104
 * DataCollection.cpp
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: There are no class invariant!
 *
 * Author: AL
 * Date: Oct. 2023
 */

#include <iostream>
#include <cmath>   // ceil()
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;


// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){
   // cout << "DataCollection Default constructor called!" << endl; // For testing purposes!
}

// Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){
   // cout << "DataCollection Copy constructor called!" << endl; // For testing purposes!

   head = nullptr;
   if (DC.head != nullptr){
      Node *current = DC.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

// Description: Destructs a DataCollection object, releasing all heap-allocated memory.
DataCollection::~DataCollection(){
   // cout << "DataCollection Destructor called!" << endl; // For testing purposes!

   Node * temp = nullptr;
   for (Node * toBeDeleted = head; toBeDeleted != nullptr;) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){
   // cout << "DataCollection append called!" << endl; // For testing purposes!
   
   Node * newNode = new Node(newElement); 
   if (newNode == nullptr)  
      throw UnableToInsertException("In DataCollection::append(): new failed, newNode cannot be allocated heap memory."); 

   if (head == nullptr){
      head = newNode;
   }else{
      Node * current = head;
      while (current->next != nullptr){
         current = current->next;
      }
      current->next = newNode;
   }
   return;
}

// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   // cout << "DataCollection prepend called!" << endl; // For testing purposes!

   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException("in DataCollection::prepend(): new failed, newNode cannot be allocated heap memory."); 
  
   if (head != nullptr) newNode->next = head;
   head = newNode;

   return;
}
 
// Description: Removes and returns the element located in the middle of the DataCollection.
//              The position of the elements in DataCollection ranges from [1 .. "total number of elements"].               
//              When computing the position of the middle element, round up to nearest integral value.           
// Exception Handling: Throws EmptyDataCollectionException.
int DataCollection::removeMiddle() {
   // if the list is empty
   if(this->head == nullptr){
      throw EmptyDataCollectionException("the list is empty can't remove anything ");
   }
   
   Node* current = this->head;
   int counter = 0; // it will count the no. of the elements 
   while(current != nullptr){
      counter++;
      current = current->next;
   }

   // counter is the no of elements 
   int middle = 0;
   if(counter == 1){        // if there is only one element 
      int val = head->data;
      delete head;  
      this->head = nullptr;
      return val;
   }
   else if(counter%2 == 0){   // finding the right middle element acc to the even/odd no.
        middle = counter/2; 
   }else if( counter%2 != 0){
      middle = (counter/2)+1;
   } 
   Node* temp = this->head;
   int nodeCounter = 1;
   while(nodeCounter != middle -1){
      temp = temp->next;
      nodeCounter++;
   }

   //now we are at the middle node -1 .
   Node* toBeRemoved = temp->next;
   temp->next = toBeRemoved->next;
   int val = toBeRemoved->data;  
   toBeRemoved->next  = nullptr;
   delete toBeRemoved;
   return val;  // returnig the value i deleted 
   
}           
            
// Bonus Method: Will be marked only if you have implemented and submitted the above method.
// Description: Computes the average of the values of all elements found in the DataCollection.
//              If the ceil(average) is odd, then the method returns the average, otherwise, "0.0" is returned.
// Exception Handling: Throws EmptyDataCollectionException.
float DataCollection::averageOdd() {

    if(this->head == nullptr){
      throw EmptyDataCollectionException("the list is empty can't remove anything ");
   }

   Node* current = this->head;
   int sum =0;
   int counter = 0;
   while(current != nullptr ){
      sum += current->data;
      counter++;
      current = current->next;
   }

   int  average = sum / counter ;
  
   if(average % 2 != 0){
      float  averageF = sum/counter;
      return averageF;
   }
   
   return 0.0;   // You can change this statement!
}

// Description: Prints the content of this DataCollection "thisDC"
//              using this format: {element1, element2, ..., elementn}.
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; 
   
   // Traverse the DataCollection
   while (current != nullptr){
      cout << current -> data;   
      current = current -> next; 
      if (current != nullptr){
         cout << ",";
      }
   }
   cout << "}"; // Don't print a newline - it might not be needed.

   return os;
} 