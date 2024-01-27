/*
 * Dictionary.cpp 
 * 
 * Description: It is a translation tool that translates English to Punjabi.
 * The data Structure it uses it Binary Search Trees via BST.cpp. 
 * It asks the user for input and then displays the translated word if found.
 
 * Author: EKAMLEEN MAAN and  TANVIR SAMRA 
 * Date of last modification: November 2, 2023
 */


#include "Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary() { //Default Constructor
    keyValuePairs  = new BST(); //generates a new BST object
    
}

Dictionary::~Dictionary() { //Destructor
    keyValuePairs->~BST(); //deletes the tree itself
    delete keyValuePairs; //deletes the Dictionary object 
}

unsigned int Dictionary::getElementCount() const {
    return keyValuePairs->getElementCount(); //returns the elementcount
}

void Dictionary::put(WordPair &newElement) { //inserts a new word into tho dictionary (Exception is thrown if the element already is in the dictionary)
    try {
        keyValuePairs->insert(newElement);
    } catch (const ElementAlreadyExistsException &e) {
        throw ElementAlreadyExistsException("Key already exists in the Dictionary.");
    }
}

WordPair& Dictionary::get(WordPair &targetElement) const { //retreaves a word (Exception is thrown if an element isn't found or if the tree is empty)
    try {
        return keyValuePairs->retrieve(targetElement);
    } catch (const ElementDoesNotExistException &e) {
        throw ElementDoesNotExistException("Key not found in the Dictionary.");
    } catch (const EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("Dictionary is empty.");
    }
}

void Dictionary::displayContent(void (*visit)(WordPair &)) const { //displays the content using the recursive method of traverseInOrder method (Exception is thrown if tree is empty)
    try {
        keyValuePairs->traverseInOrder(visit);
       
    } catch (const EmptyDataCollectionException &e) {
        throw EmptyDataCollectionException("Dictionary is empty.");
    }
}
