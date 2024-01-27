
#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

template <class ElementType>
class BinaryHeap 
{

    ElementType *arr; // Nullptr for the heap array
    int elementCount;
    int size;
    void resize(int newlen);
    void reHeapUp(int childIndex);
    void reHeapDown(unsigned int indexOfRoot);

public:
    BinaryHeap();
    ~BinaryHeap();
    BinaryHeap(BinaryHeap &rhsHeap);
    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition: The Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Description: Inserts newElement into the Binary Heap.
    //              It returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool insert(ElementType &newElement);

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1)
    ElementType &retrieve() const;
};
#include "BinaryHeap.cpp"

#endif