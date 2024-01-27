/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: EKAMLEEN MAAN and  TANVIR SAMRA 
 * Date of last modification: November 2, 2023 
 */
 
#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;


// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

   // Default constructor
BST::BST() { 
   root = nullptr; //instatiates the root as nullptr
   elementCount = 0; //makes element count as zero as we're making a new BST object
}            

   // Copy constructor
BST::BST(const BST &aBST) {
   root = copyTree(aBST.root); //uses a recursive method to copy the tree
   elementCount = aBST.elementCount; //copies the element count
}

BSTNode* BST::copyTree(BSTNode* sourceNode) { //recusive method that copies the tree
   if (sourceNode == nullptr) {
      return nullptr; // Base case
   }

   BSTNode* newNode = new BSTNode(sourceNode->element); //makes new node with the source node
   newNode->left = copyTree(sourceNode->left); //copies the left hand side
   newNode->right = copyTree(sourceNode->right); //copies the right hand side

   return newNode; //returns the tree in which we copied into
}


   // Destructor 
BST::~BST(){
    // Calls destroyTree in a rescurive way to empty out the tree
    destroyTree(root);
    root = nullptr;
}

void BST::destroyTree(BSTNode* node) {
    if (node == nullptr) {
        return;
    } // if tree is empty, return as there is nothing to delete

    // Recursively deletes the left and right elements of the tree
    destroyTree(node->left);
    destroyTree(node->right);
    this->elementCount--; //decrements as we delete elements of the tree
    
    // Deletes the root of the tree
    delete node;
}

   
/* Getters and setters */

   // Description: Returns the number of elements currently stored in the binary search tree.   
   // Time efficiency: O(1)   
unsigned int BST::getElementCount() const {     
   return this->elementCount; //returns the element count of the tree
}
   


/* BST Operations */



// Description: Inserts an element into the binary search tree.

// This is a wrapper method which calls the recursive insertR( ).

// Precondition: "newelement" does not already exist in the binary search tree.

// Exception: Throws the exception "UnableToInsertException" when newelement

// cannot be inserted because the "new" operator failed.

// Exception: Throws the exception "elementAlreadyExistsException"

// if "newelement" already exists in the binary search tree.

// Time efficiency: O(log2 n)

void BST::insert(WordPair &newelement){

BSTNode *newNode = new BSTNode(newelement); //makes a new BSTNode 

if (newNode == nullptr){
   throw UnableToInsertException("No new element got created"); //if there isn't any avaiable heap memory, throw an exception
}

if (root == nullptr){ //if the tree is empty, then instantiate the root of the tree as the newNode and update elementcount
   root = newNode;
   this->elementCount++;
   return;
}

bool ans = insertR(newNode, root); //call the recursive method of insert to and checks to see if the newNode already exists within the tree or not

if (ans == false){
   delete newNode;
   throw ElementAlreadyExistsException("this element is already there"); //if the element already exists within the tree, throw an exception as we can't have duplicates
}

}



// Description: Recursive insertion into a binary search tree.

// Returns true when "anelement" has been successfully inserted into the

// binary search tree. Otherwise, returns false.

bool BST::insertR(BSTNode *newBSTNode, BSTNode *current){

if (current->element == newBSTNode->element ){

   return false; //Checks for duplicates
}

if (newBSTNode->element < current->element){ //this segement follows the left-side of the tree

   if (current->hasLeft()){ //if there is a left element, then continue the recursive calls
      return insertR(newBSTNode, current->left);
}else{
      current->left = newBSTNode; //if not, then make the left of the current node of the tree, the newBSTnode, update elementcount, and then return true to signify that an insertion was successful
      this->elementCount++;
      return true;
   }
}

if (newBSTNode->element > current->element){ //this segement follows the right-hand side of the tree
   if (current->hasRight()){
      return insertR(newBSTNode, current->right); //if there is a right element, then continue the recursive calls
}else{
      current->right = newBSTNode; // if not, then make the right of the current node of the tree as the newBSTNode, update element count, and then return true
      this->elementCount++;
      return true;
   }
}

return false; // if none of the cases, this means that the insertion was unsuccessful

}
   
   // Description: Retrieves "targetelement" from the binary search tree.
   //           This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the binary search tree is empty.
   // Exception: Throws (propagates) the exception "elementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetelement" is not in the binary search tree.
   // Time efficiency: O(log2 n)
WordPair& BST::retrieve(WordPair & targetElement) const {

   if (elementCount == 0){  
        throw EmptyDataCollectionException("Binary search tree is empty."); //if elementcount is 0, then the tree is emepty, therfore, throw empty exception
   }
	
   WordPair& translated = retrieveR(targetElement, root); //calls the recursive method of retrieve
   return translated; //returns the translated word
}

   // Description: Recursive retrieval from a binary search tree.
   // Exception: Throws the exception "elementDoesNotExistException" 
   //            if "targetelement" is not found in the binary search tree.
WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {
   
   //if current doesn't exist, throw exception 
   if(current == nullptr){ 
      throw ElementDoesNotExistException("element is not here ");
   } 
   if(targetElement == current->element){
      return current->element; //if element is found at the root of the tree, then return the current element
   } //base case
      
	if(current->element > targetElement){ //checks the left-hand side of the tree (left side elements), if there is a left-hand side, recursively search the left-hand side
      if(current->hasLeft()){
        return retrieveR(targetElement, current->left);
      }else{
         throw ElementDoesNotExistException("element is not here "); //throw exception if the element doesn't exist 
      }
     }
      
   if(current->element < targetElement){ //checks the right-hand side of the tree (right side elements), if there is a right-hand side, recursively search the right-hand side
      if(current->hasRight()){
       return retrieveR(targetElement, current->right);
     }else{
       throw ElementDoesNotExistException("element is not here "); //throw exception if the right-hand side doesn't contain the element
     } 
   }  
}
   
   
   // Description: Traverses the binary search tree in order.
   //           This is a wrapper method which calls the recursive traverseInOrderR( ).
   //           The action to be done on each element during the traverse is the function "visit".
   // Precondition: Binary search tree is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //         if the binary search tree is empty.
   // Time efficiency: O(n)     
   void BST::traverseInOrder(void visit(WordPair &)) const {
     
     if (elementCount == 0){  
       throw EmptyDataCollectionException("Binary search tree is empty."); //checks to see if tree is empty, if it is: throw exception
     }
     
     traverseInOrderR(visit, root); //call the recursive function
     return;
   }

   // Description: Recursive in order traversal of a binary search tree.
   //Pre-Condition: The tree isn't empty  
void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 

	if(current->hasLeft()){ //if the tree has a left-side, then traverse the left side
      traverseInOrderR(visit, current->left);
   }

   // visit the current element using a help-function 
   visit(current->element);

   if(current->hasRight()){ //if the tree has a right-side, then traverse the right side
      traverseInOrderR(visit, current->right);
   }
}

void visit(WordPair& w)
{
   cout<<w<<endl; //displays the current WordPair using the overloaded << operator
}

