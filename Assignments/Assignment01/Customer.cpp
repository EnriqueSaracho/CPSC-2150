#include <iostream>
#include "Customer.h"

// Default constructor
Customer::Customer()
{
    reqBeds = 1;
}
// Constructor
Customer::Customer(int id, int beds)
{
    customerId = id;
    reqBeds = beds;
}