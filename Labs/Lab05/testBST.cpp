#include <iostream>
#include <vector>
#include "BST.h"

int getInput();
std::vector<int> genData(const int &);
void printList(std::vector<int>);
BST<int> *makeBST(std::vector<int>);
void printBT(BST<int> *);
// int height(BST<int> *);
// int height(BST<int> *, int);

int main()
{
    unsigned int n1;
    n1 = getInput();

    std::vector<int> list1 = genData(n1);

    std::cout << "The List: ";
    printList(list1);

    BST<int> *bst1 = makeBST(list1);
    printBT(bst1);

    // std::cout << "The height of bst1 is " << height(bst1) << std::endl;

    return 0;
}

// O(1)
int getInput()
{
    unsigned int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;
    return n;
}

// O(n)
std::vector<int> genData(const int &n)
{
    srand(time(0));
    std::vector<int> list(n);

    for (int i = 0; i < n; i++)
        list[i] = rand() % (2 * n + 1) - n;

    return list;
}

// O(n)
void printList(std::vector<int> list)
{
    int i = 0;
    std::cout << "[ ";
    for (; i < list.size() - 1; i++)
        std::cout << list[i] << ", ";
    std::cout << list[i] << " ]" << std::endl;
}

// O(nlogn)
BST<int> *makeBST(std::vector<int> list)
{
    BST<int> *root = nullptr,
             *p,
             *prev;
    // O(n)
    for (int x : list)
    {
        if (!root)
            root = new BST<int>(x);
        else
        {
            p = root;
            // O(logn)
            while (p != nullptr)
            {
                prev = p;
                if (x <= p->elm)
                    p = p->left;
                else
                    p = p->right;
            }
            if (x <= prev->elm)
                prev->left = new BST<int>(x);
            else
                prev->right = new BST<int>(x);
        }
    }
    return root;
}

// O(n)
void printBT(BST<int> *p)
{
    if (p != nullptr)
    {
        printBT(p->left);
        std::cout << p->elm << " ";
        printBT(p->right);
    }
}

// //
// int height(BST<int> *p)
// {
//     return height(p, 0);
// }
// int height(BST<int> *p, int sum)
// {
//     int x, y;
//     if (p != nullptr)
//     {
//         x = height(p->left, sum++);
//         y = height(p->right, sum++);
//     }
//     return sum;
// }