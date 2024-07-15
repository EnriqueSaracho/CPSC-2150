#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "AVL.h"

void DeleteAVLTree(AVL<int> *tree);               // O(n)
AVL<int> *BuildAVLTree(std::string filename);     // O(nlogn)
void InsertNodeAVL(AVL<int> *&tree, int element); // O(logn)
void DeleteNodeAVL(AVL<int> *&tree, int element); // O(logn)
void PrintAVL(AVL<int> *tree);                    // O(n)
void preOrder(AVL<int> *p);                       // O(n)
void inOrder(AVL<int> *p);                        // O(n)

int main()
{
    std::string filename = "input.txt";
    AVL<int> *avl = BuildAVLTree(filename);
    std::cout << "The height of the AVL tree is: " << avl->height() << std::endl;
    PrintAVL(avl);

    int node;
    std::cout << "Enter value to insert: ";
    std::cin >> node;
    InsertNodeAVL(avl, node);
    std::cout << "The height of the AVL tree is: " << avl->height() << std::endl;
    PrintAVL(avl);

    std::cout << "Enter value to delete: ";
    std::cin >> node;
    DeleteNodeAVL(avl, node);
    std::cout << "The height of the AVL tree is: " << avl->height() << std::endl;
    PrintAVL(avl);

    DeleteAVLTree(avl);
    PrintAVL(avl);

    return 0;
}

void DeleteAVLTree(AVL<int> *tree)
{
    if (tree)
    {
        DeleteAVLTree(tree->left);
        DeleteAVLTree(tree->right);
        delete tree;
    }
}

AVL<int> *BuildAVLTree(std::string filename)
{
    AVL<int> *tree;

    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
    {
        std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl;
        return tree;
    }

    int n, value;
    fin >> n;
    for (int i = 0; i < n; i++) // O(n)
    {
        fin >> value;
        InsertNodeAVL(tree, value); // O(logn)
    }

    return tree;
}

void InsertNodeAVL(AVL<int> *&tree, int element)
{
    // If tree is empty
    if (!tree)
    {
        tree = new AVL<int>(element, nullptr);
        return;
    }

    // Finding place for new node // O(logn)
    AVL<int> *p = tree,
             *prev = p;

    if (element > p->elm)
        p = p->right;
    else
        p = p->left;
    while (!p)
    {
        prev = p;
        if (element > p->elm)
            p = p->right;
        else
            p = p->left;
    }

    // Inserting new node // O(1)
    if (element > prev->elm)
    {
        prev->right = new AVL<int>(element, prev);
        p = prev->right;
    }
    else
    {
        prev->left = new AVL<int>(element, prev);
        p = prev->left;
    }

    // Checking balance factor up to root // O(logn)
    while (p)
    {
        int balance = p->checkBalance(); // O(1)
        if (balance > 1 || balance < -1) // Unbalanced [-2,2]
        {
            p->balanceTree(); // O(1)
            p = p->parent;
        }
        else
        {
            p = p->parent;
            if (p)                 // If it hasn't passed the root
                p->updateHeight(); // O(1)
        }
    }

    // Updating tree root // O(1)
    while (tree->parent)
        tree = tree->parent;
}

void DeleteNodeAVL(AVL<int> *&tree, int element)
{
    if (!tree)
        return;

    // Finding node // O(logn)
    AVL<int> *p = tree,
             *prev,
             *tmp;
    while (p && element != p->elm)
        if (element > p->elm)
            p = p->right;
        else
            p = p->left;

    // If node is not found
    if (!p)
        return;

    // Deleting node // O(1)
    if (!p->left && !p->right) // If node doesn't have any children;
    {
        prev = p->parent;
        if (prev->right == p)
            prev->right = nullptr;
        else
            prev->left = nullptr;
        delete p;
        p = prev;
        p->updateHeight(); // O(1)
    }
    else if (!p->right) // If node doesn't have right child
    {
        tmp = p;
        p = p->left;
        if (tmp->parent)
            if (tmp->parent->left == tmp)
            {
                tmp->parent->left = p;
                p->parent = tmp->parent;
            }
            else
            {
                tmp->parent->right = p;
                p->parent = tmp->parent;
            }
        delete tmp;
        p->parent->updateHeight(); // O(1)
    }
    else if (!p->left) // If node doesn't have left child
    {
        tmp = p;
        p = p->right;
        if (tmp->parent)
            if (tmp->parent->left == tmp)
            {
                tmp->parent->left = p;
                p->parent = tmp->parent;
            }
            else
            {
                tmp->parent->right = p;
                p->parent = tmp->parent;
            }
        delete tmp;
        p->parent->updateHeight(); // O(1)
    }
    else // If node has both children
    {
        tmp = p->left;
        prev = p;
        while (tmp->right)
        {
            prev = tmp;
            tmp = tmp->right;
        }
        p->elm = tmp->elm;
        if (prev == p)
        {
            prev->left = tmp->left;
            tmp->left->parent = prev;
        }
        else
        {
            prev->right = tmp->left;
            tmp->left->parent = prev;
        }
        delete tmp;
        prev->updateHeight(); // O(1)
        p->updateHeight();    // O(1)
    }

    // Checking balance factor up to root
    while (p)
    {
        int balance = p->checkBalance(); // O(1)
        if (balance > 1 || balance < -1) // Unbalanced [-2,2]
        {
            p->balanceTree(); // O(1)
            p = p->parent;
            if (tree->parent)
                tree = tree->parent;
        }
        else
        {
            p = p->parent;
            if (p)                 // If it hasn't passed the root
                p->updateHeight(); // O(1)
        }
    }

    // Updating tree root // O(1)
    while (tree->parent)
        tree = tree->parent;
}

void PrintAVL(AVL<int> *tree)
{
    std::cout << "Pre-order: [ ";
    preOrder(tree); // O(n)
    std::cout << "]" << std::endl;

    std::cout << "In-order: [ ";
    inOrder(tree); // O(n)
    std::cout << "]" << std::endl;
}

void preOrder(AVL<int> *p)
{
    if (p)
    {
        std::cout << p->elm << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void inOrder(AVL<int> *p)
{
    if (p)
    {
        preOrder(p->left);
        std::cout << p->elm << " ";
        preOrder(p->right);
    }
}