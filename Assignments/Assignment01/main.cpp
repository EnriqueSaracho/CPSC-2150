#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "Room.h"
#include "Customer.h"

bool compareDates(const tm *, int, int, int);
// void printLog();

int main()
{
    // Initializing date tracker
    tm *date = new tm;
    std::memset(date, 0, sizeof(tm));

    // Reading data from file
    std::ifstream fin;
    fin.open("Customers.txt");

    if (!fin.is_open())
    {
        std::cerr << "Error: Unable to open file 'Customers.txt'" << std::endl;
        return 1;
    }

    // Declaring variables
    std::string line;
    char delimiter;
    int day, month, year;
    std::string customerId;
    int beds, stay;
    bool dateFlag = false;

    // Skipping headers line
    std::getline(fin, line);

    // Reading each line/customer individually
    while (std::getline(fin, line))
    {
        std::stringstream ss(line);

        // Reading date
        ss >> day >> delimiter >> month >> delimiter >> year;
        if (!compareDates(date, day, month, year))
        {
            date->tm_mday = day;
            date->tm_mon = month - 1;
            date->tm_year = year - 1900;
            // if (dateFlag)
            //     // Display daily log
            //     printLog();
            // else
            //     dateFlag = true;
        }

        // Reading customer info
        ss.ignore(2);
        std::getline(ss, customerId, ',');
        ss.ignore(1);
        ss >> beds;
        ss.ignore(2);
        ss >> stay;

        Customer customer(beds);


        // TODO: Remove testing 'break' when done testing
        break;
    }
    // TODO: Remove test logs after done testing
    std::cout << day << "/" << month << "/" << year << std::endl;
    // std::cout << asctime(date) << std::endl;
    std::cout << "id: " << customerId << ", beds: " << beds << ", stay: " << stay << std::endl;

    // date->tm_year = 2018 - 1900;
    // date->tm_mon = 1 - 1;
    // date->tm_mday = 1;
    // std::cout << asctime(date) << std::endl;

    // // 1/1/2018
    // tm *currentTime = new tm;
    // std::memset(currentTime, 0, sizeof(tm));
    // currentTime->tm_year = 2018 - 1900;
    // currentTime->tm_mon = 1 - 1;
    // currentTime->tm_mday = 1;
    // std::cout << asctime(currentTime) << std::endl;

    // // Creating room
    // Room room1(2);
    // room1.printNumOfBeds();
    // room1.printCustomerId();
    // room1.printCheckInDate();
    // room1.printCheckOutDate();
    // std::cout << std::endl;

    // // Creating customer
    // Customer customer1(2);
    // customer1.printId();
    // std::cout << std::endl;

    // // Assigning room to customer
    // room1.assignRoom(customer1, currentTime, 5);
    // room1.printCustomerId();
    // room1.printCheckInDate();
    // room1.printCheckOutDate();
    // std::cout << std::endl;

    return 0;
}

bool compareDates(const tm *date, int day, int month, int year)
{
    return (date->tm_year == year &&
            date->tm_mon == month &&
            date->tm_mday == day);
}