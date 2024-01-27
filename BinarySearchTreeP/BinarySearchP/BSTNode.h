#ifndef BSTNODE_H_
#define BSTNODE_H_

class BSTNode{
    public:
    int element;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val);
    bool hasLeaf();
    bool hasRight();
    bool hasLeft();
};


#endif