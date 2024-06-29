#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item
{
public:
public:
    int key;
    char value;

    Item();
    Item(char, int);
    // bool operator<(const Item &other) const;
};

Item::Item()
{
    value = '\0';
    key = 1;
}

Item::Item(char v, int k)
{
    value = v;
    key = k;
}

// bool Item::operator<(const Item &other) const
// {
//     return key > other.key;
// }

#endif