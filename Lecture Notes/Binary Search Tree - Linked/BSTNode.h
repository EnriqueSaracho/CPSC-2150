#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>

template <class T>
class BSTNode
{
public:
    BSTNode()
    {
        left = right = nullptr;
    }
    BSTNode(const T &e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr)
    {
        elm = e;
        left = l;
        right = r;
    }
    T elm;
    BSTNode<T> *left, *right;
};

#endif