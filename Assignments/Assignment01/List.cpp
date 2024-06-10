#include <iostream>
#include "List.h"

// Constructor
List::List()
{
    h = nullptr;
    t = nullptr;
}

// Destructor
List::~List()
{
    while (!isEmpty())
    {
        Node *temp = h;
        if (!h->next)
        {
            h = nullptr;
            t = nullptr;
        }
        else
        {
            h = h->next;
            h->prev = nullptr;
        }
        delete temp;
        size--;
    }
}

// Check if the list is empty
bool List::isEmpty()
{
    return (!h);
}

// Get size of list
int List::getSize()
{
    return size;
}

// Add room to top of list
void List::insertTop(int index)
{
    if (isEmpty())
    {
        h = new Node{index, nullptr, nullptr};
        t = h;
    }
    else
    {
        h = new Node{index, h, nullptr};
        h->next->prev = h;
    }
    size++;
}

// Add room to bottom of list
void List::insertBottom(int index)
{
    if (isEmpty())
    {
        h = new Node{index, nullptr, nullptr};
        t = h;
    }
    else
    {
        t = new Node{index, nullptr, t};
        t->prev->next = t;
    }
    size++;
}

// Return and eliminate room from top of list
int List::popTop()
{
    if (isEmpty())
        return -1;

    int room = h->index;
    Node *temp = h;
    if (!h->next)
    {
        h = nullptr;
        t = nullptr;
    }
    else
    {
        h = h->next;
        h->prev = nullptr;
    }
    delete temp;
    size--;
    return room;
}
