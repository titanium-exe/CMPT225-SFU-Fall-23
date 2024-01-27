#include "BST.h"
#include <iostream>
#include <cmath>
using namespace std;

BST::BST()
{
    this->root = nullptr;
    this->elementCount = 0;
}

BST::~BST()
{
    if (root != nullptr)
    {
        destroyR(this->root);
        this->root = nullptr;
    }
    return;
}

// we will do the preOrder Traversal
BST::BST(BST &rhsTree)
{
    if (rhsTree.elementCount == 0)
    {
        this->root = nullptr;
        this->elementCount = 0;
        return;
    }
    copyTree(rhsTree.root);
}

void BST::copyTree(BSTNode *RHScurrent)
{
    if (RHScurrent != nullptr)
    {
        this->insert(RHScurrent->element);
        copyTree(RHScurrent->left);
        copyTree(RHScurrent->right);
    }
    return;
}

// we will destroy the tree in PostOrder
void BST::destroyR(BSTNode *current)
{

    if (current->hasLeft())
    {
        destroyR(current->left);
    }
    if (current->hasRight())
    {
        destroyR(current->right);
    }
    BSTNode *toBeRem = current;
    cout << "deleted NOde: " << current->element << endl;
    delete toBeRem;
    current = nullptr;
    this->elementCount--;
    return;
}

bool BST::insert(int val)
{
    BSTNode *newNode = new BSTNode(val);
    if (newNode == nullptr)
    {
        // throw exception
        return false;
    }
    if (elementCount == 0)
    {
        this->root = newNode;
        this->elementCount++;
        return true;
    }
    insertR(this->root, newNode);
}

bool BST::insertR(BSTNode *current, BSTNode *newNode)
{

    if (newNode->element < current->element)
    {
        if (current->hasLeft())
        {
            return insertR(current->left, newNode);
        }
        else
        {
            current->left = newNode;
            this->elementCount++;
            return true;
        }
    }
    if (newNode->element >= current->element)
    {
        if (current->hasRight())
        {
            return insertR(current->right, newNode);
        }
        else
        {
            current->right = newNode;
            this->elementCount++;
            return true;
        }
    }

    return false;
}

int BST::getElementCount()
{
    return this->elementCount;
}

void BST::traverseInOrder()
{
    if (elementCount == 0)
    {
        cout << "tree is empty" << endl;
        return;
    }
    else
    {
        traverseInOrder(this->root);
    }
}

void BST::traverseInOrder(BSTNode *current)
{
    if (current == nullptr)
    {
        return;
    }

    traverseInOrder(current->left);
    cout << current->element << "  ";
    traverseInOrder(current->right);
}

int BST::kSmallest(int k)
{
    if (elementCount == 0)
    {
        return 0;
    }
    int counter = 0;
    return kSmallest(this->root, counter, k);
}

int BST::kSmallest(BSTNode *current, int &counter, int k)
{
    if (current == nullptr)
    {
        return -1;
    }

    int left = kSmallest(current->left, counter, k);
    if (left != -1)
    {
        return left;
    }
    counter++;
    if (counter == k)
    {
        return current->element;
    }
    return kSmallest(current->right, counter, k);
}

int BST::kLargest(int k)
{
    int counter = 0;
    return kLargest(this->root, counter, k);
}

int BST::kLargest(BSTNode *current, int &counter, int k)
{
    if (current == nullptr)
    {
        return INT_MAX;
    }

    int right = kLargest(current->right, counter, k);
    if (right != INT_MAX)
    {
        return right;
    }
    counter++;
    if (counter == k)
    {
        return current->element;
    }

    return kLargest(current->left, counter, k);
}

// bool BST::isBalanced() { return isBalanced(this->root); }

// bool BST::isBalanced(BSTNode *current)
// {
//     if (current == nullptr)
//     {
//         return true;
//     }
//     int heightDiff = abs( heightNode(current) - heightNode(current));
//     return (heightDiff <= 1) && isBalanced(current->left) && isBalanced(current->right);
// }

// int BST::heightNode(BSTNode* current){
//     if(current == nullptr){
//         return 0;
//     }
//     int left = 1 + heightNode(current->left);
//     int right = 1 + heightNode(current->right);
//     if(left>=right){
//         return left;
//     }else{
//         return right;
//     }
//     return INT_MAX;
// }

int BST::targetHeight(int target)
{
    if (elementCount == 0)
    {
        return -1;
    }
    return targetHeightR(this->root, target);
}

int BST::targetHeightR(BSTNode *current, int target)
{
    // when we havn't found the targetelement - we can't help other than termianting function.
    if (current == nullptr)
    {
        return INT_MAX;
    }
    // base case
    if (current->element == target)
    {
        return 1;
    }
    if (current->element > target)
    {
        return 1 + targetHeightR(current->left, target);
    }
    else
    {
        return 1 + targetHeightR(current->right, target);
    }
    return -1;
}

int BST::numberOfNodes()
{
    if (root == nullptr)
    {
        return 0;
    }
    return numberOfNodesR(this->root);
}

int BST::numberOfNodesR(BSTNode *current)
{
    if (current == nullptr)
    {
        return 0;
    }
    int left = numberOfNodesR(current->left);
    int right = numberOfNodesR(current->right);

    return left + right + 1;
}

int BST::rootKsmallest(int k)
{
    int counter = 0;
    return rootKsmallest(this->root->left, k, counter);
}

int BST::rootKsmallest(BSTNode *current, int k, int &counter)
{   
    if(current == nullptr){
        return -1;
    }

    int right = rootKsmallest(current->right, k, counter);
    if(right != -1){
        return right;
    }
    counter++;
    if (counter == k)
    {
        return current->element;
    }
    return rootKsmallest(current->left, k, counter);
}

unsigned int BST::height() const {
    return heightR(this->root);
}

unsigned int BST::heightR(BSTNode* current)const{
    if(current == nullptr){
        return 0;
    }
    int left = 1 + heightR(current->left);
    int right = 1 + heightR(current->right);
    if(left<=right){
        return right;
    }else{
        return left;
    }
    return 0;
}

