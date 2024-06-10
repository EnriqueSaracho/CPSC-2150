#include <iostream>
#include <string>
#include <cstring>
#include "Room.h"
#include "Customer.h"

// Default constructor
Room::Room()
{
    customerId = "000000";
    numOfBeds = 1;

    checkInDate = new tm;
    std::memset(checkInDate, 0, sizeof(tm));
    checkOutDate = new tm;
    std::memset(checkOutDate, 0, sizeof(tm));
}

// Constructor
Room::Room(int beds)
{
    customerId = "000000";

    if (beds > 0 && beds < 4)
        numOfBeds = beds;
    else
        numOfBeds = 1;

    checkInDate = new tm;
    std::memset(checkInDate, 0, sizeof(tm));
    checkOutDate = new tm;
    std::memset(checkOutDate, 0, sizeof(tm));
}

// Copy constructor
Room::Room(Room &other)
{
    customerId = other.customerId;
    numOfBeds = other.numOfBeds;

    checkInDate = new tm(*other.checkInDate);
    checkOutDate = new tm(*other.checkOutDate);
}

// Destructor
Room::~Room()
{
    delete checkInDate;
    delete checkOutDate;
}

// Room is assigned to customer
void Room::assignRoom(Customer customer, const tm *date, int stay)
{
    customerId = customer.getId();
    std::memcpy(checkInDate, date, sizeof(tm));

    time_t checkInTime = mktime(checkInDate);
    checkInTime += stay * 24 * 60 * 60;
    std::memcpy(checkOutDate, localtime(&checkInTime), sizeof(tm));

    occupied = true;
}

// Customer checks out and leaves room
void Room::freeRoom()
{
    occupied = false;
}

// Indicate if room is occupied
bool Room::isOccupied()
{
    return occupied;
}

// Get check out date
tm *Room::getCheckoutDate()
{
    return checkOutDate;
}

// Display number of beds
// Display customer ID
void Room::printCustomerId()
{
    std::cout << customerId << std::endl;
}
void Room::printNumOfBeds()
{
    std::cout << numOfBeds << std::endl;
}
// Display checkInDate
void Room::printCheckInDate()
{
    std::cout << asctime(checkInDate);
}
// Display checkOutDate
void Room::printCheckOutDate()
{
    std::cout << asctime(checkOutDate);
}
