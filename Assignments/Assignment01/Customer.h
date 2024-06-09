#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
    std::string id;   // Customer id
    int reqBeds;      // Number of requested beds
    static int count; // Number of customers

public:
    // Default constructor
    Customer();
    // Constructor
    Customer(int beds);
    // Copy constructor
    Customer(Customer &);

    // Assign ID to customer
    std::string assignId();
    // Get customer ID
    std::string getId();

    // TODO: Delete test logs when done testing
    // Displays customer id
    void printId();
    // Displays number of requested beds
    void printBeds();
    // Displays number of customers
    void printCount();
};

#endif