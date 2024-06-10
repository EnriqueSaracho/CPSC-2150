#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "Room.h"
#include "Customer.h"
#include "List.h"

bool compareDates(const tm *, int, int, int);
void initializeRooms(Room[], int, int, int);
int updateAvRoom(int, Room[], int, int);

int main()
{
    // Initializing date tracker
    tm *date = new tm;
    std::memset(date, 0, sizeof(tm));

    // Initializing dynamic array of rooms
    int oneBedRooms = 100,
        twoBedRooms = 50,
        threeBedRooms = 30,
        totalRooms = oneBedRooms + twoBedRooms + threeBedRooms;
    Room *rooms = new Room[totalRooms];
    initializeRooms(rooms, oneBedRooms, twoBedRooms, threeBedRooms);

    // Creating linked list for tracking occupied rooms
    List occupiedRooms;

    // Creating variables to store the index of the next available room
    int avOneBed = 0,
        avTwoBed = oneBedRooms,
        avThreeBed = oneBedRooms + twoBedRooms;

    // Start reading data from file
    std::ifstream fin;
    fin.open("Customers.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error: Unable to open file 'Customers.txt'" << std::endl;
        return 1;
    }

    // Creating output file
    std::ofstream fout;
    fout.open("Log.txt");
    if (!fout.is_open())
    {
        std::cerr << "Error: Unable to open file 'Log.txt'" << std::endl;
        return 1;
    }
    fout << std::endl;

    // Declaring variables for daily log
    int served = 0,
        refused = 0,
        checkedOut = 0,
        freedRooms = 0;

    // Declaring variables for individual record
    std::string line;
    char delimiter;
    int day, month, year;
    std::string customerId;
    int beds, stay;

    // Skipping headers line
    std::getline(fin, line);

    // Reading each line/customer individually
    while (std::getline(fin, line))
    {
        std::stringstream ss(line);

        // Reading date and checking if it's a different day from past record
        ss >> day >> delimiter >> month >> delimiter >> year;
        if (!compareDates(date, day, month, year))
        {
            // Case when it's a different day
            // Go through list finding and updating rooms that are checking out that day
            for (int i = 0; i < occupiedRooms.getSize(); i++)
            {
                // Get room from top of list
                int room = occupiedRooms.popTop();
                // Check if its checkout date is the same as the current date
                if (compareDates(rooms[room].getCheckoutDate(), day, month, year))
                {
                    // Free room
                    rooms[room].freeRoom();
                    freedRooms++;
                    // Check if the room can be the next available room
                    if (avThreeBed == -1 && room >= oneBedRooms + twoBedRooms && room < totalRooms)
                        avThreeBed = room;
                    else if (avTwoBed == -1 && room >= oneBedRooms && room < oneBedRooms + twoBedRooms)
                        avTwoBed = room;
                    else if (avOneBed == -1 && room > -1 && room < oneBedRooms)
                        avOneBed = room;
                    checkedOut++;
                }
                else
                {
                    // Add room back to 'occupiedRooms' list
                    occupiedRooms.insertBottom(room);
                }
            }

            // Display daily log
            fout << "Date: " << day << "/" << month << "/" << year << std::endl;
            fout << "Number of customers served:         " << served << std::endl;
            fout << "Number of customers refused:        " << refused << std::endl;
            fout << "Number of customers checked out:    " << checkedOut << std::endl;
            fout << "Number of rooms freed:              " << freedRooms << std::endl;
            fout << std::endl;

            // Update current date's values
            date->tm_mday = day;
            date->tm_mon = month - 1;
            date->tm_year = year - 1900;
            served = refused = checkedOut = freedRooms = 0;
        }

        // Read customer info
        ss.ignore(2);
        std::getline(ss, customerId, ',');
        ss.ignore(1);
        ss >> beds;
        ss.ignore(2);
        ss >> stay;
        Customer customer(beds, customerId); // Create customer
        List customerRooms;                  // temporary current customer's list

        // Find rooms for customer
        while (beds > 0)
        {
            // Iterate while giving a room to the customer until his number of requested beds is fulfilled
            if (beds > 2 && avThreeBed != -1)
            {
                // Assign room number 'avThreeBed'
                rooms[avThreeBed].assignRoom(customer, date, stay);
                // Add room to temporary current customer's list
                customerRooms.insertTop(avThreeBed);
                // Add room to ocuppied rooms list
                occupiedRooms.insertTop(avThreeBed);
                // Update value of 'avThreeBed'
                avThreeBed = updateAvRoom(avThreeBed, rooms, oneBedRooms + twoBedRooms, totalRooms);
                // Update 'beds' value
                beds -= 3;
            }
            else if (beds > 1 && avTwoBed != -1)
            {
                // Assign 'avTwoBed'
                rooms[avTwoBed].assignRoom(customer, date, stay);
                // Add room to current customer's list
                customerRooms.insertTop(avTwoBed);
                // Add room to ocuppied rooms list
                occupiedRooms.insertTop(avTwoBed);
                // Update 'avTwoBed'
                avTwoBed = updateAvRoom(avTwoBed, rooms, oneBedRooms, oneBedRooms + twoBedRooms);
                // Update 'beds' value
                beds -= 2;
            }
            else if (avOneBed != -1)
            {
                // Assign 'avOneBed'
                rooms[avOneBed].assignRoom(customer, date, stay);
                // Add room to current customer's list
                customerRooms.insertTop(avOneBed);
                // Add room to ocuppied rooms list
                occupiedRooms.insertTop(avOneBed);
                // Update 'avOneBed'
                avOneBed = updateAvRoom(avOneBed, rooms, 0, oneBedRooms);
                // Update 'beds' value
                beds -= 1;
            }
            else
            {
                std::cout << "Sorry, there is no more available rooms" << std::endl;
                // Freeing previously assigned rooms to this customer
                while (!customerRooms.isEmpty())
                {
                    // Remove room from current customer's list of rooms and occupied rooms list
                    int room = customerRooms.popTop();
                    occupiedRooms.popTop();
                    // Free room
                    rooms[room].freeRoom();
                    freedRooms++;
                    // Check if the room can be the next available room
                    if (avThreeBed == -1 && room >= oneBedRooms + twoBedRooms && room < totalRooms)
                        avThreeBed = room;
                    else if (avTwoBed == -1 && room >= oneBedRooms && room < oneBedRooms + twoBedRooms)
                        avTwoBed = room;
                    else if (avOneBed == -1 && room > -1 && room < oneBedRooms)
                        avOneBed = room;
                }
                break;
            }
        }
        if (customerRooms.isEmpty())
            refused++;
        else
            served++;
    }

    return 0;
}

bool compareDates(const tm *date, int day, int month, int year)
{
    return (date->tm_year + 1900 == year &&
            date->tm_mon + 1 == month &&
            date->tm_mday == day);
}

void initializeRooms(Room rooms[], int oneBedRooms, int twoBedRooms, int threeBedRooms)
{
    int i = 0;
    for (; i < oneBedRooms; i++)
    {
        Room room(1);
        rooms[i] = room;
    }
    for (; i < oneBedRooms + twoBedRooms; i++)
    {
        Room room(2);
        rooms[i] = room;
    }
    for (; i < oneBedRooms + twoBedRooms + threeBedRooms; i++)
    {
        Room room(3);
        rooms[i] = room;
    }
}

int updateAvRoom(int room, Room rooms[], int start, int end)
{
    bool found = false;
    int range = end - start,
        count = 0;
    while (!found && count < range)
    {
        room++;
        count++;
        // Check if room is in range
        if (room == end)
            room = start - 1;
        // Check if room is already occupied
        else if (rooms[room].isOccupied())
            continue;
        else
            found = true;
    }
    if (found)
        return room;
    else
        return -1;
}