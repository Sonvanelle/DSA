//Recieves input of 5 digit integer, split to individual digit and print them seperated from one another by 3 spaces

#include <iostream>
using namespace std;
int main(){
	int num;
	cout << "Enter 5 Digit Number: " << endl;
	cin >> num;
	

	//Get first digit from left
	int digit1 = num / 10000; 
	num = num % 10000;
	int digit2 = num / 1000;
	num = num % 1000;
	int digit3 = num / 100;
	num = num % 100;
	int digit4 = num / 10;
	num = num % 10;	//Last Digit
	cout << digit1 << "   " << digit2 << "   " << digit3 << "   " << digit4 << "   " << num << endl;

	return 0;
}