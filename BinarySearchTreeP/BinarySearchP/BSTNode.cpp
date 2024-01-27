#include "BSTNode.h"
#include <iostream>
using namespace std;

BSTNode::BSTNode(int val){
    this->element = val;
    this->left = nullptr;
    this->right = nullptr;
}

bool BSTNode::hasLeaf(){
    return this->left == nullptr && this->right == nullptr;
}

bool BSTNode::hasLeft(){
    return this->left != nullptr;
}

bool BSTNode::hasRight(){
    return this->right != nullptr;
}