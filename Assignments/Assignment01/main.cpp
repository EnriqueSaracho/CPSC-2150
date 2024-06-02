#include <iostream>
#include <fstream>
#include <string>
#include "Room.h"
#include "Customer.h"

const int ONE_BED_RMS = 100;
const int TWO_BED_RMS = 50;
const int THREE_BED_RMS = 30;
const int TOTAL_RMS = ONE_BED_RMS + TWO_BED_RMS + THREE_BED_RMS;

void initRooms(Room rooms[]);

int main()
{
    // Initializing hotel rooms list
    Room rooms[TOTAL_RMS];
    initRooms(rooms);
    for (int i = 0; i < TOTAL_RMS; i++)
    {
        std::cout << "Room " << i + 1 << " has " << rooms[i].getNumOfBeds() << " bed(s)." << std::endl;
    }

    // Reading customer data
    std::ifstream fin;
    fin.open("Customers.txt");

    if (!fin.is_open())
    {
        std::cerr << "Error: Unable to open file 'Customers.txt'" << std::endl;
        return 1;
    }
    // Skipping headers line
    std::string line;
    std::getline(fin, line);
}

void initRooms(Room rooms[])
{
    int i = 0;

    for (; i < ONE_BED_RMS; i++)
    {
        rooms[i] = Room(1);
    }
    for (; i < ONE_BED_RMS + TWO_BED_RMS; i++)
    {
        rooms[i] = Room(2);
    }
    for (; i < TOTAL_RMS; i++)
    {
        rooms[i] = Room(3);
    }
}

// std::string checkInDate;
// fin >> checkInDate;

// std::cout << checkInDate << std::endl;