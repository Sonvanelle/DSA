
//Queue.h - - Specification of Queue ADT (implemented using Pointers)

#include<string>
#include<iostream>
using namespace std;

typedef char ItemType;

class Queue
{
private:
	struct Node
	{
		ItemType item;	// item
		Node     *next;	// pointer pointing to next item
	};

	Node *frontNode;	// point to the first item
	Node *backNode;	// point to the first item


public:
	// constructor
	Queue();

	~Queue();

	// enqueue item at the back of queue
	bool enqueue(ItemType& newItem);

	// dequeue item from front of queue
	bool dequeue();

	// dequeue and retrieve item from front of queue
	bool dequeue(ItemType& item);


	// retrieve item from front of queue
	void getFront(ItemType& item);

	// display items in queue from front to back
	void displayItems();

	// check if the queue is empty
	bool isEmpty();

};

