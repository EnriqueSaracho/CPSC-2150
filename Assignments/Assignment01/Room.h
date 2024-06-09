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

    // TODO: Delete test logs when done testing
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