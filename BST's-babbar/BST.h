#ifndef BST_H_
#define BST_H_
#include "BSTNode.h"
#include <iostream>

class BST
{
    BSTNode *root;
    int elementCount;
    // these are wrappers methods
    bool insertR(BSTNode *current, BSTNode *newNode);
    void traverseR(BSTNode *current);
    BSTNode *removeR(BSTNode *current, int targetVal);
    BSTNode *copyTree(BSTNode *original);
    int minValR(BSTNode *current);
    bool isBSTR(BSTNode *current, int min, int max);
    void findPredeSuccR(BSTNode *current, int key, int pred , int succ);
    int  lcaR(BSTNode* current, int v1,int v2);
    bool isValidBST(BSTNode* current, int min, int max);

public:
    BST();
    ~BST();
    BST(BST &original);
    int getElementCount();
    bool insert(int value);
    void traverseInOrder();
    bool remove(int targetVal);
    bool isBST();
    void findPredeSucc(int key);
    int lca(int v1,int v2);
    bool isValidBST();
};

#endif