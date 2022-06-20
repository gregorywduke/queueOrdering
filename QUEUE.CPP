// File Name: Queue.h
//
// Author: Gregory Duke
 // Date:4/23/2019
// Assignment Number: 6
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// A header file that creates a queue of nodes, as well as various queue functions

#include <string>

using namespace std;

class Queue {
private:
    // define a Node to store strings and any other member variables here
    struct Node
    {
	string data;
	Node *next;
    };

    Node *head;


public:
    Queue();
    void enqueue(string);
    string dequeue();
    bool isEmpty();
    int size();  //returns the number of elements in the queue
};

Queue::Queue()
{
    head = NULL;
}

void Queue::enqueue( string x )
{
    assert( !isEmpty() );  // should ensure queue is not full [needs correction]

    Node newNode = head;
    while ( newNode )
    {
	newNode = newNode->next;
    }

    int value = newNode->data;

    return value;
}

string Node::dequeue()
{
    assert( isEmpty() ); //make sure queue isn’t empty

    int value = head->data;
    head = head->next;           // set head to next node

    return value;
}

bool Node::isEmpty()
{
    bool validate;
    if( head == NULL )
    {
	validate = true;
	return validate;     //if empty, return true
    }

    else
    {
	validate = false;
	return validate;     //else, return false
    }
}

int Node::size()
{
    Node newNode = head;
    int size = 0;

    while ( newNode != NULL )
    {
        size++;
        newNode = newNode->next;
    }

    return size;
}
