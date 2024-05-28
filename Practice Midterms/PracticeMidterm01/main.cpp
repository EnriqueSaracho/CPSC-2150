#include <iostream>
#include "Node.h"

int max(const Node *t);
void print(Node *h);

int main()
{
    Node *p = new Node{3, new Node{5, new Node{2, new Node{7, new Node{4, nullptr}}}}};
    // p -> 3 -> 5 -> 2 -> 7 -> 4 -> nullptr
    print(p);
    std::cout << "max: " << max(p) << std::endl;

    Node *q = nullptr;
    print(q);
    std::cout << "max: " << max(q) << std::endl;
}

void print(Node *h)
{
    for (; h; h = h->next)
    {
        std::cout << h->element << "->";
    }
    std::cout << "nullptr" << std::endl;
}

int max(const Node *t)
{
    if (!t)
        return -1;

    int next = max(t->next);
    if (next > t->element)
        return next;
    return t->element;
}