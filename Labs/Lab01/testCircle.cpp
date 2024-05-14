#include <iostream>
#include "Circle.h"

int main()
{
    // Creating circles
    Circle c1;
    Circle c2(3, 6, 15);
    Circle c3(10, -15, 4.6);
    Circle c4(6, -12, -2.5);

    // Using getNumberOfCurrentCircles()
    std::cout << "Circle count: " << Circle::getNumberOfCurrentCircles() << std::endl;

    // Displaying Circle 1 information
    std::cout << "Circle 1" << std::endl;
    c1.displayCircle();
    std::cout << "Area: " << c1.computeArea() << std::endl;
    std::cout << std::endl;

    // Displaying Circle 2 information
    std::cout << "Circle 2" << std::endl;
    c2.displayCircle();
    std::cout << "Area: " << c2.computeArea() << std::endl;
    std::cout << std::endl;

    // Displaying Circle 3 information
    std::cout << "Circle 3" << std::endl;
    c3.displayCircle();
    std::cout << "Area: " << c3.computeArea() << std::endl;
    std::cout << std::endl;

    // Displaying Circle 4 information
    std::cout << "Circle 4" << std::endl;
    c4.displayCircle();
    std::cout << "Area: " << c4.computeArea() << std::endl;
    std::cout << std::endl;

    // Using translateXY() for Circle 4
    std::cout << "Translating Circle 4" << std::endl;
    c4.translateXY(-11, 27);
    std::cout << "Circle 4" << std::endl; // Displaying information
    c4.displayCircle();
    std::cout << "Area: " << c4.computeArea() << std::endl;
    std::cout << std::endl;

    // Using setRadius() for Circle 2
    std::cout << "Trying to set radius of Circle 2 to -20" << std::endl;
    try
    {
        c2.setRadius(-20);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    std::cout << "Circle 2" << std::endl; // Displaying informaion
    c2.displayCircle();
    std::cout << "Area: " << c2.computeArea() << std::endl;
    std::cout << std::endl;

    // Using setRadius() for Circle 2
    std::cout << "Trying to set radius of Circle 2 to 4" << std::endl;
    try
    {
        c2.setRadius(4);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    std::cout << "Circle 2" << std::endl; // Displaying information
    c2.displayCircle();
    std::cout << "Area: " << c2.computeArea() << std::endl;
    std::cout << std::endl;

    // Using intersect() for Circle 1 and 2
    std::cout << "Circle 1 intersects Circle 2: " << c1.intersect(c2) << std::endl;

    // Using intersect() for Circle 1 and 3
    std::cout << "Circle 1 intersects Circle 3: " << c1.intersect(c3) << std::endl;
    std::cout << std::endl;

    // Using getNumberOfCurrentCircles()
    std::cout << "Circle count: " << Circle::getNumberOfCurrentCircles() << std::endl;
}