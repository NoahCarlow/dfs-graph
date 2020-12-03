// Assignment #8
// Name: Noah Carlow
// ASU Email Address: ncarlow2@asu.edu

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

// perform a DFS on our adjacency list that the user inputed
void Graph::depthFirstSearch(Graph thisGraph, int size)
{
    color = new string[size]; // holds the color of the nodes
    pi = new string[size]; // holds the parents of the nodes
    darray = new int[size];
    farray = new int[size];

    for (int i = 0; i < size; i++)
    {
        color[i] = "white";
        pi[i] = "none";
        //std::cout << thisGraph.adjacencyListProjects[i];
    }
    time = 0; // keeps track of DFS time

    for (int i = 0; i < size; i++)
    {
        if (color[i].compare("white") == 0)
        {
            DFSVISIT(thisGraph, i);
        }
    }
}

// visit each node in the horizonal array and gather data
void Graph::DFSVISIT(Graph thisGraph, int index)
{
    color[index] = "gray";
    time++; darray[index] = time;

    vector<string> names = adjacencyList[index].getProjName(); // grabs all names in horizonal list

    for (int i = 0; i < thisGraph.adjacencyList[index].sizeOfHorizontal(); i++)
    {
        string horizontalName = names[i]; // stores the string of the node in the horizontal array
        //std::cout << horizontalName;
        int indexOfHorizontal = search(horizontalName); // searches for that string in the vertical array
        //std::cout << indexOfHorizontal;
        //std::cout<<std::endl;
        if (color[indexOfHorizontal].compare("white") == 0)
        {
            pi[indexOfHorizontal] = thisGraph.adjacencyListProjects[index]; // set the parent in the pi array
            DFSVISIT(thisGraph, indexOfHorizontal); // recursion call to visit the rest of the nodes
        }
    }
    color[index] = "black";
    time++;
    farray[index] = time;
}

// print out all of the array content after DFS
void Graph::printGraph()
{
    std::cout << "DFS being performed..." << std::endl;
    std::cout<<endl;

    std::cout << "The array pi content:" << std::endl;
    std::cout<<endl;
    for(int i = 0; i < graphSize; i++)
    {
        std::cout << "pi[" << adjacencyListProjects[i] << "]" << " = " << pi[i] << std::endl;
    }
    std::cout<<endl;
    
    std::cout << "The array d content:" << std::endl;
    std::cout<<endl;
    for(int i = 0; i < graphSize; i++)
    {
        std::cout << "d[" << adjacencyListProjects[i] << "]" << " = " << darray[i] << std::endl;
    }
    std::cout<<endl;

    std::cout << "The array f content:" << std::endl;
    std::cout<<endl;
    for(int i = 0; i < graphSize; i++)
    {
        std::cout << "f[" << adjacencyListProjects[i] << "]"<< " = " << farray[i] << std::endl;
    }
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