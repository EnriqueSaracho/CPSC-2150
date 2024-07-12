#ifndef BST_H
#define BST_H

#include <iostream>

template <class T>
class BST
{
public:
    // Variables
    T elm;
    BST *left, *right;

    // Defautl constructor O(1)
    BST();
    // Constructor O(1)
    BST(const T &x, BST<T> *l = nullptr, BST<T> *r = nullptr);
};

// Default constructor
template <class T>
BST<T>::BST()
{
    left = right = nullptr;
}

// Constructor
template <class T>
BST<T>::BST(const T &x, BST<T> *l, BST<T> *r)
{
    elm = x;
    left = l;
    right = r;
}

#endif