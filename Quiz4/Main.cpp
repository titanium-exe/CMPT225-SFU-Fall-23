#include "BST.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include <iostream>
using namespace std;

int main(){
    BST* bst = new BST();
    
    bst->insert(11);
    bst->insert(7);
    bst->insert(13);
    bst->insert(9);
    bst->insert(1);
    bst->insert(15);
    bst->insert(19);
    cout<<bst->targetCount(7)<<endl;
    bst->printInOrder();
}