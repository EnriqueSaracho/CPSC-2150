#ifndef STACK_H
#define STACK_H

class Circle
{
private:
    int x;
    int y;
    double radius;
    static int count;

public:
    // Default constructor
    Circle();
    // Constructor
    Circle(int a, int b, double r);
    // Get X
    int getX() const;
    // Get Y
    int getY() const;
    // Get Radius
    double getRadius() const;
    // Modify location
    void translateXY(int X, int Y);
    // Modify radius
    void setRadius(double r);
    // Compute and display area
    double computeArea();
    // Display circle values
    void displayCircle();
    // Find intersections
    bool intersect(Circle c2);
    // Get number of Circle class instances on left side of y-axis
    static int getNumberOfCurrentCircles();
};
#endif