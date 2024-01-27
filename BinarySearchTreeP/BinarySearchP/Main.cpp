#include "BST.h"
#include "BSTNode.h"
#include "UnableToInsertException.h"
#include <iostream>
using namespace std;

int main()
{
    BST *newTree = new BST();

    newTree->insert(45);
    newTree->insert(49);
    newTree->insert(20);
    newTree->insert(35);
    newTree->insert(23);
    newTree->insert(48);
    newTree->insert(47);
    newTree->insert(25);
    newTree->insert(40);
    newTree->insert(10);
    newTree->insert(19);
    newTree->insert(24);
    cout<<newTree->numberOfNodes()<<endl;
    BST*  newTree2 = new BST();
    cout<<newTree2->numberOfNodes()<<endl;
    cout<<newTree2->height()<<endl;
    cout<<newTree->height()<<endl;

}