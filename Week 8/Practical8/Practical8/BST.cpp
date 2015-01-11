#include "BST.h"
#include <iostream>

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

}

//Qn 2
int BST::getHeight(BinaryNode* t){

}

//Qn 3
bool BST::isBalanced(BinaryNode* t){

}