#include <iostream>
#include "List.h"
#include "Person.h"

using namespace std;

//Display the Main Menu
void mainMenu(){
	cout << "---------------- Main Menu -------------------" << endl;
	cout << "[1]     List the phone numbers" << endl;
	cout << "[2]     Add a new contact" << endl;
	cout << "[3]     Remove a contact  " << endl;
	cout << "[4]     Search for a phone number " << endl;
	cout << "[0]     Exit " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter your option : ";
}

//Error Message
void error(){
	cout << "INVALID SELECTION. Please select a valid option." << endl;
}

//List everything in list
void ListAllContacts(List& list){
	ItemType data;
	for (int i = 1; i <= list.getLength(); i++){
		data = list.get(i);
		cout << i << ") Name: " << data.getName() << " Tel No: " << data.getTel() << endl;
	}
}

//Add a new contact to list
void AddContact(List& list){
	Person toAdd;
	string input;
	cout << "Enter new Person's Name: ";
	getline(cin, input);
	toAdd.setName(input);
	cout << "Enter new Person's Telephone No: ";
	cin >> input;
	toAdd.setTel(input);
	list.add(toAdd);
	cout << toAdd.getName() << " with telephone number " << toAdd.getTel() << " has been added!";
}

void RemoveContact(List& list){
	ListAllContacts(list);
	int value;
	cout << "Select a contact to remove: ";
	cin >> value;
	if (value <= list.getLength() && value > 0) {
		ItemType data;
		data = list.get(value);
		list.remove(value);
		cout << "Contact " << data.getName() << " with telephone number " << data.getTel() << " has been removed!" << endl;
	}
	else {
		cout << "Error removing contact!" << endl;
	}
}

void SearchContact(List& list){
	string searchQuery;
	cout << "Enter phone number to find: ";
	cin >> searchQuery;
	ItemType data;
	int index = -1;
	for (int i = 1; i <= list.getLength(); i++){
		data = list.get(i);
		if (data.getTel() == searchQuery){
			index = i;
			break;
		}
	}

	if (index == -1){
		cout << "Unable to find any results from the phone number " << searchQuery << "!" << endl;
		return;
	}

	data = list.get(index);
	cout << "Found a person with phone number " << searchQuery << endl;
	cout << "Person Name: " << data.getName() << " ,Phone Number: " << data.getTel() << endl;
}


// Main loop. Must be placed last else will error with identifier not found.
int main(){
	List contacts;
	//Insert Default Values
	Person p1("Tan See Kow", "1211111222");
	Person p2("Syafiqah Tan", "6590022333");
	contacts.add(p1);
	contacts.add(p2);

	while (true){
		int sel;
		mainMenu();
		cin >> sel;

		// Use up rest of line so that getLine doesn't skip
		string restOfLine;
		getline(cin, restOfLine);

		cout << endl;
		switch (sel){
		case 1: ListAllContacts(contacts);
			cout << endl;
			break;
		case 2: AddContact(contacts);
			cout << endl;
			break;
		case 3: RemoveContact(contacts);
			cout << endl;
			break;
		case 4: SearchContact(contacts);
			cout << endl; 
			break;
		case 0: exit(0);
			break;
		default: error();
			break;
		}

	}

	return 0;
}
