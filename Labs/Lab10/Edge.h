#ifndef EDGE_H
#define EDGE_H
#include <iostream>

class Edge
{
public:
    int vertex1, vertex2;
    int weight;

    Edge();
    Edge(int v1, int v2, int w);
};

Edge::Edge()
{
    vertex1 = 0;
    vertex2 = 0;
    weight = 0;
}

Edge::Edge(int v1, int v2, int w)
{
    vertex1 = v1;
    vertex2 = v2;
    weight = w;
}

#endif