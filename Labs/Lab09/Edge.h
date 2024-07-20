#ifndef EDGE_H
#define EDGE_H
#include <iostream>

class Edge
{
public:
    int vertex;
    int weight;

    Edge();
    Edge(int v, int w);
};

Edge::Edge() {}

Edge::Edge(int v, int w)
{
    vertex = v;
    weight = w;
}

#endif