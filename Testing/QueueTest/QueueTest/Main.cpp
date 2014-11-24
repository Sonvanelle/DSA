#include <iostream>
#include "Queue.h"

using namespace std;
int main(){
	Queue queue;
	if (queue.isEmpty())
		cout << "Queue is Empty" << endl;
	else
		cout << "Queue is NOT Empty" << endl;

	ItemType item = 2;
	queue.enqueue(item);

	cout << "Added 2" << endl;
	if (queue.isEmpty())
		cout << "Queue is Empty" << endl;
	else
		cout << "Queue is NOT Empty" << endl;

	queue.dequeue();
	cout << "Removed 2" << endl;
	if (queue.isEmpty())
		cout << "Queue is Empty" << endl;
	else
		cout << "Queue is NOT Empty" << endl;
	return 0;
}