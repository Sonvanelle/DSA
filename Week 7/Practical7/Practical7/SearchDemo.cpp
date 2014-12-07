#include <iostream>

using namespace std;

//Static var for comparision
static int comparisions = 0;

//Question 1 (Iterative Sequential Search of Sorted Array)
int search(int dataArray[], int arraySize, int target){
	//Set index to 0 and loop through array
	for (int i = 0; i < arraySize; i++){
		comparisions++;
		if (dataArray[i] == target){
			//If Matches, return index
			return i;
		}
		//Check if value in array exceeded target
		if (dataArray[i] > target){
			//Item not found if above statement is true, return -1
			return -1;
		}
	}
	//End of array, item not found, return -1
	return -1;
}

//Question 3 (Iterative Binary Search of Sorted Array)
int binarySearch(int dataArray[], int arraySize, int target){
	int first = 0, last = arraySize - 1;	//Set first to start and last to end of array

	while (first <= last){		//Loop while first is less than last
		comparisions++;
		int mid = (first + last) / 2;	//Set mid to middle of the array
		if (dataArray[mid] == target){
			//Mid is target
			return mid;
		}
		if (dataArray[mid] > target){	//Cut the first half of the array into half
			last = mid - 1;
		}
		else {
			first = mid + 1;	//Cut the second half of the array into half
		}
	}

	//Cannot find item. Returning
	return -1;
}

//Question 8 (Recursive Sequential Search of Sorted Array)
int search(int dataArray[], int arraySize, int start, int target){
	//Loop through array
	for (int num = 0; num < arraySize; num++){
		if (dataArray[start] == target){
			//If match, return index (start)
			return start;
		}
		else if (dataArray[start] > target){
			//Value had exceeded target, return -1
			return -1;
		}
		else {
			//Recurse back in to search the next index
			return search(dataArray, arraySize, start + 1, target);
		}
	}
	//Cannot find target, return -1
	return -1;

}

//Question 9 (Recursive Binary Search of Sorted Array)
int binarySearch(int dataArray[], int first, int last, int target){
	while (first <= last){		//Loop while first is less than last
		comparisions++;
		int mid = (first + last) / 2;	//Set mid to middle of the array
		if (dataArray[mid] == target){
			//Mid is target
			return mid;
		}
		if (dataArray[mid] > target){	//Recurse into the first half of the array
			return binarySearch(dataArray, first, mid - 1, target);
		}
		else {
			return binarySearch(dataArray, mid + 1, last, target);	//Recurse into the second half of the array
		}
	}

	//Cannot find item. Returning -1
	return -1;
}

int main(){
	int dataArray[1000];					//Declare size 1000 int array (2a)
	int evenNoInit = 2;
	for (int i = 0; i < 1000; i++){			//Initialize array with even numbers (2b)
		dataArray[i] = evenNoInit;
		evenNoInit = evenNoInit + 2;
	}
	cout << "Enter a search target: ";		//Prompt user to enter a target search number (2c)
	int target;
	cin >> target;							//Read number entered and store to var target (2d)
	cout << endl << "===========================" << endl << "Check Target (Qn 2 & 4)" << endl << "===========================" << endl;
	int result = search(dataArray, 1000, target);
	if (result != -1){						//Invoke iterative sequential search method and display results (2e)
		cout << "Iterative Sequential Search : Found target (Index: " << result << ")" << endl;
	}
	else {
		cout << "Iterative Sequential Search : Target Not Found" << endl;
	}
	result = binarySearch(dataArray, 1000, target);
	if (result != -1){						//Invoke iterative binary search method and display results (4)
		cout << "Iterative Binary Search     : Found target (Index: " << result << ")" << endl;
	}
	else {
		cout << "Iterative Binary Search     : Target Not Found" << endl;
	}
	cout << "===========================" << endl;

	cout << endl << "===========================" << endl << "Comparisions Counts (Qn 6)" << endl << "===========================" << endl;
	comparisions = 0;
	int idx1 = search(dataArray, 1000, target);
	cout << "Sequential Search : " << comparisions << endl;

	comparisions = 0;
	int idx2 = binarySearch(dataArray, 1000, target);
	cout << "Binary Search     : " << comparisions << endl;
	cout << "===========================" << endl;

	cout << endl << "===========================" << endl << "Check Target (Qn 8 & 9)" << endl << "===========================" << endl;
	result = search(dataArray, 1000, 0, target);
	if (result != -1){						//Invoke iterative sequential search method and display results (2e)
		cout << "Recursive Sequential Search : Found target (Index: " << result << ")" << endl;
	}
	else {
		cout << "Recursive Sequential Search : Target Not Found" << endl;
	}
	result = binarySearch(dataArray, 0, 999, target);
	if (result != -1){						//Invoke iterative binary search method and display results (4)
		cout << "Recursive Binary Search     : Found target (Index: " << result << ")" << endl;
	}
	else {
		cout << "Recursive Binary Search     : Target Not Found" << endl;
	}
	cout << "===========================" << endl;

	return 0;
}