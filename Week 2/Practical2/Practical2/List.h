// List.h - - Specification of List ADT
#include<string>
#include "Person.h"
const int MAX_SIZE = 100;

typedef Person ItemType;

class List
{
private:
	ItemType items[MAX_SIZE];
	int      size;

public:

	// constructor
	List::List();

	// add a new item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: new item is added to the back of the list
	//       size of list is increased by 1
	bool List::add(ItemType newItem);

	// add a new item at a specified position in the list (insert)
	// pre : 1 <= index <= size && size < MAX_SIZE
	// post: new item is added to the specified position in the list
	//       size of list is increased by 1
	bool List::add(int index, ItemType newItem);

	// remove an item at a specified position in the list
	// pre : 1 <= index <= size
	// post: item is removed the specified position in the list
	//       size of list is decreased by 1
	void List::remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 1 <= index <= size
	// post: none
	ItemType List::get(int index);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool List::isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int List::getLength();

};
