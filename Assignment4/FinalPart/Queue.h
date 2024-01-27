#ifndef QUEUE_H_
#define QUEUE_H_

// Declaring as a template class
template <typename ElementType>
class Queue
{
   
    class Node
    {
    public:
        ElementType data;
        Node *next;
        
        Node(ElementType &value);
    };
    Node *front;
    Node *back;
    

public:
int elementCount;
    Queue();
    ~Queue();
    // Class Invariant:  FIFO or LILO order

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue
    //              (not necessarily the "back" of this Queue's data structure)
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType &newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType &peek() const;
};

#include "Queue.cpp"

#endif

