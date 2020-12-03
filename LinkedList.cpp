#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Deallocates memory for the Project object, also used when a object passes out of scope.
LinkedList::~LinkedList()
{
    Project *next = head;

    while(next)
    {
        Project *del = next;
        next = next -> next;
        delete del;
    }
}

vector<string> LinkedList::getProjName()
{
    Project *pointer = new Project;
    pointer = head;
    vector<string> names;
    // traverses through all nodes in the linked list
    int i = 0;
    while (pointer != NULL)
    {
        names.push_back(pointer->projectName);
        i++;
        pointer = pointer->next;
        
    }
    
    return names;
}

vector<string> LinkedList::getProjWeight()
{
    Project *pointer = new Project;
    pointer = head;
    vector<string> names;
    
    // traverses through all nodes in the linked list
    int i = 0;
    
    while (pointer != NULL)
    {
        string weightToString = to_string(pointer->weight);
        names.push_back(weightToString);
        i++;
        pointer = pointer->next;
    }
    
    return names;
}

int LinkedList::sizeOfLinked()
{
    int count = 0; // Initialize count  
    Project* current = head; // Initialize current  
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;
}

//Adds a object called project containing a name and participant count (return true if added and false if not)
bool LinkedList::addProject(string newProjectName, int newDistance)
 {
    // try and catch for when there is no memory to create a new project
    try
    {
        Project *newNode = new Project;

        // assigns string and int to project
        newNode -> projectName = newProjectName;
        newNode -> weight = newDistance;
        newNode -> next = NULL;

        Project* ptr = head;

        if (head == NULL)
        {
            head = newNode;
            return true;
        }
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        
        return true;
    }
    catch(bad_alloc& badAlloc)
    {
        std::cerr << "Not enough memory! " << badAlloc.what() << endl;;
        return false;
    }
 }

//Removes a project from the linked list (return true if deleted and false if not)
bool LinkedList::removeProject(string projectName)
 {
    // t is used to keep track of previous node
    Project *t = new Project;
    // p is uesd to keep track of current node
    Project *p = new Project;
    p = head;

    // checks if the list is empty
    if(p == NULL)
    {
        return false;
    }

    // gets the position of the node which is to be deleted
    int nodePos = 0;
    while(projectName != (p -> projectName))
    {
        nodePos++;
        p = p -> next;
        if(p == NULL)
        {
            return false;
        }
    }
    // deletes head node if it is the requested node to be deleted
    if(nodePos == 0)
    {
        if(head == NULL)
        {
            return NULL;
        }
        p = head;
        head = head -> next;
        delete p;
        return true;
    }
    p = head;
    // traverses to node that needs to be deleted if not head node
    for(int i = 0; i < nodePos; i++)
    {
        t = p;
        p = p -> next;
    }
    t -> next = p -> next;
    delete p;
    return true;
 }
 
//Changes the participant int for the given project (return true if changed and false if not)
bool LinkedList::changeDistance(string projectName, int newDistance)
{
    // checks if list is empty
    Project* p = head;
    if(p == NULL)
    {
        return false;
    }

    // searches for the correct project name
    while(projectName != (p -> projectName))
    {
        p = p -> next;
        if(p == NULL)
        {
            return false;
        }
    }
    // if project name is found than it changes the participant count
    if(projectName == (p -> projectName))
    {
        p -> weight = newDistance;
        return true;
    }
    return true;
}

//Prints the entire linked list
void LinkedList::printList()
{
    Project *pointer = new Project;
    pointer = head;
    // traverses through all nodes in the linked list
    if (pointer == NULL)
    {
        cout << "No adjacent nodes" << endl;
    }
    while (pointer != NULL)
    {
        cout << "To: " << pointer -> projectName << " with weight " << pointer -> weight << endl;
        pointer = pointer->next;
    }
}