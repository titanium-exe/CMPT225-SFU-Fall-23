#include "BST.h"
#include <iostream>
using namespace std;

// default constructor
BST::BST() {}

// Copy Constructor
BST::BST(BST &original)
{

    if (original.elementCount == 0)
    {
        this->elementCount = 0;
        this->root = nullptr;
        return;
    }
    this->root = copyTree(original.root);
    this->elementCount = original.elementCount;
}

BSTNode *BST::copyTree(BSTNode *original)
{
    if (original == nullptr)
    {
        cout << "the tree passsed is empty" << endl;
        return nullptr;
    }

    BSTNode *newNode = new BSTNode(original->element);
    newNode->left = copyTree(original->left);
    newNode->right = copyTree(original->right);
    
    return newNode;
}

BST::~BST()
{
}

int BST::getElementCount()
{
    return this->elementCount;
}

bool BST::insert(int val)
{
    BSTNode *newNode = new BSTNode(val);
    if (elementCount == 0)
    {
        this->root = newNode; // we made a root
        this->elementCount++;
        return true;
    }

    if (insertR(this->root, newNode) == true)
    {
        this->elementCount++;
    }
    else if (insertR(this->root, newNode) == false)
    {
        cout << "not inserted" << endl;
    }
    else
    {
        false;
    }
}

bool BST::insertR(BSTNode *current, BSTNode *newNode)
{

    if (current->element > newNode->element)
    {
        if (current->left != nullptr)
        {
            return insertR(current->left, newNode);
        }
        else
        {
            current->left = newNode;

            return true;
        }
    }
    else if (current->element < newNode->element)
    {
        if (current->right != nullptr)
        {
            return insertR(current->right, newNode);
        }
        else
        {
            current->right = newNode;

            return true;
        }
    }
    return false;
}

void BST::traverseInOrder()
{
    if (this->elementCount == 0)
    {
        cout << "Tree is empty " << endl;
        return;
    }

    traverseR(this->root);
}

void BST::traverseR(BSTNode *current)
{
    if (current == nullptr)
    {
        return;
    }

    traverseR(current->left);
    cout << current->element << endl;
    traverseR(current->right);
}

int BST::minValR(BSTNode *current)
{

    if (current->left == nullptr)
    {
        return current->element;
    }
    return minValR(current->left);
}

bool BST::remove(int targetVal)
{
    BSTNode *returnedVal = removeR(this->root, targetVal);
}
// Using successor
BSTNode *BST::removeR(BSTNode *current, int targetVal)
{
    if (current == nullptr)
    {
        return current;
    }

    if (current->element == targetVal)
    {
        // 0 child - Leaf
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            this->elementCount--;
            return nullptr;
        }

        // 1 child

        // Left child
        if (current->left != nullptr && current->right == nullptr)
        {
            BSTNode *temp = current->left;
            delete current;
            this->elementCount--;
            return temp;
        }

        // right child
        if (current->left == nullptr && current->right != nullptr)
        {
            BSTNode *temp = current->right;
            delete current;
            this->elementCount--;
            return temp;
        }

        // 2 child
        if (current->left != nullptr && current->right != nullptr)
        {
            int min = minValR(current->right);
            current->element = min;
            current->right = removeR(current->right, min);
            return current;
        }
    }
    else if (current->element > targetVal)
    {
        if (current->left == nullptr)
        {
            cout << "Node not present" << endl;
        }
        current->left = removeR(current->left, targetVal);
        return current;
    }
    else if (current->element < targetVal)
    {
        if (current->right == nullptr)
        {
            cout << "Node not present" << endl;
        }
        current->right = removeR(current->right, targetVal);
        return current;
    }
}

bool BST::isBST()
{
    if (elementCount == 0)
    {
        return true;
    }
    return isBSTR(this->root, INT_MIN, INT_MAX);
}

bool BST::isBSTR(BSTNode *current, int min, int max)
{

    if (current == nullptr)
    {
        return true;
    }

    if (current->element >= min && current->element <= max)
    {

        bool leftAns = isBSTR(current->left, min, current->element);
        bool rightAns = isBSTR(current->right, current->element, max);
        if (leftAns && rightAns)
        {
            return true;
        }
    }
    else
    {
        false;
    }
}

void BST::findPredeSucc(int key)
{
    findPredeSuccR(this->root, key, -1,-1);
}

void BST::findPredeSuccR(BSTNode *current, int key, int pred, int succ)
{

    if(current == nullptr){
        return;
    }
    if (current->element > key )
    {
        succ = current->element;
        cout<<"now succ is "<<succ<<endl;
        if(current->left ==nullptr){
            return;
        }
        findPredeSuccR(current->left,key, pred, succ);
    }
    if(current->element < key){
        pred = current->element;
        cout<<"now pred is "<<pred<<endl;
        if(current->right == nullptr){
            return;
        }
        findPredeSuccR(current->right,key, pred, succ);
    }
}


int BST::lca(int v1,int v2){
    if(elementCount ==0){
        return -1;
    }

    return lcaR(this->root, v1, v2);

}

int BST::lcaR(BSTNode* current, int v1, int v2){

      if(current == nullptr){
        return -1;
      }
      if(current->element > v1 && current->element > v2){
         return lcaR(current->left, v1, v2);
      }else if(current->element < v1 && current->element < v2){
           return lcaR(current->right, v1, v2);
      }
      else if(current->element > v1 && current->element < v2){
        return current->element;
      }else{
        return current->element;
      }
}


bool BST::isValidBST(){
    if(elementCount == 0 || elementCount == 1){
        return true;
    } 
    else{
        return isValidBST(this->root, INT_MIN, INT_MAX);
    }
    return false;
}

bool BST::isValidBST(BSTNode* current, int min, int max){
    // Base case 
    if(current == nullptr){
        return true;
    }
    if(current->element >= min && current->element <= max){
        // Left's max range becomes right's min
        bool left = isValidBST(current->left, min ,current->element);
        bool right = isValidBST(current->right,current->element,max);
        return left && right;
    }
    else{
        return false;
    }
}