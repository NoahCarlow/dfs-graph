// Assignment #8
// Name: Noah Carlow
// ASU Email Address: ncarlow2@asu.edu

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

class Graph
{
    public:
        vector<string> adjacencyListProjects;
        LinkedList* adjacencyList;
        string* color;
        string* pi;
        int* darray;
        int* farray;
        int time = 0;
        int graphSize = 0;
        // add node into our adjency list
        void addNode(string nodeOne);

        // add project into our adjency list
        void addEdge(string nodeOne, string nodeTwo, int weight);

        // shortest path algorithm using Dijkstra's method
        void depthFirstSearch(Graph thisGraph, int size);

        void DFSVISIT(Graph thisGraph, int index);

        // initialize our adjacency list to our node size
        void createAdjacencyList(int size);

        // searches through the linked list and returns the index at which a project is found
        int search(string projName);

        void printGraph(); // prints the graph
};

#endif 