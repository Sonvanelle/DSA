#include <iostream>
#include "Queue.h"

Queue::Queue(){
	frontNode = NULL;
	backNode = NULL;
}

Queue::~Queue(){
	while (!isEmpty()){
		dequeue();
	}
}

bool Queue::enqueue(ItemType& newItem){
	Node *newNode = new Node;	//Create New Node
	newNode->item = newItem;	//Store Item to Node
	newNode->next = NULL;		//Set next pointer to null

	//Check if queue is empty
	if (isEmpty()){
		//Set front node to new node
		frontNode = newNode;
	}
	else {
		//Set back node's next pointer to point to new node
		backNode->next = newNode;
	}

	//Set back node's pointer to point to new Node
	backNode = newNode;
	return true;
}

bool Queue::dequeue(){
	//Check if front node points to same location as back node (they are the same)
	if (frontNode == backNode){
		//Set front and back nodes to NULL
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		//Set temp pointer to front node
		Node *tmpPtr = frontNode;
		//Front node point to next node in stack
		frontNode = frontNode->next;
		//Make tmpPtr next pointer point to NULL
		tmpPtr->next = NULL;
		//Deallocate memory
		delete tmpPtr;
	}
	return true;
}

bool Queue::dequeue(ItemType& item){
	//Check if front node points to same location as back node (they are the same)
	if (frontNode == backNode){
		//Get Item Out
		item = frontNode->item;
		//Set front and back nodes to NULL
		frontNode = NULL;
		backNode = NULL;
	}
	else {
		//Set temp pointer to front node
		Node *tmpPtr = frontNode;
		//Front node point to next node in stack
		frontNode = frontNode->next;
		//Get Item Out
		item = tmpPtr->item;
		//Make tmpPtr next pointer point to NULL
		tmpPtr->next = NULL;
		//Deallocate memory
		delete tmpPtr;
	}
	return true;
}

void Queue::getFront(ItemType& item){
	//Check if queue empty
	if (!isEmpty()){
		item = frontNode->item;
	}
}

void Queue::displayItems(){
	Queue *tmpQueue = new Queue;	//Temporary queue
	cout << endl << "==========================" << endl;
	cout << "DISPLAY ALL ITEMS IN QUEUE" << endl;
	cout << "==========================" << endl;
	while (!isEmpty()){
		ItemType tmp;
		dequeue(tmp);				//Get Item out
		cout << tmp << endl;		//Print information
		tmpQueue->enqueue(tmp);		//Place in temporary queue
	}
	cout << "==========================" << endl;

	//Put it back into the queue
	while (!tmpQueue->isEmpty()){
		ItemType tmp;
		tmpQueue->dequeue(tmp);				//Get Item out
		enqueue(tmp);		//Place in queue
	}
}

bool Queue::isEmpty(){
	//Check if front node is NULL
	if (frontNode == NULL){
		return true;
	}
	return false;
}