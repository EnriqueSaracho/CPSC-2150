#include <iostream>
#include "Circle.h"
#include "cmath"

const double PI = 3.14159;
int Circle::count = 0;

// Default constructor
Circle::Circle() : x(0), y(0), radius(10)
{
    // Count objects left of y-axis
    if (x < 0)
        count++;
}

// Constructor
Circle::Circle(int a, int b, double r)
{
    if (r > 0)
        radius = r;
    else
        radius = 1.0;

    x = a;
    y = b;

    // Count objects left of y-axis
    if (x < 0)
        count++;
}

// Get x
int Circle::getX() const
{
    return x;
}

// Get y
int Circle::getY() const
{
    return y;
}

// Get radius
double Circle::getRadius() const
{
    return radius;
}

// Modify location
void Circle::translateXY(int X, int Y)
{
    // Update for getNumberOfCurrentCircles()
    if (x < 0 && X >= (x * -1))
        count--;
    if (x > 0 && (X * -1) > x)
        count++;

    x += X;
    y += Y;
}

// Modify radius
void Circle::setRadius(double r)
{
    if (r > 0)
        radius = r;
    else
        throw "Radius must be greater than 0.0";
}

// Compute and display area
double Circle::computeArea()
{
    return PI * pow(radius, 2);
}

// Display circle values
void Circle::displayCircle()
{
    std::cout << "[x = " << x << ", y = " << y << ", radius = " << radius << "]" << std::endl;
}

// Find intersections
bool Circle::intersect(Circle c2)
{
    double dist = sqrt(pow(c2.x - x, 2) + pow(c2.y - y, 2));
    double radiusSum = radius + c2.radius;
    if (radiusSum > dist)
        return true;
    return false;
}

// Get number of Circle class instances on left side of y-axis
int Circle::getNumberOfCurrentCircles()
{
    return count;
}