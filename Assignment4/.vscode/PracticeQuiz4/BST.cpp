/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Date of last modification: Nov. 2023
 */
 
#include "BST.h"
#include <iostream>

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
  
    //cout << "BST Copy constructor called!" << endl;
           
    if ( aBST.elementCount == 0 ) {
      //cout << "aBST is empty!" << endl;	
      this->elementCount = 0;
      this->root = nullptr;
    }
    else
      copyR(aBST.root);	
  }

  // Destructor 
  BST::~BST() {

    //cout << "BST destructor called!" << endl;
     
    if ( this->root != nullptr ) {
      destroyR(root);
      root = nullptr;
    }

  }                


/* Helper methods */
  
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void BST::copyR(BSTNode * current) {
    
    //cout << "copyR called!" << endl;

    if (current != nullptr) {
      this->insert(current->element);
      copyR(current->left);
      copyR(current->right);
    }    
    return;
  }

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
  void BST::destroyR(BSTNode * current) {
  
    // cout << "destroyR called!" << endl;
  
    if (current != nullptr) {
      destroyR(current->left);
      destroyR(current->right);
      delete current;
      current = nullptr;
      this->elementCount--;
    }
    return;
  }

/* Getters and setters */
   

  // Description: Returns the number of elements currently stored in the binary search tree.     
  unsigned int BST::getElementCount() const { 
    return this->elementCount;
  }


/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).   
  void BST::insert(int newElement) {
     
    // Binary search tree is empty, so add the new element as the root
    BSTNode * newBSTNode = new BSTNode(newElement);
    if (newBSTNode == nullptr)
      throw UnableToInsertException("In insert(): operator new failed!");
    if (elementCount == 0 ) // and root == nullptr
      root = newBSTNode;
    else {
      try { // can I let it flow through? no try/catch block?
        insertR(newBSTNode, root);
      }
      catch ( UnableToInsertException & e ) {
        throw UnableToInsertException("Operator new failed!");
      }
    }

    this->elementCount++;
    return;
  } 
  

  // Description: Recursive insertion into a binary search tree.
  void BST::insertR(BSTNode * newBSTNode, BSTNode * current) { 
  
    // If the element to be inserted < the element at current node, insert it to the left subtree
    if (newBSTNode->element < current->element) {
      // If current node's left subtree is empty add the new node there
      if (!current->hasLeft()) {
        current->left = newBSTNode; // new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the left subtree
      else 
        insertR(newBSTNode, current->left);
    }
    // If the element to be inserted > the element at current node, insert it to the right subtree
    else { // if ( element >=  current->getElement() ) {
      // If current node's right subtree is empty add the new node there
      if (!current->hasRight()) {
        current->right = newBSTNode; //new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the right subtree
      else 
        insertR(newBSTNode, current->right);
    }
  } 

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int BST::numberOfNodes( ) const {
  
    // Put your code here
	
  }

  // Description: Returns the height of this binary search tree.
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int BST::height() const {

    // Put your code here

  }
  
  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void BST::printInOrder() const {

    cout << "Printing BST with elementCount = " << elementCount << endl;
    cout << "{ ";
    if (elementCount != 0) printInOrderR(root);
    cout << "}";

    return;
  }

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void BST::printInOrderR(BSTNode *current) const {
    if (current != nullptr) {
      printInOrderR(current->left);
      cout << current->element << " ";
      printInOrderR(current->right);
    }
    return;
  }
