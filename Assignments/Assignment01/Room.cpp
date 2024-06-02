#include <iostream>
#include <string>
#include "Room.h"

// Default constructor
Room::Room()
{
    numOfBeds = 1;
}

// Constructor
Room::Room(int beds)
{
    numOfBeds = beds;
}

// Get number of beds
int Room::getNumOfBeds()
{
    return numOfBeds;
}