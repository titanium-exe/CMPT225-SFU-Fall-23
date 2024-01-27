
#include <iostream>
#include "EmptyDataCollectionException.h"
using namespace std;

template <typename ElementType>
Queue<ElementType>::Node::Node(ElementType &value)
{
    this ->data = value;
    this->next = nullptr;
    
}

template <typename ElementType>
Queue<ElementType>::Queue()
{
    this->elementCount = 0;
    this->front = nullptr;
    this->back = nullptr;
}
template <typename ElementType>
Queue<ElementType>::~Queue()
{
    if (this->front == nullptr) {
        return;
  }
  while (this->front != nullptr) {
    Node *toBeDeleted = this->front;
    this->front = this->front->next;
    toBeDeleted->next = nullptr;
    delete toBeDeleted;

    this->elementCount--;
  }
  // now head is nullptr
  this->back = nullptr;
}

template <typename ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return this->elementCount == 0;
}

template <typename ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement)
{
    if (elementCount == 0)
    {
        Node *newNode = new Node(newElement);

        this->front = newNode;
        this->back = newNode;
        this->elementCount++;
        //cout<<this->elementCount<<endl;
        return true;
    }
    else
    {
        // i'm enqueuing at the tail of the linkedList
        Node *newNode = new Node(newElement);
        back->next = newNode;
        
        back = newNode;
        this->elementCount++;
        //cout<<this->elementCount<<endl;
        return true;
    }

    return false;
}

template <typename ElementType>
void Queue<ElementType>::dequeue()
{
    if (this->elementCount == 0)
    {
        throw EmptyDataCollectionException("This is empty");
    }
    // i'm removing at the head of the LinkedList

    Node *tobeDeleted = this->front;

    if (this->elementCount == 1)
    {
        delete tobeDeleted;
        this->front = nullptr;
        this->back = nullptr;
        this->elementCount--;
        //cout<<this->elementCount<<endl;
        return;
    }
    front = front->next;

    tobeDeleted->next = nullptr;
    delete tobeDeleted;
    this->elementCount--;
    //cout<<this->elementCount<<endl;
    return;
}

template <typename ElementType>
ElementType& Queue<ElementType>::peek()const{
     if (this->elementCount == 0)
    {
        throw EmptyDataCollectionException("This is empty");
    }
    return front->data;
}