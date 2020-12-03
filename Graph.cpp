#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"

// LinkedList* adjacencyList;

// creates an array of linked lists and sets the size to the number of size input
void Graph::createAdjacencyList(int size)
{
    adjacencyList = new LinkedList[size];
    adjacencyListProjects[size];
    graphSize = size;
}

// adds project names into our adjacency list
void Graph::addNode(string nodeOne)
{
    adjacencyListProjects.push_back(nodeOne);
}

// adds nodes and weights into the corresponding project name in the adjacency list
void Graph::addEdge(string nodeOne, string nodeTwo, int weight)
{
    // searches for index at which to add project to
    int index = 0;
    for (int i = 0; i < adjacencyListProjects.size(); i++)
    {
        if(adjacencyListProjects[i].compare(nodeOne) == 0)
        {
            break;
        }
        index++;
    }
    adjacencyList[index].addProject(nodeTwo, weight);
}

// TODO
void Graph::shortestPath(Graph thisGraph)
{
    
}

//Searches through the linked list and returns the index at which a project is found
int Graph::search(string projName)
{
    bool found = false;
    // traverses through all nodes in the linked list
    if (adjacencyListProjects.empty())
    {
        cout << "Error: graph not initialized" << endl;
    }
    int index = 0;

    for (int i = 0; i < graphSize; i++)
    {
        if(adjacencyListProjects[i].compare(projName) == 0)
        {
            found = true;
            break;
        }
        index++;
    }
    if(!found)
    {
        return -1;
    }
    
    return index;
}