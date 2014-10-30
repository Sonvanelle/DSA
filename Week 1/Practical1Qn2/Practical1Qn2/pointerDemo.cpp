#include <iostream>

using namespace std;
int main(){
	long int value1 = 200000;																//Part A
	long int value2;																		//Part B
	long* longPtr;																			//Part C
	longPtr = &value1;																		//Part D
	cout << "Value in longPtr is: " << *longPtr << endl;									//Part E
	value2 = *longPtr;																		//Part F
	cout << "Value in longPtr is: " << *longPtr << endl;									//Part G (Value of Value 1 is printed)
	cout << "Value 1 is: " << value1 << endl;												//Part H
	cout << "Value in longPtr is: " << *longPtr << endl;									//Part I (Yes)
	longPtr = &value2;																		//Part K
	*longPtr += 2000;																		//Part J
	cout << "Value 1 is: " << value1 << ", Value 2 is: " << value2 << endl;					//Part L (Value of 2 changed, as its added by the pointer)
	return 0;
}