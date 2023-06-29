#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r; 
	}
};

class BinaryTree
{
public:
	Node* ROOT;
	BinaryTree()
	{
		ROOT = NULL; // Inisialisasi ROOT ke NULL
	}

	void insert(string element) // Memsukan node kedalam binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Untuk menyipkan memory untuk new node
		newNode->info = element; // Assign value to the data field of the new node
		newNode->leftchild = NULL; // Buat left child dari node baru ke NULL
		newNode->rightchild = NULL; // Buat right child dari node baru ke NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // Locate the node which will be the parent of the node to be inserted

		if (parent == NULL) // if the parent is NULL (Tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT 
			return; // Exit
		}

		if (element < parent->info) // if the value in the value in the data field of the new than that of the parent{
		{
			parent->leftchild = newNode; // membuat left child dari parent point ke new node
		}
		else if (element > parent->info) // if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newNode; // Make the right child of the parent point to the new node
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) 
	{
		//This function search the currentNode of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		{
			if (ROOT == NULL) {
				cout << "Tree is empty" << endl;
				return;
			}
			if (ptr != NULL) {
				inorder(ptr->leftchild);
				cout << ptr->info << " ";
				inorder(ptr->rightchild);
			}
		}

	}

	void preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr) {
		//Performs the postorder traversal of the tree
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	
	}
};

int main() {
	BinaryTree obj;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inordeer traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : " << endl;

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch) {
		case '1':
		{
			cout << "Enter a word : ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case'4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case'5':
			return 0;
		default:
		{
			cout << "Invalid option" << endl;
			break;
		}
		}
	}
}