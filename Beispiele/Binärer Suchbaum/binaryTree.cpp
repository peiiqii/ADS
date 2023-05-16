#include <iostream>
#include "binaryTree.h"
#include <queue>
using namespace std;

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	deleteTreeNode(root);
}

//löscht alle Knoten im BST
void BinaryTree::deleteTreeNode(TreeNode* k) {
	if (k != nullptr) {
		deleteTreeNode(k->left);
		deleteTreeNode(k->right);
		delete k;
	}
} 

//Suchen im BST
int BinaryTree::get(int key) {
	TreeNode* treenode = TreeSearch(root, key);
	//TreeNode* treenode = IterativeTreeSearch(root, key);
	
	if (treenode == nullptr) return -1;
	else return treenode->key;
}

TreeNode* BinaryTree::TreeSearch(TreeNode* x, int k) {//rekursive Suche im BST
	if (x == nullptr || k == x->key) return x;

	if (k < x->key) return TreeSearch(x->left, k);
	else return TreeSearch(x->right, k);
} 

TreeNode* BinaryTree::IterativeTreeSearch(TreeNode* x, int k) { //iterative Suche im BST
	while (x != nullptr && k != x->key) {
		if (k > x->key) x = x->right;
		else x = x->left;
	}
	return x;
}

bool BinaryTree::SearchNode(TreeNode* node, int value) {
	bool found = false;
	
	if (node == nullptr) return found;

	if (node->key == value) {
		found = true;
		cout << "Key " << node->key << " is found!" << endl;
	}

	//if value exists more than once in BST
	if (node->left != nullptr) {
		found = SearchNode(node->left, value) || found;
	}

	if (node->right != nullptr) {
		found = SearchNode(node->right, value) || found;
	}

	return found;
}

TreeNode* BinaryTree::MinimumTreeSearch(TreeNode* x) { //minimum Suche im BST
	while (x->left != nullptr ) {
		x = x->left;
	}
	return x;
}

TreeNode* BinaryTree::MaximumTreeSearch(TreeNode* x) { //maximum Suche im BST
	while (x->right != nullptr) {
		x = x->right;
	}
	return x;
}

//Einfügen eines neuen Knoten im BST (iterativ)
void BinaryTree::insert(int key) {
	TreeNode* treenode = new TreeNode();
	treenode->key = key;
	treenode->left = treenode->right = nullptr;

	TreeNode* parent = nullptr;	//parent von curr
	TreeNode* curr = root;		//aktualler Knoten im BST

	//Suche durch den BST bis ein Nachfolger nicht belegt ist
	while (curr != nullptr) {
		parent = curr;
		if (key > curr->key) curr = curr->right;
		else curr = curr->left;
	}

	//Fall 1: Baum ist leer
	if (root == nullptr) {
		root = treenode;
	}
	//Fall 2: Baum ist nicht leer
	else{
		if (key > parent->key) parent->right = treenode;	// Blatt wird rechts angefügt
		else parent->left = treenode;						// Blatt wird links angefügt
	}
}

//Einfügen eines neuen Knoten (rekursiv)
void BinaryTree::insertNode(const int& key, TreeNode* parent)
{
	TreeNode* newNode = new TreeNode();
	newNode->key = key;

	//BST leer
	if (parent == nullptr) {
		root = newNode;
	}
	else {
		if (key < parent->key) {
			if (parent->left == nullptr) {
				parent->left = newNode;
			}
			else insertNode(key, parent->left);
		}
		else {
			if (parent->right == nullptr) {
				parent->right = newNode;
			}
			else insertNode(key, parent->right);
		}
	}
}
        
//Traversierungs-Algorithmus
void BinaryTree::printInorder() {
	cout << "Inorder: ";
	printInorder(root);
	cout << endl;
}
void BinaryTree::printPreorder() {
	cout << "Preorder: ";
	printPreorder(root);
	cout << endl;
}
void BinaryTree::printPostorder() {
	cout << "Postorder: ";
	printPostorder(root);
	cout << endl;
}
void BinaryTree::printLevelorder() {
	cout << "Levelorder: ";
	printLevelorder(root);
	cout << endl;
}

