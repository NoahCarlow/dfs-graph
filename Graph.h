#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include "LinkedList.h"
#include "MinHeap.h"
using namespace std;

class Graph
{
    public:
        vector<string> adjacencyListProjects;
        LinkedList* adjacencyList;
        MinHeap* myHeap;
        int graphSize = 0;
        // add node into our adjency list
        void addNode(string nodeOne);

        // add project into our adjency list
        void addEdge(string nodeOne, string nodeTwo, int weight);

        // shortest path algorithm using Dijkstra's method
        void shortestPath(Graph thisGraph);

        // initialize our adjacency list to our node size
        void createAdjacencyList(int size);

        // searches through the linked list and returns the index at which a project is found
        int search(string projName);
};

#endif 