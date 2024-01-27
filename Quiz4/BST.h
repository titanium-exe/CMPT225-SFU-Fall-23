/*
 * D103+D104
 * BST.h
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

#ifndef BST_H
#define BST_H

#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

class BST {
	
  class BSTNode {

    public:
  
      int element = 0;
      BSTNode * left = nullptr;
      BSTNode * right = nullptr;
      int mystery = 0;
  
      // Constructors
      BSTNode() {}
      BSTNode(int element) { this->element = element; }

      // Boolean helper functions
      bool isLeaf() const { return (left == nullptr && right == nullptr); }
      bool hasLeft() const { return (left != nullptr); }
      bool hasRight() const { return (right != nullptr); }

  };

	
private:

/* Data Members */

  // You cannot change the following data members of this class.

  BSTNode * root = nullptr; 
  unsigned int elementCount = 0;          

/* Utility methods */
	
// Feel free to add private methods to this class.

  // Description: Recursive preorder traversal of a binary search tree 
  //              in order to build its copy.
  void copyR(BSTNode * current);

  // Description: Recursive postorder traversal of a binary search tree
  //              in order to release heap memory allocated to BSTNode.
  void destroyR(BSTNode * current);
  
  // Description: Recursive insertion into a binary search tree.
  void insertR(BSTNode * newElement, BSTNode * current);

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void printInOrderR(BSTNode * current) const;
  int targetCount(BSTNode* current,const int targetElement, int&counter) const; 


  
public:

// You cannot change the prototype of the public methods of this class.


/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  BST();            

  // Parameterized constructor
  BST(int element);        

  // Copy constructor
  BST(const BST & aBST);

  // Destructor 
  ~BST();


/* Getters and setters */
   
  // Description: Returns the number of elements currently stored in the binary search tree.  
  unsigned int getElementCount() const;

/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).  
  void insert(int newElement);
  

  // Description: Prints the content of the binary search tree in order
  //              i.e., in ascending order from smallest element to largest
  //              printing each BSTNode using the following format:
  //              [<key value of element>,<mystery>].
  //              This is a wrapper method which calls the recursive printInOrderR( ).
  // Precondition: Binary search tree is not empty.
  // Exception: Throws the exception "EmptyDataCollectionException" 
  //            if the binary search tree is empty.
  void printInOrder() const;

  
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
  int targetCount(const int targetElement) const; 

};

#endif
