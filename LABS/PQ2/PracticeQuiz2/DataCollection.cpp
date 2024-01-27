/* 
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: None!
 *
 * Author: AL
 * Date: Oct. 2023
 */

#include <iostream>
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;


// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){
   // cout << "DataCollection Default constructor called!" << endl;
}

// Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){
   // cout << "DataCollection Copy constructor called!" << endl;

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
   // cout << "DataCollection Destructor called!" << endl;

   Node * temp = nullptr;
   for ( Node * toBeDeleted = head; toBeDeleted != nullptr; ) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){

Node* newNode = new Node(newElement);
   newNode->next = nullptr;
   if(newNode == nullptr){
      throw UnableToInsertException("there is not enough memory in the heap");
   }
   if(head == nullptr){
      this->head = newNode;
      return;
   }
   Node* temp = this->head;
   while(temp->next != nullptr){
      if(temp->data == newElement){
      throw UnableToInsertException(" there is a duplicate element");
   }
   temp = temp->next;
   }
   //checking for the last node.
   if(temp->data == newElement){
      throw UnableToInsertException(" there is a duplicate element");
   }
   // now we are at the last element
   
   temp->next = newNode;


   return;
}


// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   
   Node* newNode = new Node(newElement);
   if(newNode == nullptr){
      throw UnableToInsertException("not enough heap memory");

   }
   
   if(head == nullptr){
      this->head = newNode;
      return;
   }else{
      newNode->next = head;
      head = newNode;
   
   }
   return;
}
 
// Description: Prints the content of this DataCollection "thisDC".
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; 
   while (current != nullptr){
      cout << current -> data; 
      current = current -> next; 
      if (current != nullptr){
         cout << ","; 
      }
   }
   cout << "}";

   return os;

} 
