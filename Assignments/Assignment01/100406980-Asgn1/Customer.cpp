#include <iostream>
#include <string>
#include "Customer.h"

// Default constructor
Customer::Customer()
{
    id = "000000";
    reqBeds = 1;
}
// Constructor
Customer::Customer(int beds, std::string assignedId)
{
    id = assignedId;
    reqBeds = beds;
}
// Copy constructor
Customer::Customer(Customer &customer)
{
    id = customer.id;
    reqBeds = customer.reqBeds;
}

// Get customer ID
std::string Customer::getId()
{
    return id;
}

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