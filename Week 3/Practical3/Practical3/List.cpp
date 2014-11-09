#include <iostream>
#include "List.h"

using namespace std;

List::List(){}

bool List::add(ItemType newItem){
	//Create a new node
	Node *newNode = new Node;
	newNode->item = newItem;	//Store item to node
	newNode->next = NULL;		//Initialize to NULL

	//Check if list empty
	if (size == 0){
		//Set first pointer to point at new node
		firstNode->next = newNode;
	}
	else {
		//Move to last node
		Node *tempNode = new Node;
		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
		}
		//Set lastNode to point to newNode
		tempNode->next = newNode;
		
	}
	size++;	//Increse list size
	return true;
}