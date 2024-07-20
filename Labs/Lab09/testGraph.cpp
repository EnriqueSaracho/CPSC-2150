#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AMGraph.h"
#include "ALGraph.h"

AMGraph makeDenseDWG(int n);
ALGraph makeSparseUDWG(int n);

int main()
{
    int n = 12;
    ALGraph graph = makeSparseUDWG(n);
    AMGraph graph = makeDenseDWG(n);
}

ALGraph makeSparseUDWG(int n)
{
    // Checking that n > 10
    if (n < 11)
        return ALGraph();

    // Initializing graph without edges
    ALGraph graph(n);

    // Seed for random number
    std::srand(std::time(0));

    // Number of edges to add
    int maxEdges = 2 * n,
        numEdges = std::rand() % (maxEdges + 1),
        edgesAdded = 0;

    // Filling the graph with edges
    while (edgesAdded < numEdges)
    {
        int v1 = std::rand() % n;
        int v2 = std::rand() % n;

        // Ensuring no duplicate edges
        if (!graph.edgeExists(v1, v2))
        {
            int weight = std::rand() % 100 + 1;
            graph.updateEdge(v1, v2, weight);
            edgesAdded++;
        }
    }

    return graph;
}

AMGraph makeDenseDWG(int n)
{
    // Checking that n > 10
    if (n < 11)
        return AMGraph();

    // Initializing graph without edges
    AMGraph graph(n);

    // Seed for random number
    std::srand(std::time(0));

    // Number of edges to add
    int minEdges = ((n - 2) * n) / 2,
        maxEdges = n * (n - 1),
        extraEdges = std::rand() % (maxEdges - minEdges + 1),
        edgesAdded = 0;

    // Filling the graph with edges
    while (edgesAdded < minEdges + extraEdges)
    {
        int v1 = std::rand() % n;
        int v2 = std::rand() % n;

        // Ensuring no duplicate edges
        if (!graph.edgeExists(v1, v2))
        {
            int weight = std::rand() % 100 + 1;
            graph.updateEdge(v1, v2, weight);
            edgesAdded++;
        }
    }

    return graph;
}