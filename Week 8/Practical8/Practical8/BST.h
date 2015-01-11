// BST.h

#include<string>	// for string items

typedef int ItemType;

class BST{

	struct BinaryNode
	{
		ItemType   item;		// data item
		BinaryNode *left;	// pointer pointing to left subtree
		BinaryNode *right;	// pointer pointing to right subtree
	};

	// search an item in the binary search tree
	BinaryNode* search(BinaryNode* t, ItemType target);

	// add an item to the binary search tree
	void insert(BinaryNode* &t, ItemType item);

	// delete an item from the binary search tree
	void remove(BinaryNode* &t, ItemType item);

	// traverse the binary search tree in inorder
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder(BinaryNode* t);

	// compute the height of the binary search tree
	int getHeight(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty(BinaryNode* t);

	// check if the binary search tree is balanced
	bool isBalanced(BinaryNode* t);

};