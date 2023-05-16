/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

class Tree {
private: 
	TreeNode * anker;
	int CurrentNodeChronologicalID;

	//Hilfsfunktionen
	void loeschen(TreeNode* ptr);
	void print_preorder(TreeNode*);
	//bool search_recursive(TreeNode* ptr, std::string Name);
	bool ist4erKnoten(TreeNode*);
			
public:
	Tree() : anker(nullptr), CurrentNodeChronologicalID(0) {}
	~Tree();
	bool addNode(std::string Name, int Age, double Income, int PostCode);	
	bool searchNode(std::string);
	void printAll();
	void printLevel();
	void printLevelOrder();
	void printLevelOrder(int);

	void balance(TreeNode*);
	bool split4Node(TreeNode*);

	int proofRBCriterion();
	int proofRB(TreeNode*);

	bool rotateTreeRight(TreeNode*, TreeNode*);
	bool rotateTreeLeft(TreeNode*, TreeNode*);

	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
