/* 
 * Queue.cpp - 
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: SANDRA FAWZY, EKAMLEEN MAAN
 * Date : october 2023
 */
 
#include <iostream>
#include "Queue.h"

// Description: Constructor

Queue::Queue() 
{
    capacity = INITIAL_CAPACITY;
    elements = new int[capacity];
    frontindex = 0;
    backindex = 0;
    elementCount = 0;

}


// Description: Inserts newElement at the back of Queue

// Time Efficiency: O(1)

void Queue::enqueue(int newElement) 
{

if (frontindex == backindex ) 
{
    // Create a new array with double the capacity
    int newCapacity = 2 * capacity;
    int* copyElements = new int[newCapacity];

    // Copy the elements from the old array to the new array (circular Queue)

    for (unsigned int i = 0; i < elementCount; i++) 
    {
        copyElements[i] = elements[(frontindex + i) % capacity];
    }

    // Update capacity and backindex
    frontindex = 0;
    backindex = elementCount; // this will point to the first empty block of new copied array.

    // Delete the old array 
    delete[] elements;
    elements = copyElements; // point elements to our new Array
    capacity = newCapacity;
}
// Add the new element to the back of the queue

    elements[backindex] = newElement;
    elementCount++;
    backindex = (backindex + 1) % capacity;

}


// Description: Removes the frontmost element

// Precondition: Queue not empty 

// Time Efficiency: O(1)

void Queue::dequeue() 
{

    if(elementCount < (capacity-1)/4)
    {

        int newCapacity = 0.5 * capacity;

        int* copyElements = new int[newCapacity];

        for (unsigned int i = 0; i < elementCount; i++) 
        {
            copyElements[i] = elements[(frontindex + i) % newCapacity];
        }

        frontindex = 0;
        backindex = elementCount; // this will point to the first empty block of new copied array.
        capacity = newCapacity; 

        delete[] elements;
        elements = copyElements; // point elements to our new Array

    }

    elementCount--;

    frontindex = (frontindex+1)%capacity;
} 


// Description: Returns a copy of the frontmost element

// Precondition: Queue not empty

// Time Efficiency: O(1)

int Queue::peek() const 
{
    return elements[frontindex]; 
} 


// Description: Returns true if and only if Queue empty

// Time Efficiency: O(1)

bool Queue::isEmpty() const 
{
    return elementCount == 0;
}