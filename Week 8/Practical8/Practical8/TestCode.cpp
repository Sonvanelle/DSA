#include <iostream>
#include "BST.h"

using namespace std;

int main(){
	cout << "Enter a string of ONLY integers (seperated by spaces)" << endl;
	string intStr;
	cin >> intStr;

	string tmp;
	for (int i = 0; i < intStr.length(); i++){

		if (intStr[i] == ' '){
			BST::insert(root, stoi(tmp))
			tmp = "";

		}
	}

	return 0;
}