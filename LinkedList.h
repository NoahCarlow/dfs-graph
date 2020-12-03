// Assignment #8
// Name: Noah Carlow
// ASU Email Address: ncarlow2@asu.edu

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string> //to use strings
#include <vector>
using namespace std;

//struct Project represents some project information
struct Project
{
    string projectName;
    int weight;
    string color;
    struct Project * next;

    // constructor to initialize project
    Project()
    {
        projectName = "?";
        weight = -1;
        color = "white";
    }
};

//class LinkedList will contains a linked list of projects
class LinkedList
{
    private:
    struct Project * head;
    
    public:
    LinkedList();
    ~LinkedList();

    bool addProject(string projectName, int weight);
    bool removeProject(string projectName);
    bool changeDistance(string projectName, int newDistance);
    int sizeOfLinked();
    vector<string> getProjName();
    vector<string> getProjWeight();
    void printList();
    int sizeOfHorizontal();
};

#endif