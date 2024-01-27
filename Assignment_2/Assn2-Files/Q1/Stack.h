/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author:
 * Date:
 */
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        StackNode* head;
        int size;
/* Put your code here! */       
        

    public:

        Stack();
        ~Stack();
        bool push(int newElement);
        bool pop();
        int peek();
        bool isEmpty();
/* Put your code here! */   


};
