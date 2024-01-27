#include "BST.h"
#include <iostream>

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
        throw UnableToInsertException("No more Heap memory");
    }
    if (elementCount == 0)
    {
        this->root = newNode;
        this->elementCount++;
        return true;
    }
    else
    {
        try
        {
            if (insertR(this->root, newNode))
            {
                this->elementCount++;
                return true;
            }
        }
        catch (UnableToInsertException &e)
        {
            throw UnableToInsertException("im not able to insert");
        }
    }
    return false;
}

// this is a wrapper function
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
            return true;
        }
    }
    else if (newNode->element > current->element)
    {
        if (current->hasRight())
        {
            return insertR(current->right, newNode);
        }
        else
        {
            current->right = newNode;
            return true;
        }
    }
    else
    {
        return false;
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
        cout << "nullptr" << endl;
        return;
    }
    traverseInOrder(this->root);
}

void BST::traverseInOrder(BSTNode *current)
{
    if (current == nullptr)
    {
        return;
    }
    traverseInOrder(current->left);
    cout << current->element << " ";
    traverseInOrder(current->right);
}

bool BST::isValidBST()
{
    if (elementCount == 0 || elementCount == 1)
    {
        return true;
    }
    else
    {
        return isValidBST(this->root, INT_MIN, INT_MAX);
    }
    return false;
}

bool BST::isValidBST(BSTNode *current, int min, int max)
{
    // Base case
    if (current == nullptr)
    {
        return true;
    }
    if (current->element >= min && current->element <= max)
    {
        // Left's max range becomes right's min
        bool left = isValidBST(current->left, min, current->element);
        bool right = isValidBST(current->right, current->element, max);
        return left && right;
    }
    else
    {
        return false;
    }
}

int BST::kSmallest(int k)
{
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
        return -1;
    }
    int right = kLargest(current->right, counter, k);
    if (right != -1)
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

int BST::rootNextNext()
{
    if (elementCount == 0)
    {
        return -1;
    }
    if (elementCount == 1)
    {
        return this->root->element;
    }
    return rootNextNext(this->root->right);
}
// i'll pass right node in the first call
int BST::rootNextNext(BSTNode *current)
{
    // if there are no elements in the right tree of the root
    if (current == nullptr)
    {
        return root->element;
    }
    if (current->left == nullptr && current->right == nullptr)
    {
        return current->element;
    }
    if (current->left == nullptr && current->right != nullptr)
    {
        return current->right->element;
    }
    if (current->left->left == nullptr)
    {
        return current->element;
    }
    return rootNextNext(current->left);
}

unsigned int BST::height() const
{

    if (root == nullptr)
    {
        return 0;
    }
    unsigned int ans = heightR(root);
    return ans;
}

unsigned int BST::heightR(BSTNode *current) const
{

    if (current == nullptr)
    {
        return 0;
    }

    unsigned int ansLeft = 1 + heightR(current->left);
    unsigned int ansRight = 1 + heightR(current->right);

    if (ansRight >= ansLeft)
    {
        return ansRight;
    }
    else
    {
        return ansLeft;
    }
}

int BST::targetHeight(int target)
{

    return targetHeightR(this->root, target);
}

int BST::targetHeightR(BSTNode *current, int target)
{
    if (current->element == target)
    {
        return 1;
    }
    if (current->element > target)
    {
        if (current->hasLeft())
        {
            return 1 + targetHeightR(current->left, target);
        }
        else
        {
            throw UnableToInsertException("Element not found");
        }
    }
    else
    {
        if (current->hasRight())
        {
            return 1 + targetHeightR(current->right, target);
        }
        else
        {
            throw UnableToInsertException("Element not found");
        }
    }
    return -1;
}

int BST::numberOfNodes()
{
    if(root == nullptr){
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
    
    int left =   numberOfNodesR(current->left);
    int right =  numberOfNodesR(current->right);
    return  1 + left + right;
   
}