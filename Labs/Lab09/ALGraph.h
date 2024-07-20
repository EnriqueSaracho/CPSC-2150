#ifndef ALGRAPH_H
#define ALGRAPH_H
#include <iostream>
#include <vector>
#include "Edge.h"

class ALGraph
{
private:
    std::vector<std::vector<Edge>> list;

public:
    ALGraph();      // Default constructor
    ALGraph(int n); // Constructor
    void updateEdge(int v1, int v2, int w);
    bool edgeExists(int v1, int v2);
};

ALGraph::ALGraph() {}

ALGraph::ALGraph(int n) : list(n) {}

void ALGraph::updateEdge(int v1, int v2, int w)
{
    if (v1 >= list.size() || v2 >= list.size())
        return;

    list[v1].emplace_back(v2, w);
    list[v2].emplace_back(v1, w);
}

bool ALGraph::edgeExists(int v1, int v2)
{
    // Checking if v1 or v2 is out of bounds
    if (v1 >= list.size() || v2 >= list.size())
        return false;

    // Searching in the adjacency list of vertex v1
    for (const Edge &edge : list[v1])
        if (edge.vertex == v2)
            return true;
    return false;
}

#endif