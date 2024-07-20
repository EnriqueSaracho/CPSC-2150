#ifndef AMGRAPH_H
#define AMGRAPH_H
#include <iostream>
#include <vector>

class AMGraph
{
private:
    std::vector<std::vector<int>> matrix;

public:
    AMGraph();      // Default constructor
    AMGraph(int n); // Constructor
    void updateEdge(int v1, int v2, int w);
    bool edgeExists(int v1, int v2);
};

AMGraph::AMGraph() {}

AMGraph::AMGraph(int n) : matrix(n, std::vector<int>(n, 0)) {}

void AMGraph::updateEdge(int v1, int v2, int w)
{
    if (v1 >= 0 && v1 < matrix.size() && v2 >= 0 && v2 < matrix.size())
        matrix[v1][v2] = w;
    else
        std::cerr << "Error: One or both vertices are out of bounds." << std::endl;
}

bool AMGraph::edgeExists(int v1, int v2)
{
    if (v1 >= 0 && v1 < matrix.size() && v2 >= 0 && v2 < matrix.size())
        return matrix[v1][v2] != 0;
    return false;
}

#endif