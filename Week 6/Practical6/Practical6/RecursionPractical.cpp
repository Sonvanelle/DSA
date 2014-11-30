#include <iostream>

using namespace std;

//Calculates the value of a given integer raised to the power of
//a second integer.   
//param a – the base integer (to be raised to a power).
//param n – the power
//pre: a > 0
//post: return the value of a to the nth power.
long power(int a, int n){
	if (n == 0){
		return 1;
	}
	return a * power(a,n - 1);
}

//return the maximum value in an array of integers
//param anArray – the array in concern
//param n – no of elements in anArray
int maxArray(const int anArray[], int n){
	//If Size = 1
	if (n == 1){
		return anArray[0];	//Return value in array
	}
	//Get the maximum value that is obtained after recursion
	int max = maxArray(anArray, n - 1);
	//Check if max value is higher than that of value in the current array cell
	if (max > anArray[n - 1])
		return max;	//Return max value if larger
	else
		return anArray[n - 1];	//Return value in current array cell otherwise
}


int main(){
	//Qn 1
	int startVal = 10;
	int startPow = 3;

	cout << "Starting Value: " << startVal << " Starting Power: " << startPow << endl;
	cout << "Result: " << power(startVal, startPow) << endl;

	//Qn 2
	int startArr[] = { 3, 6, 4, 8, 5, 1, 10, 49 ,67};
	cout << endl;
	cout << "Integers in Array: ";
	for (int i : startArr){
		cout << i << " ";
	}
	int size = sizeof(startArr) / sizeof(*startArr);
	cout << endl << "Size of Array: " << size << endl;
	cout << "Maximum Value in Integer Array: " << maxArray(startArr, size) << endl;
	return 0;
}