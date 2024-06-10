#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <ctime>
#include "Customer.h"

class Room
{
private:
    std::string customerId; // Customer who's currently occupying room
    tm *checkInDate;        // Date customer gets the room
    tm *checkOutDate;       // Date customer is leaving the room
    int numOfBeds;          // Number of beds in the room
    bool occupied;          // Indicates if the room is occupied or not

public:
    // Default constructor
    Room();
    // Constructor
    Room(int);
    // Copy constructor
    Room(Room &);
    // Destructor
    ~Room();

    // Room is assigned to customer
    void assignRoom(Customer, const tm *, int);
    // Customer checks out and leaves room
    void freeRoom();
    // Returns true if the room is ocuppied
    bool isOccupied();
    // Get check out date
    tm *getCheckoutDate();

    // Display number of beds
    void printCustomerId();
    // Display checkInDate
    void printNumOfBeds();
    // Display customer ID
    void printCheckInDate();
    // Display checkOutDate
    void printCheckOutDate();
};

#endif