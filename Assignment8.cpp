// Assignment #8
// Name: Noah Carlow
// ASU Email Address: ncarlow2@asu.edu
// Description: This program lets a user enter in nodes which connect to other nodes.
//              It will then use a DFS to find the shortest path between nodes.

#include <iostream> // used for input and output
#include <string>   // used for strings
#include <sstream>  // used for parsing , delimited string
#include <vector>   // used as a data structure to hold parsed strings
#include "Graph.h"

int main()
{
    Graph* myGraph = new Graph(); // initialize graph object

    int numberOfNodes = 0; 
    cin >> numberOfNodes; // take number of nodes from user input

    myGraph->createAdjacencyList(numberOfNodes); // create adjacency list size: numberOfNodes

    string nodes;
    
    for(int i = 0; i < numberOfNodes; i++)
    {
        vector<string> parsedString; // hold parsed strings, resets every iteration of for loop
        int nodesConnected = 0; // keep track of number of nodes connected

        cin >> nodes; // take node names and connections
        

        stringstream s_stream(nodes);
        while(s_stream.good())
        {
            string subStr;
            getline(s_stream, subStr, ','); // string delimited by comma
            parsedString.push_back(subStr);
            nodesConnected++;
        }

        // node at 0 is the original node
        myGraph->addNode(parsedString[0]);

        // traverses through nodes that are connected to the original node
        for (int y = 1; y < nodesConnected; y++)
        {
            // adopted from https://stackoverflow.com/questions/28163723/c-how-to-get-substring-after-a-character
            string nodeWeight = parsedString[y].substr(parsedString[y].find("(") + 1); // gets the substr after '(' where weight is held
            nodeWeight.pop_back(); // deletes the last char of the string which is ')'

            stringstream s_stream(parsedString[y]);
            
            string nodeName; // holds nodes name
            getline(s_stream, nodeName, '('); // string delimited by (

            myGraph->addEdge(parsedString[0], nodeName, stoi(nodeWeight)); // load the connected node into adjacency list
        }
    }

    // print the adjacency list
    std::cout << "The Graph Content:\n-------------------" << endl;
    for (int i = 0; i < numberOfNodes; i++)
    { 
        std::cout << "From: " << myGraph->adjacencyListProjects[i] << std::endl; // vertical list
        myGraph->adjacencyList[i].printList(); // horizontal list
        std::cout << std::endl;
    }

    myGraph->depthFirstSearch(*myGraph, numberOfNodes);
    myGraph->printGraph();
}