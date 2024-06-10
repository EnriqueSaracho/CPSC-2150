#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"

class List
{
private:
    Node *h;
    Node *t;
    int size = 0;

public:
    // Constructor
    List();
    // Destructor
    ~List();

    // Check if the list is empty
    bool isEmpty();
    // Get size of list
    int getSize();
    // Add room to top of list
    void insertTop(int);
    // Add room to bottom of list
    void insertBottom(int);
    // Return and eliminate room from top of list
    int popTop();
};

#endif