#include <iostream>
#include "Queue.h"

using namespace std;

int se(int arrayPassIn[]){
	///int arrayPassIn[] = { 1, 5, 7, 8, 22, 34, 55, 77, 99 };
	for (int num : arrayPassIn){

	}
}

int search(int dataArray[], int arraySize, int start, int target){
	//int arrayPassIn[] = { 1, 5, 7, 8, 22, 34, 55, 77, 99 };
	start = 0;
	for (int num : dataArray)
	{
		if (num == target){
			return start;
		}
		else if (num > target){
			return -1;
		}
		else {
			start++;
		}
	}
	return 0;
}


int main(){
	int dataArray[] = { 1, 2, 3, 4, 5 };

	for (int i : dataArray)
	{
		cout << i << endl;
	}

	int arrayPassIn[] = { 1, 5, 7, 8, 22, 34, 55, 77, 99 };
	cout << search(arrayPassIn, 9, 0, 22) << endl;
	/*Queue queue;
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
	return 0;*/
}