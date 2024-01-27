/*
 * D103+D104
 * BST.cpp
 * 
 * Description: Binary Search Tree (BST) data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Class invariant: It is always a Binary Search Tree (BST).
 *                  All element key values in left subtree of root < element key value in root.
 *                  All element key values in right subtree of root >= element key value in root.
 *
 * Date of last modification: Nov. 2023
 */
 
#include <iostream>
#include "BST.h"

using std::cout;
using std::endl;

/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  BST::BST() { }            

  // Parameterized constructor
  BST::BST(int element) {
    root = new BSTNode(element);
    elementCount = 1;
  }

  // Copy constructor
  BST::BST(const BST & aBST) {         
    if ( aBST.elementCount == 0 ) {
      this->elementCount = 0;
      this->root = nullptr;
    }
    else
      copyR(aBST.root);	
  }

  // Destructor 
  BST::~BST() {    
    if ( this->root != nullptr ) {
      destroyR(root);
      root = nullptr;
    }
  }                

/* Getters and setters */
   
  // Description: Returns the number of elements currently stored in the binary search tree.  
  unsigned int BST::getElementCount() const { 
    return this->elementCount;
  }

/* Utility methods */
  
  // Description: Recursive preorder traversal of a binary search tree 
  //              in order to build its copy.
  void BST::copyR(BSTNode * current) {
    if (current != nullptr) {
      this->insert(current->element);
      copyR(current->left);
      copyR(current->right);
    }    
    return;
  }

  // Description: Recursive postorder traversal of a binary search tree
  //              in order to release heap memory allocated to BSTNode.
  void BST::destroyR(BSTNode * current) {
    if (current != nullptr) {
      destroyR(current->left);
      destroyR(current->right);
      delete current;
      current = nullptr;
      this->elementCount--;
    }
    return;
  }
  

/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).   
  void BST::insert(int newElement) {
    BSTNode * newBSTNode = new BSTNode(newElement);
    if (newBSTNode == nullptr)
      throw UnableToInsertException("In insert(): operator new failed!");

    if (elementCount == 0 ) 
      root = newBSTNode;
    else 
      insertR(newBSTNode, root);

    this->elementCount++;
    return;
  }

  // Description: Recursive insertion into a binary search tree.
  void BST::insertR(BSTNode * newBSTNode, BSTNode * current) { 
  
    if (newBSTNode->element < current->element) {
      if (!current->hasLeft()) {
        current->left = newBSTNode; 
        return;
      }
      else 
        insertR(newBSTNode, current->left);
    }
    else { 
      if (!current->hasRight()) {
        current->right = newBSTNode; 
        return;
      }
      else 
        insertR(newBSTNode, current->right);
    }
  }  
    
  // D103+D104
  // Description: Counts the number of times targetElement is found in each 
  //              of the subtrees of this binary search tree, updates the data member
  //              "mystery" of each BSTNode (in this binary search tree) with this count, 
  //              i.e., the count of the number of times targetElement is found in 
  //              the subtree rooted at this BSTNode (the search including this BSTNode) 
  //              and returns this count.
  //              *** You are free to implement this method either iteratively or 
  //                  recursively (with a wrapper and a recursive method) ***.
  // Example: If the key values of the elements to be inserted into the 
  //          binary search tree are: 11 7 13 9 1 15 19 and the targetElement is 7
  //          printing this binary search tree once this method has executed 
  //          will display the following (where [<key value of element>,<mystery>]): 
  //          [1,0], [7,1], [9,0], [11,1], [13,0], [15,0], [19,0]
  // Precondition: Binary search tree is not empty.
  // Exception: Throws the exception "EmptyDataCollectionException" 
  //            if the binary search tree is empty.
  // ***This method does not print anything.***
  int BST::targetCount(const int targetElement) const {
	  
       if(this->elementCount == 0){
         throw EmptyDataCollectionException("Binary search tree is empty.");
       }
       int counter =0;
       int ans =  targetCount(this->root, targetElement, counter);
       return ans;
	
  }
   
  int BST::targetCount(BSTNode* current, const int targetElement, int &counter) const{
       // Base Case 
        if(current == nullptr){
          return 0;
        }
        // updating the counter
         if(current->element == targetElement){
            current->mystery = 1;
            return 1;
         }
         
        if(targetElement < current->element){
              int ans =  targetCount(current->left, targetElement,counter);
              current->mystery = ans;
              return ans;

        }else{
          int ans =  targetCount(current->right, targetElement, counter);
          current->mystery = ans;
          return ans;
        }
  }
 
  // Description: Prints the content of the binary search tree in order
  //              i.e., in ascending order from smallest element to largest
  //              printing each BSTNode using the following format:
  //              [<key value of element>,<mystery>].
  //              This is a wrapper method which calls the recursive printInOrderR( ).
  // Precondition: Binary search tree is not empty.
  // Exception: Throws the exception "EmptyDataCollectionException" 
  //            if the binary search tree is empty.
   void BST::printInOrder() const {
      if (elementCount == 0)  
         throw EmptyDataCollectionException("Binary search tree is empty.");

      printInOrderR(root);

      return;
   }
   

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.  
  void BST::printInOrderR(BSTNode *current) const {
    if (current != nullptr) {
      printInOrderR(current->left);
      cout << "[" << current->element << ",";
	  cout << current->mystery << "] ";
      printInOrderR(current->right);
    }
    return;
  }