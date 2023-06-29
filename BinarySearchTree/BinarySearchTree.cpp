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
	}
};