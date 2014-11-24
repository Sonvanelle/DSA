#include <iostream>
#include "Queue.h"

using namespace std;
Queue::Queue(){
	front = 0;
	back = MAX_SIZE - 1;
	isFull = false;
}

bool Queue::enqueue(ItemType& item){
	if (!isFull){
		back = (back + 1) % MAX_SIZE;
		items[back] = item;
		cout << "[QUEUE] Added" << item << endl;
		if ((back + 1) % MAX_SIZE == front)
			isFull = true;
		return true;
	}
	cout << "An error occurred(Queue full)" << endl;
	return false;

}

bool Queue::dequeue(){
	if (!isEmpty()){
		front = (front + 1) % MAX_SIZE;
		cout << "[QUEUE] Removed Item" << endl;
		isFull = false;
		return true;
	}
	return false;
}

bool Queue::dequeue(ItemType& item){
	if (!isEmpty()){
		front = (front + 1) % MAX_SIZE;
		item = items[front];
		cout << "[QUEUE] Removed " << item << endl;
		isFull = false;
		return true;
	}
	return false;
}

bool Queue::isEmpty(){
	return (((back + 1) % MAX_SIZE) == (front % MAX_SIZE) && isFull == false);
}

void Queue::getFront(ItemType& item){
	item = items[front];
}