#include "BST.h"
#include <iostream>
#include <algorithm>

using namespace std;

BST::BinaryNode* BST::search(BinaryNode* t, ItemType target){
	//If t is empty
	if (t == NULL){
		return NULL;
	}
	else {
		if (t->item == target){
			//Found item
			return t;
		}
		else {
			if (target < t->item){
				//Search left subtree
				return search(t->left, target);
			}
			else {
				//Search right subtree
				return search(t->right, target);
			}
		}
	}
}

void BST::insert(BinaryNode* &t, ItemType item){
	//If t is empty
	if (t == NULL){
		BinaryNode *newNode = new BinaryNode;	//Create new node
		newNode->item = item;					//Assign item to node
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;							//Assign new node to t
	}
	else {
		if (item < t->item){
			//Insert in left subtree
			insert(t->left, item);
		}
		else {
			//Insert in right subtree
			insert(t->right, item);
		}
	}
}

void BST::remove(BinaryNode* &t, ItemType item){
	//Search for node to be deleted
	BinaryNode* current = t;
	BinaryNode* parentNode = NULL;
	bool isLeftChild = false;
	bool found = false;

	//While node is not found and the current tree has not ended
	while ((!found) && (current != NULL)){
		if (item == current->item){
			found = true;
		}
		else {
			parentNode = current;
			//Go to next level of node
			if (item < current->item){
				//Go to the left subtree
				current = current->left;
				isLeftChild = true;
			}
			else {
				//Go to the right subtree
				current = current->right;
				isLeftChild = false;
			}
		}
	}


	//Check if the targeted node to remove exists and has been found
	if (found){
		//If node has 0 child (aka a leaf) (Case 1)
		if (current->left == NULL && current->right == NULL){
			//Check if leaf node is the root node (main node)
			if (current == t){
				//remove
				t = NULL;
			}
			else {
				if (isLeftChild){
					//Leaf is the left child of the parent
					parentNode->left = NULL;
				}
				else {
					//Leaf is the right child of the parent
					parentNode->right = NULL;
				}
			}
		}
		//If node has 1 child (Case 2)
		//If node has a right child
		else if (current->left == NULL){
			//Set parent node to point to the node's child
			//Check which subtree is the removed node in
			if (isLeftChild)
				parentNode->left = current->right;
			else
				parentNode->right = current->right;
		}
		//If node has left child
		else if (current->right == NULL){
			//Repeat same steps as when child is right except pointing left node instead
			if (isLeftChild)
				parentNode->left = current->left;
			else
				parentNode->right = current->left;
		}
		//If node has 2 childs (Case 3)
		else {
			//Get the successor (rightmost child of the left subtree of removed node)
			BinaryNode* successor = current->left;
			while (successor->right != NULL){
				successor = successor->right;
			}
			//Store item of the successor in temp var
			ItemType tmp = successor->item;

			//Remove successor recursively (based on case 1/2)
			remove(t, tmp);

			//Replace the current node item with the item in temp var
			current->item = tmp;
		}
	}
}

bool BST::isEmpty(BinaryNode* t){
	return (t == NULL);
}

/*Following stuff are essentially the same thing besides the order*/

void BST::inorder(BinaryNode* t){
	//Order: Left - Root - Right
	//Check if t is empty
	if (t != NULL){
		//Go to left node
		inorder(t->left);
		//Print current node
		cout << t->item << endl;
		//Go to right node
		inorder(t->right);
	}
}

void BST::preorder(BinaryNode* t){
	//Order: Root - Left - Right
	if (t != NULL){
		cout << t->item << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

void BST::postorder(BinaryNode* t){
	//Order: Left - Right - Root
	if (t != NULL){
		postorder(t->left);
		postorder(t->right);
		cout << t->item << endl;
	}
}

/*Questions in Practical*/
//Qn 1
int BST::countNodes(BinaryNode* t){
	int count = 0;
	//Check if node is not null
	if (t != NULL){
		//Recursively sum up the count of the subtrees including root node
		//Essentially it will be (root node (1)) + (left subtree of root recursive count) + (right subtree of root recursive count)
		count = 1 + countNodes(t->left) + countNodes(t->right);
	}

	//Return the number of nodes total
	return count;
}

//Qn 2 (Not sure if allowed to use max from the algorithm namespace)
int BST::getHeight(BinaryNode* t){
	//Check if node is null (based on num of nodes. if by links, return -1)
	if (t == NULL)
		return 0;
	else
		return max(getHeight(t->left), getHeight(t->right)) + 1;
}

//Qn 3
bool BST::isBalanced(BinaryNode* t){
	//Initialize var for height of left an right subtrees of root
	int leftTreeHeight = 0;
	int rightTreeHeight = 0;

	//Check if node is empty
	if (t == NULL)
		return true;	//As node is empty -> Balanced

	//Get height of both subtrees
	leftTreeHeight = getHeight(t->left);
	rightTreeHeight = getHeight(t->right);

	//Get absolute value of the difference of the height of both subtrees
	int diffInHeight = abs(leftTreeHeight - rightTreeHeight);

	//If height difference is less or equal to 1 for the root and its respective child nodes
	if (diffInHeight <= 1 && isBalanced(t->left) && isBalanced(t->right))
		return true;		//It is balanced

	return false;			//Not balanced
}