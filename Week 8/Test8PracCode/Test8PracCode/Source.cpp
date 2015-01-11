#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main(){
	string intStr;
	cout << "Enter a string of ONLY integers (seperated by ONE space each)" << endl;
	getline(cin, intStr);

	BST root;
	string tmp;
	for (int i = 0; i < intStr.length(); i++){
		//cout << "DEBUG CHAR: " << intStr[i] << endl;
		if (intStr[i] == ' '){
			//cout << "DEBUG STOI: " << stoi(tmp) << endl;
			root.insert(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += intStr[i];
		}
	}
	root.insert(stoi(tmp));

	cout << "-----Inorder-----" << endl;
	root.inorder();
	cout << "-----------------" << endl;

	cout << "-----Preorder-----" << endl;
	root.preorder();
	cout << "------------------" << endl;

	cout << "-----Postorder-----" << endl;
	root.postorder();
	cout << "-------------------" << endl;

	cout << "Total Number of Nodes in Binary Tree: " << root.countNodes() << endl;
	cout << "Total Height of Binary Tree: " << root.getHeight() << endl;
	if (root.isBalanced())
		cout << "Is Binary Tree Balanced?: True" << endl;
	else
		cout << "Is Binary Tree Balanced?: False" << endl;
	return 0;
}