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
	}
};