void BinaryTree::printInorder(TreeNode* k){
	if (k != nullptr) {
		printInorder(k->left);
		cout << k->key << " ";
		printInorder(k->right);
	}
}
void BinaryTree::printPreorder(TreeNode* k){
	if (k != nullptr) {
		cout << k->key << " ";
		printInorder(k->left);
		printInorder(k->right);
	}
}
void BinaryTree::printPostorder(TreeNode* k){
	if (k != nullptr) {
		printInorder(k->left);
		printInorder(k->right);
		cout << k->key << " ";
	}
}
void BinaryTree::printLevelorder(TreeNode* k){
	queue<TreeNode*> q;
	TreeNode* node = root;
	if (node != nullptr) {
		q.push(node);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			cout << node->key << " ";
			if (node->left != nullptr) {
				q.push(node->left);
			}
			if (node->right != nullptr) {
				q.push(node->right);
			}
		}
	}
}

bool BinaryTree::removeNode(int key) {		// Knoten entfernen
	TreeNode* delNode = root;				//zu löschender Knoten
	TreeNode* parent_delNode = nullptr;     //parent von dem zu löschenden Knoten

	//zu löschender Knoten suchen
	while (delNode != nullptr && key != delNode->key) {
		parent_delNode = delNode;
		if (key < delNode->key) delNode = delNode->left;
		else delNode = delNode->right;
	}

	if (delNode == nullptr) return false; //nicht gefunden

	// Fall 1: Löschen eines Blattknoten 
	if (delNode->left == nullptr && delNode->right == nullptr) {
		if (parent_delNode != nullptr) {
			if (parent_delNode->left == delNode) parent_delNode->left = nullptr;
			else parent_delNode->right = nullptr;
		}
		else { //if the tree has only a root node
			root = nullptr;
		}
	}
	// Fall 2: Löschen eines Knotens mit nur 1 Nachfolger
	//nur rechter Nachfolger
	else if (delNode->left == nullptr && delNode->right != nullptr) {
		TreeNode* nachfolger = delNode->right;
		if (nachfolger->key < parent_delNode->key) parent_delNode->left = nachfolger;
		else parent_delNode->right = nachfolger;
		delete delNode;
	}
	//nur linker Nachfolger
	else if (delNode->left == nullptr && delNode->right != nullptr) {
		TreeNode* nachfolger = delNode->left;
		if (nachfolger->key < parent_delNode->key) parent_delNode->left = nachfolger;
		else parent_delNode->right = nachfolger;
		delete delNode;
	}
	// Fall 3: Löschen eines Knotens mit 2 Nachfolgern
	else {
		//ersetzen zu löschenden Knoten durch das Minimum im rechten Teilbaum
		TreeNode* temp = delNode;
		TreeNode* min = delNode->right;
		while (min->left != nullptr) {
			temp = min;
			min = min->left;
		}

		temp->left = min->right;
		min->left = delNode->left;		// Minimum links übernimmt linken Teilbaum von delNode
		min->right = delNode->right;

		//der zu löschende Knoten ist root
		if (parent_delNode == nullptr) {
			root = min;
		}
		else {
			if (parent_delNode->left == delNode) parent_delNode->left = min;
			else parent_delNode->right = min;
		}
		delete delNode;
	}
	return true;
}

bool BinaryTree::removeNode(int key) {
	//empty BST
	if (root == nullptr) return false;

	//Wurzel löschen
	if (root->key == key) {
		if (root->left == nullptr && root->right == nullptr) { //Fall 1: kein Nachfolger
			delete root;
			root = nullptr;
			return true;
		}
		else if (root->left == nullptr && root->right != nullptr) { //Fall 2: einen rechten Nachfolger
			TreeNode* c_delNode = root->right;
			delete root;
			root = c_delNode;
			return true;
		}
		else if (root->left != nullptr && root->right == nullptr) { //Fall 3: einen linken Nachfolger
			TreeNode* c_delNode = root->left;
			delete root;
			root = c_delNode;
			return true;
		}
		else if (root->left != nullptr && root->right != nullptr) { //Fall 4: zwei Nachfolger
			TreeNode* c_delNode = root->right;
			TreeNode* parent_c_delNode = root;
			while (c_delNode->left != nullptr) { //suchen nach MINIMUM DES RECHTEN TEILBAUM
				parent_c_delNode = c_delNode;
				c_delNode = c_delNode->left;
			}
			c_delNode->left = root->left;
			parent_c_delNode->left = c_delNode->right;

			if (root->right != c_delNode) {
				c_delNode->right = root->right;
			}

			delete root;
			root = c_delNode;
			return true;
		}
	}
	else {

	}
}