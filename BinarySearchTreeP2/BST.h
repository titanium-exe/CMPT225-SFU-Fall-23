#ifndef BST_H_
#define BST_H_
#include "BSTNode.h"
#include "UnableToInsertException.h"

class BST
{
    BSTNode *root;
    int elementCount;
    bool insertR(BSTNode *current, BSTNode *newNode);
    void traverseInOrder(BSTNode *current);
    void destroyR(BSTNode *current);
    void copyTree(BSTNode *RHScurrent);

    int kSmallest(BSTNode *current, int &counter, int k);
    int kLargest(BSTNode *current, int &counter, int k);
    int rootKsmallest(BSTNode *current, int k, int &counter);
    unsigned int heightR(BSTNode *current) const;
    int targetHeightR(BSTNode *current, int target);
    int numberOfNodesR(BSTNode *current);
    bool isBalanced(BSTNode *current);
    int heightNode(BSTNode* current);

public:
    BST();
    ~BST();
    BST(BST &rhsTree);
    bool insert(int val);
    int getElementCount();
    void traverseInOrder();
    int kSmallest(int k);
    int kLargest(int k);
    int rootKsmallest(int k);
    unsigned int height() const;
    int targetHeight(int targret);
    int numberOfNodes();
    bool isBalanced();
};

#endif