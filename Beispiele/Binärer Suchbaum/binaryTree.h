#pragma once
#include "TreeNode.h"
#include <iostream>
using namespace std;

class BinaryTree {
private:
	TreeNode* root; 

	//Traversierungsmethoden
	void printInorder(TreeNode* k);
	void printPreorder(TreeNode* k);
	void printPostorder(TreeNode* k);
	void printLevelorder(TreeNode* k);

	//Suchen im BST
	TreeNode* TreeSearch(TreeNode* x, int k); //rekursive Suche im BST
	TreeNode* IterativeTreeSearch(TreeNode* x, int k); //iterative Suche im BST
	TreeNode* MinimumTreeSearch(TreeNode* x); //minimum Suche im BST
	TreeNode* MaximumTreeSearch(TreeNode* x); //maximum Suche im BST
	bool SearchNode(TreeNode* node, int k); //search method that returns boolean

	void deleteTreeNode(TreeNode* k); //löscht alle Knoten im BST
	void insertNode(const int& key, TreeNode* parent);

public:
	BinaryTree(); //Konstruktor
	~BinaryTree(); //Destruktor: löscht alle Knoten

	//Einfügen im BST
	void insert(int key); //iterativ
	void add(const int& key) { insertNode(key, root); } //rekursiv

	int get(int key);			  //Knoten suchen
	bool removeNode(int key);	  //Knoten entfernen

	//Traversierungsmethoden
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelorder();
};

