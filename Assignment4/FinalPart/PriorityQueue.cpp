#include <iostream>
using namespace std;

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    this->arr = new BinaryHeap<ElementType>();
}

template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
    delete this->arr;
    this->arr = nullptr;
    
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
    return  this->arr->getElementCount() == 0;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement){
    bool ans =  arr->insert(newElement);
     if(ans == true){
        return true;
     }
     return false;
}

template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    arr->remove();
}

template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek()const{
       return  arr->retrieve();
}
