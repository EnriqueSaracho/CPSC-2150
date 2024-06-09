#include <iostream>
#include <string>
#include "Customer.h"

int Customer::count = 0;

// Default constructor
Customer::Customer()
{
    count++;

    id = assignId();
    reqBeds = 1;
}
// Constructor
Customer::Customer(int beds)
{
    count++;

    id = assignId();
    reqBeds = beds;
}
// Copy constructor
Customer::Customer(Customer &customer)
{
    count++;

    id = assignId();
    reqBeds = customer.reqBeds;
}

// Assign ID to customer
std::string Customer::assignId()
{
    std::string id;
    if (count < 10)
        id = "00000" + std::to_string(count);
    else if (count < 100)
        id = "0000" + std::to_string(count);
    else if (count < 1000)
        id = "000" + std::to_string(count);
    else if (count < 10000)
        id = "00" + std::to_string(count);
    else if (count < 100000)
        id = "0" + std::to_string(count);
    else
        id = std::to_string(count);

    return id;
}

// Get customer ID
std::string Customer::getId()
{
    return id;
}

// TODO: Delete test logs when done testing
// Display customer id
void Customer::printId()
{
    std::cout << id << std::endl;
}
// Display number of requested beds
void Customer::printBeds()
{
    std::cout << reqBeds << std::endl;
}
// Displays number of customers
void Customer::printCount()
{
    std::cout << count << std::endl;
}