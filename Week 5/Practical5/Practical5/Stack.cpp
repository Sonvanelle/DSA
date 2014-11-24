/** @file Stack.cpp */

#include <iostream>
#include <cstddef>   // for NULL
#include <new>       // for bad_alloc
#include "Stack.h"  // header file

using namespace std;

Stack::Stack(){
	topNode = NULL;
}

//Pop all the items in stack
Stack::~Stack(){
	while (!isEmpty()){
		pop();
	}
}

bool Stack::push(ItemType& newItem){
	//Create new node
	Node *newNode = new Node;
	//Store item to node and set next to NULL
	newNode->item = newItem;
	newNode->next = NULL;

	//Set new node next pointer to point to node pointed by topNode
	newNode->next = topNode;
	//Set topNode to point to newNode
	topNode = newNode;
	//Return true
	return true;
}

//Just pop topNode
bool Stack::pop(){
	//Check if index is valid
	if (!isEmpty()){
		//Set tmpPtr to point to top node
		Node *tmpPointer = topNode;
		//Set topNode ptr to point to next Node
		topNode = topNode->next;
		//Removed node next ptr to NULL
		tmpPointer->next = NULL;
		//deallocate memory from removed Node
		delete tmpPointer;
		return true;
	}
	return false;
}

//Retive and pop topNode
bool Stack::pop(ItemType& item){
	//Check if index is valid
	if (!isEmpty()){
		//Retrive topNode item
		item = topNode->item;
		//Set tmpPtr to point to top node
		Node *tmpPointer = topNode;
		//Set topNode ptr to point to next Node
		topNode = topNode->next;
		//Removed node next ptr to NULL
		tmpPointer->next = NULL;
		//deallocate memory from removed Node
		delete tmpPointer;
		return true;
	}
	return false;
}

void Stack::getTop(ItemType& item){
	//Check if index is valid
	if (!isEmpty()){
		//Return item in topNode
		item = topNode->item;
	}
}

//Check if topNode is empty
bool Stack::isEmpty(){
	if (topNode == NULL){
		return true;
	}
	return false;
}