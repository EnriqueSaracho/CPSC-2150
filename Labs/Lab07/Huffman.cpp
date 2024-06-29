#include <iostream>
#include <vector>
#include <queue>
#include "BST.h"
#include "Item.h"

std::string getInput();                                         // O(1)
BST makeHuffmanTree(std::string &);                             // O(n^2)
void computeFrequency(std::vector<Item> &, std::string &, int); // O(n^2)
bool findChar(std::vector<Item> &, char);                       // O(n)
void printTrie(BST &);                                          // O(n)
void inOrderPrint(BST *);                                       // O(n)
void preOrderPrint(BST *);                                      // O(n)

int main()
{
    std::string input = getInput();
    BST trie = makeHuffmanTree(input);
    printTrie(trie);

    return 0;
}

std::string getInput()
{
    std::string input;
    std::cout << "Enter a word to encode: ";
    std::cin >> input;
    return input;
}

BST makeHuffmanTree(std::string &input)
{
    int n = input.length();
    std::vector<Item> d;

    computeFrequency(d, input, n);

    std::priority_queue<BST> Q;

    for (Item c : d)
    {
        BST T(c);
        Q.push(T);
    }

    while (Q.size() > 1)
    {
        int f1 = Q.top().elm.key;
        BST T1 = Q.top();
        Q.pop();
        int f2 = Q.top().elm.key;
        BST T2 = Q.top();
        Q.pop();
        Item item('0', T1.elm.key + T2.elm.key);

        BST T(item, new BST(T1), new BST(T2));
        Q.push(T);
    }

    return Q.top();
}

void computeFrequency(std::vector<Item> &d, std::string &input, int n)
{
    for (int i = 0; i < n; i++)
        if (!findChar(d, input[i]))
        {
            d.push_back(Item(input[i], 1));
        }
    return;
}

bool findChar(std::vector<Item> &f, char c)
{
    int i = 0;
    for (; i < f.size(); i++)
        if (f[i].value == c)
        {
            f[i].key++;
            return true;
        }
    return false;
}

void printTrie(BST &trie)
{
    std::cout << "In-Order Traversal: ";
    inOrderPrint(&trie);
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal: ";
    preOrderPrint(&trie);
    std::cout << std::endl;
}

void inOrderPrint(BST *node)
{
    if (node == nullptr)
        return;
    inOrderPrint(node->left);
    std::cout << node->elm.value << " ";
    inOrderPrint(node->right);
}

void preOrderPrint(BST *node)
{
    if (node == nullptr)
        return;
    std::cout << node->elm.value << " ";
    preOrderPrint(node->left);
    preOrderPrint(node->right);
}