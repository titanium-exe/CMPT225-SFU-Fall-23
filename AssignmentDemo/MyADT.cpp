/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: Ekamleen Maan
 * Last modified on: Sept 29 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;


    
// Default constructor.
MyADT::MyADT() {
  for(unsigned int i =0; i< MAX_ALPHA;i++){
   elements[i]=nullptr;
   elementCount[i] = 0;

  }
  
} // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
  for(unsigned int i = 0; i < MAX_ALPHA; i++){
    elements[i] = new Profile[MAX_ELEMENTS];
    elementCount[i] = rhs.elementCount[i];
    for(unsigned int j = 0; j < rhs.elementCount[i]; j++){
      elements[i][j] = rhs.elements[i][j];
    
    }

  }
}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {
  for (unsigned  int i = 0; i < MAX_ALPHA; i++) {
    delete[] elements[i];
   } 
} // end destructor


// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
  unsigned int counter = 0;
  for(unsigned int i =0; i<MAX_ALPHA;i++ ){
    counter += elementCount[i];
  }
  return counter;     
}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".

bool MyADT::insert(const Profile& newElement) {
  Profile temp(newElement);
  char character = newElement.getFirstLetter();
  unsigned  int intValue = character - 'A';

  // if array full return false
  if(elementCount[intValue] >= MAX_ELEMENTS){    // if there is no space for the elements it will not let the new element in.
	  return false;
  }
  
  // if array empty , make newElement array and insert in first position
  if(elementCount[intValue] ==0){
    Profile * newArray = new Profile[MAX_ELEMENTS];  //if the elementcount of that letter specific array is 0 then an array will be initialized and first element will be added.
    newArray[0] = newElement;  //new element got added
    elements[intValue] = newArray; //now the the big array is being made pointed to the new letter specific array that we created.
    elementCount[intValue]++; // element count of that letter specific array incremented.
    return true;
  }
  
  // otherwise go over the array , and check if ther element already in there
  for(unsigned int i = 0 ; i<elementCount[intValue]; i++){
    if(temp == elements[intValue][i]){
	    return false;
    }
  }
  // check where to insert the newElement element
  for(unsigned int i=0;i<=elementCount[intValue];i++){
    // if last e
    if(i == elementCount[intValue] ){     
      elements[intValue][i] = newElement;
      elementCount[intValue]++;
       return true;
    }

  // if newElement element is greater than the current element move over to the next element 
  if(temp > elements[intValue][i]){
      continue;
  }
  else{
    for(unsigned int j=elementCount[intValue]-1;j>=i;j--){
      elements[intValue][j+1] = elements[intValue][j]; //shifting the elements to the right.
      if(j==0) break;
    }
      elements[intValue][i] = newElement; // adding profile to the space we created by shifting all the elements to right.
      elementCount[intValue]++;
    
      return true;
    }
  }
    return false;  
} // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {

  char character = target.getFirstLetter();
  unsigned int intValue = character - 'A';
   Profile temp(target);

  for(unsigned int i = 0 ; i< elementCount[intValue]; i++){
   if(temp == elements[intValue][i] ){   
      return &elements[intValue][i]; 
      }
  }
    return nullptr; //if element is not found nullpointer will be returned.
}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {
      
      //Index of first letter 
  unsigned int index = toBeRemoved.getFirstLetter()-'A';
  for(unsigned int i = 0; i<elementCount[index]; i++){
    if(elements[index][i] == toBeRemoved){
      elements[index][i] = elements[index][elementCount[index]-1]; //Shifting the elements.
      elementCount[index]--;  //Decrementing the no of elements in the array.
        return true;
    }
  }
      return false;
}  // end remove


// Description: Remove all elements.
void MyADT::removeAll() {
  for(unsigned int i =0; i< MAX_ALPHA;i++){
    if(elements[i] != nullptr){
        delete[] elements[i];
        elements[i] = nullptr;
        elementCount[i] = 0;
    }
  }
} // end removeAll


void MyADT::print() {
  
  for(unsigned int i =0; i<MAX_ALPHA;i++){
    if( elements[i] != nullptr) {
      for(unsigned int j = 0; j< elementCount[i];j++){
        if (elementCount[i] >0) {
          cout<<elements[i][j];
        }
      }
    }
  }
} // end of print 
