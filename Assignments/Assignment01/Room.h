#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room
{
private:
    std::string customer;     // Customer who's currently occupying room
    std::string checkInDate;  // Date customer gets the room
    std::string checkOutDate; // Date customer is leaving the room
    int numOfBeds;            // Number of beds in the room

public:
    // Default constructor
    Room();
    // Constructor
    Room(int beds);
    // Get number of beds
    int getNumOfBeds();
};

#endif