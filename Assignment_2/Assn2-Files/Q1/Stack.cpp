/* 
 * StackTestDriver.cpp
 *
 * Description: Test Driver for Stack class.
 *
 * Author: EKAMLEEN MAAN, SANDRA FAWZY
 * Date:october 2023
 */


#include <iostream>
#include "Stack.h" 


Stack::Stack()
{
    // Constructor for Stack class
    // Initialize the head pointer to nullptr and set the size to 0.
    head = nullptr;
    size = 0;
}


Stack::~Stack()
{
    // Destructor for Stack class
    // Deallocate memory and remove all elements from the stack.
    while(!isEmpty())
    {
        pop();
    }

}


bool Stack::push(int newElement)
{ 
    // Push a new element onto the stack. 
    // Create a new node and set its data to the new element.
    StackNode* newNode = new StackNode;
    newNode->data = newElement;
    newNode->next = nullptr;

    if(head == nullptr)
    {
    // If the stack is empty, set the head to the new node and increase the size.
    // this means stack is empty
        head = newNode;
        size++;
        return true;
    }

    else
    {
        // If the stack is not empty, traverse to the end and add the new node.
        StackNode* current = head;

        while(current-> next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
        size++;
        return true;

    }
     return false;
}


bool Stack::pop()
{
    // Pop the top element from the stack.
    if(head == nullptr)
    {
        // If the stack is empty, return false.
        return false;
    }


    if(size == 1)
    {
        // If there is only one element, delete it, and set head to nullptr.
        StackNode* deleted = head;
        head = nullptr;
        size--;
        delete deleted;
        return true;
    }

    else
    {
        // If there are multiple elements, traverse to the second-to-last element and delete the last one.
        StackNode* current = head;

        while(current->next->next != nullptr)
        {
            current = current->next;
        }

        StackNode* deleted = current->next;
        current->next = nullptr;
         delete deleted;
        size--;
        return true;
    }  
     return false;
}


int Stack::peek()
{
     // Return the top element of the stack.

    if(head == nullptr)
    {
        // If the stack is empty, return 0 (or another appropriate value).
        return 0;

    }

    StackNode* current = head;

    while(current-> next != nullptr)
    {
        current = current->next;

    }

    return current->data;
}


bool Stack::isEmpty()
{
    // Check if the stack is empty.
    return this->size == 0;

}