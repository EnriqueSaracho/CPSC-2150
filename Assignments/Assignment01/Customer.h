#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
    int customerId; // Customer id
    int reqBeds;    // Number of requested beds

public:
    // Default constructor
    Customer();
    // Constructor
    Customer(int id, int beds);
};

#endif