#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;
bool checkIfPalindrome(string input){
	Stack s;
	Queue q;
	for (int i = 0; i < input.length(); i++){
		//Insert the char in the string into both the stack and queue
		s.push(input[i]);
		q.enqueue(input[i]);
	}

	//Pop from stack and dequeue from queue and check if it matches
	while (!q.isEmpty())
	{
		ItemType queueItem, stackItem;
		s.pop(stackItem);	//Pop from stack
		q.dequeue(queueItem);	//Dequeue from queue
		//Check if they match
		if (stackItem != queueItem){
			//Doesnt match, return false
			return false;
		}
	}

	//Matches, its a palindrome, return true
	return true;
}

int main(){
	Queue q;				//Create Empty Queue (5a)
	ItemType item;
	item = 'a';
	q.enqueue(item);		//Enqueue 'a' (5b)
	item = 'b';
	q.enqueue(item);		//Enqueue 'b' (5c)
	q.getFront(item);
	cout << item << endl;	//Get front and display (5d)
	q.displayItems();		//Display all items in q (5e)
	q.dequeue();			//Dequeue q (5f)
	q.displayItems();		//Display all items in q (5g)


	//Qn 6
	//Read User Input
	cout << endl << "Input some characters to check if it is a palindrome: ";
	string input;
	getline(cin, input);
	
	if (checkIfPalindrome(input))
		cout << endl << input << " is a palindrome!" << endl;
	else
		cout << endl << input << " is not a palindrome!" << endl;
	return 0;
}