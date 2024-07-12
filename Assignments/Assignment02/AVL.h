#ifndef AVL_H
#define AVL_H
#include "BST.h"

template <class T>
class AVL : public BST
{
public:
    int height;

    AVL();
};

template <class T>
AVL<T>::AVL()
{
}

#endif