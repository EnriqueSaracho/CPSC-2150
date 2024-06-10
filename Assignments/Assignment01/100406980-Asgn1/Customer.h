#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
    std::string id; // Customer id
    int reqBeds;    // Number of requested beds

public:
    // Default constructor
    Customer();
    // Constructor
    Customer(int beds, std::string);
    // Copy constructor
    Customer(Customer &);
    // Get customer ID
    std::string getId();

    // Displays customer id
    void printId();
    // Displays number of requested beds
    void printBeds();
};

#endif