#include<iostream>
#include <cmath>
#include "EmptyDataCollectionException.h"



using namespace std;
template <class ElementType>

BinaryHeap<ElementType>::~BinaryHeap()
{
   delete[] this->arr;
   this->arr = nullptr;
   this->elementCount = 0;
}

template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(BinaryHeap &rhsHeap)
{
   this->size = rhsHeap->size;
   this->arr = new ElementType[size];
   for (int i = 0; i < rhsHeap->elementCount; i++)
   {
      this->arr[i] = rhsHeap->arr[i];
      this->elementCount++;
   }
}

// this is the default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
   // Dynamically constructed the array of heap
   this->size = 5;
   this->arr = new ElementType[this->size];
   this->elementCount = 0;
}

template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
   return this->elementCount;
}

template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{
   

   if (this->elementCount == size)
   {
 
      resize(size * 2);
   }
 
   arr[this->elementCount] = newElement;
   this->elementCount++;
   reHeapUp(this->elementCount-1);
   return true;
}

template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(int childIndex)
{

   if (childIndex == 0)
   {
      return;
   }
   int parentIndex = floor((childIndex - 1) / 2);
   if (!(arr[parentIndex] <= arr[childIndex]))
   {
      ElementType temp = arr[childIndex];
      arr[childIndex] = arr[parentIndex];
      arr[parentIndex] = temp;
   }
   reHeapUp(parentIndex);
}

template <class ElementType>
void BinaryHeap<ElementType>::resize(int newlen)
{
   // no size change => nothing to do
   if (newlen == size)
      return;

   // precondition check
   if (newlen < size)
      return;

   // allocate new space
   ElementType *newElements = new ElementType[newlen];
   if (newElements == nullptr){
      throw EmptyDataCollectionException("No avaiable heap memory");
   }

   // copy elements to new space
   for (unsigned int i = 0; i < elementCount; i++)
   {
      newElements[i] = arr[i];
   }

   // recycle new space
   delete[] arr;
   arr = newElements;

   // update properties
   size = newlen;

   return;
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{

   if (elementCount == 0){
      throw EmptyDataCollectionException("Nothing to remove");
   }
   
   arr[0] = arr[elementCount - 1];
 
   elementCount--;

   // No need to call reheapDown() is we have just removed the only element
   if (elementCount > 0)
      reHeapDown(0);

   return;
}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot)
{

   unsigned int indexOfMinChild = indexOfRoot;

   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1)
      return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if (!(arr[indexOfRoot] <= arr[indexOfLeftChild]))
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount)
   {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if (!(arr[indexOfMinChild] <= arr[indexOfRightChild]))
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot)
   {

      ElementType temp = arr[indexOfRoot];
      arr[indexOfRoot] = arr[indexOfMinChild];
      arr[indexOfMinChild] = temp;

      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}

template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{
   
   return this->arr[0];
}


