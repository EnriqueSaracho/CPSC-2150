#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Edge.h"

void reverseKruskal(std::vector<std::vector<int>> &);
std::vector<std::vector<int>> getInput(std::string);
std::vector<Edge> createTree(std::vector<std::vector<int>> &);
int partition(std::vector<Edge> &, int, int);
void quickSort(std::vector<Edge> &, int, int);
std::vector<Edge> quickSortEdges(std::vector<Edge>);

int main()
{
    std::string filename = "sparse7.txt";
    // std::string filename = "sparse25.txt";

    std::vector<std::vector<int>> graph;
    graph = getInput(filename);
    reverseKruskal(graph);
}

void reverseKruskal(std::vector<std::vector<int>> &graph)
{
    // Starting algorithm with all edges in tree // O(m^2)
    std::vector<Edge> tree = createTree(graph);

    // Sequence of all edges sorted by weight in descending order // O(nlogn)
    std::vector<Edge> edges = quickSortEdges(tree);

    // Creating Union-Find id vector.
    // First index is parent of all others.
    std::vector<int> id(graph.size(), 0);

    const int E = edges.size();
    const int V = graph.size();

    // Updating id vector to have parents according to MST
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].vertex1;
        int v = edges[i].vertex2;
        id[v] = u;
    }

    // Removing unnecesary edges
    std::cout << "Edges removed:" << std::endl;
    std::vector<Edge> mst;
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].vertex1;
        int v = edges[i].vertex2;
        int w = edges[i].weight;

        if (id[v] != u)
            std::cout << "  {" << u << ", " << v << ", " << w << "}" << std::endl;
        else
            mst.emplace_back(edges[i]);
    }

    // Printing MST edges
    std::cout << "MST Edges: " << std::endl;
    for (int i = 0; i < mst.size(); i++)
    {
        int u = edges[i].vertex1;
        int v = edges[i].vertex2;
        int w = edges[i].weight;

        std::cout << "  {" << u << ", " << v << ", " << w << "}" << std::endl;
    }
}

int partition(std::vector<Edge> &edges, int low, int high)
{
    int pivot = edges[high].weight;
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (edges[j].weight > pivot)
        {
            i++;
            std::swap(edges[i], edges[j]);
        }
    }
    std::swap(edges[i + 1], edges[high]);
    return i + 1;
}

void quickSort(std::vector<Edge> &edges, int low, int high)
{
    if (low < high)
    {
        int pi = partition(edges, low, high);

        quickSort(edges, low, pi - 1);
        quickSort(edges, pi + 1, high);
    }
}

std::vector<Edge> quickSortEdges(std::vector<Edge> edges)
{
    if (!edges.empty())
        quickSort(edges, 0, edges.size() - 1);

    return edges;
}

std::vector<Edge> createTree(std::vector<std::vector<int>> &graph)
{
    std::vector<Edge> tree;

    int m = graph.size();
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            if (graph[i][j] != 0)
                tree.emplace_back(i, j, graph[i][j]); // O(1)

    return tree;
}

std::vector<std::vector<int>> getInput(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Unable to open file");

    int n;
    file >> n;
    if (file.fail())
        throw std::runtime_error("Error reading the number of elements");

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    int vertex1, vertex2, weight;
    while (file >> vertex1 >> vertex2 >> weight)
    {
        if (vertex1 >= n || vertex2 >= n)
            throw std::runtime_error("Index out of bounds");

        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
    }

    if (file.fail() && !file.eof())
    {
        throw std::runtime_error("Error reading matrix data");
    }

    file.close();
    return graph;
}