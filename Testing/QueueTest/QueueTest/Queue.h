
// Queue.h - - Specification of Queue ADT (implemented using Circular Array)

#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 100;
typedef int ItemType;

class Queue
{
private:
	ItemType items[MAX_SIZE];
	int  front;
	int  back;
	bool isFull;
public:
	// constructor
	Queue();

	// enqueue item at back of the queue
	bool enqueue(ItemType& newItem);

	// dequeue item from front of the queue
	bool dequeue();

	// retrieve and dequeue item from front of the queue
	bool dequeue(ItemType& item);

	// retrieve item from front of queue
	void getFront(ItemType& item);

	// check if the queue is empty
	bool isEmpty();

};
