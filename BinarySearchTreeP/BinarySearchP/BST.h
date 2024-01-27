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
    bool isValidBST(BSTNode *current, int min, int max);
    int kSmallest(BSTNode *current, int &counter, int k);
    int kLargest(BSTNode *current, int &counter, int k);
    int rootNextNext(BSTNode *current);
    unsigned int heightR(BSTNode *current) const;
    int targetHeightR(BSTNode* current, int target);
    int numberOfNodesR(BSTNode* current);

public:
    BST();
    ~BST();
    BST(BST &rhsTree);
    bool insert(int val);
    int getElementCount();
    void traverseInOrder();
    bool isValidBST();
    int kSmallest(int k);
    int kLargest(int k);
    // Finding root's next largest's next largest.
    int rootNextNext();
    unsigned int height() const;
    int targetHeight(int targret);
    int numberOfNodes();
};

#endif