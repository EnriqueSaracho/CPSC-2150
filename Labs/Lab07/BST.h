#ifndef BST_H
#define BST_H
#include <iostream>
#include "Item.h"

class BST
{
public:
    Item elm;
    BST *left, *right, *parent;

    BST();
    BST(const Item &x, BST *l = nullptr, BST *r = nullptr, BST *p = nullptr);
    bool operator<(const BST &other) const;
};

BST::BST()
{
    left = right = parent = nullptr;
}

BST::BST(const Item &x, BST *l, BST *r, BST *p)
{
    elm = x;
    left = l;
    right = r;
    parent = p;
}

bool BST::operator<(const BST &other) const
{
    return elm.key > other.elm.key;
}

#endif