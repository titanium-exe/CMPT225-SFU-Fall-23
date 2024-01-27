#include "BST.h"
#include "BSTNode.h"
#include <iostream>
using namespace std;

int main(){
    BST* bst = new BST();
    
    bst->insert(50);
    bst->insert(20);
    bst->insert(70);
    bst->insert(10);
    bst->insert(60);
    bst->insert(56);
    bst->insert(25);
    bst->insert(65);
    cout<<bst->lca(56,65)<<endl;


}