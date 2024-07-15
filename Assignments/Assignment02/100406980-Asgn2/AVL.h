#ifndef AVL_H
#define AVL_H
#include "BST.h"

template <class T>
class AVL : public BST<T>
{
public:
    // Variables
    // T elm (inherited)
    AVL<T> *left, *right, *parent;
    int hLeft, hRight; // highest amount of children on each direction

    // Methods
    AVL();                     // O(1)
    AVL(T element, AVL<T> *p); // O(1)
    int checkBalance();        // O(1)
    void updateHeight();       // O(1)
    void balanceTree();        // O(1)
    void rightLeftRotation();  // O(1)
    void leftRightRotation();  // O(1)
    void leftRotation();       // O(1)
    void rightRotation();      // O(n)
    int height();              // O(1)
};

template <class T>
AVL<T>::AVL()
{
    this->elm = 0;
    left = right = parent = nullptr;
    hLeft = hRight = 0;
}

template <class T>
AVL<T>::AVL(T element, AVL<T> *p)
{
    this->elm = element;
    parent = p;
    hLeft = hRight = 0;
    left = right = nullptr;
}

template <class T>
int AVL<T>::checkBalance()
{
    return hRight - hLeft;
}

template <class T>
void AVL<T>::updateHeight()
{
    if (left)
        hLeft = left->hLeft > left->hRight ? left->hLeft + 1 : left->hRight + 1;
    else
        hLeft = 0;

    if (right)
        hRight = right->hLeft > right->hRight ? right->hLeft + 1 : right->hRight + 1;
    else
        hRight = 0;
}

template <class T>
void AVL<T>::balanceTree()
{
    if (checkBalance() > 0)            // [2]
        if (right->checkBalance() < 0) // right child balance [-1]
            rightLeftRotation();
        else // right child balance [1]
            leftRotation();
    else                              // [-2]
        if (left->checkBalance() > 0) // [1]
            leftRightRotation();
        else // [-1]
            rightRotation();
}

template <class T>
void AVL<T>::rightLeftRotation()
{
    right->rightRotation();
    leftRotation();
}

template <class T>
void AVL<T>::leftRightRotation()
{
    left->leftRotation();
    rightRotation();
}

template <class T>
void AVL<T>::leftRotation()
{
    AVL<T> *a = this,
           *b = a->right,
           *c = b->left,
           *d = a->parent;

    a->parent = b;
    b->left = a;

    a->right = c;
    if (c)
        c->parent = a;

    if (d)
        if (d->right == a)
            d->right = b;
        else
            d->left = b;
    b->parent = d;

    a->updateHeight();
    b->updateHeight();
}

template <class T>
void AVL<T>::rightRotation()
{
    AVL<T> *a = this,
           *b = left,
           *c = b->right,
           *d = a->parent;

    a->parent = b;
    b->right = a;

    a->left = c;
    if (c)
        c->parent = a;

    if (d)
        if (d->right == a)
            d->right = b;
        else
            d->left = b;
    b->parent = d;

    a->updateHeight();
    b->updateHeight();
}

template <class T>
int AVL<T>::height()
{
    int height = hLeft > hRight ? hLeft : hRight;
    return height;
}

#endif