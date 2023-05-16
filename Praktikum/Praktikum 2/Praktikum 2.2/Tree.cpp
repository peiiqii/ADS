/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

Tree::~Tree()
{
	if (anker != nullptr)
	{
		loeschen(anker);
	}
}

void Tree::loeschen(TreeNode* ptr) // Hilfsfunktion zum löschen für Destruktor
{
	if (ptr->getLeft() != nullptr)
	{
		loeschen(ptr->getLeft());
	}
	if (ptr->getRight() != nullptr)
	{
		loeschen(ptr->getRight());
	}
	delete ptr; 
}

void Tree::addNode(string Name, int Age, double Income, int PostCode) {
	int NodeOrderID = Age + (int)Income + PostCode;
	TreeNode* newNode = new TreeNode(NodeOrderID, currentNodeChronologicalID++, Name, Age, Income, PostCode, nullptr, nullptr);

	TreeNode* parent = nullptr;
	TreeNode* current = anker;

	if (current == nullptr) { //Baum leer
		anker = newNode;
	}
	else {
		//Suche durch den BST bis ein Nachfolger nicht belegt ist
		while (current != nullptr) {
			parent = current;
			if (NodeOrderID > current->getNodeOrderID()) current = current->getRight();
			else current = current->getLeft();
		}

		if (NodeOrderID > parent->getNodeOrderID()) parent->setRight(newNode); //Blatt wird rechts angefügt
		else parent->setLeft(newNode); //Blatt wird links angefügt
	}
}

bool Tree::deleteNode(int orderID) {
	TreeNode* ptr = anker; // zu löschende knoten
	TreeNode* ptr2 = anker;// minimum
	TreeNode* ptr3 = anker;// vorgänger ptr
	TreeNode* ptr4 = anker;// vorgänger ptr2

	if (anker == nullptr)
	{
		return false;
	}

	// Wurzel löschen
	if (anker->getNodeOrderID() == orderID)
	{
		if (anker->getRight() == nullptr && anker->getLeft() == nullptr) // Fall => kein Nachfolger
		{
			delete anker;
			anker = nullptr;
			return true;
		}
		if (anker->getRight() != nullptr && anker->getLeft() == nullptr) // Fall => 1 Nachfolger | anker hat einen rechten Nachfolger
		{
			ptr2 = anker->getRight();
			delete anker;
			anker = ptr2;
			return true;
		}
		if (anker->getLeft() != nullptr && anker->getRight() == nullptr) // Fall => 1 Nachfolger | anker hat einen linken Nachfolger
		{
			ptr2 = anker->getLeft();
			delete anker;
			anker = ptr2;
			return true;
		}
		if (anker->getLeft() != nullptr && anker->getRight() != nullptr) // Fall => anker hat 2 Nachfolger
		{
			ptr2 = anker->getRight();
			ptr3 = anker;
			while (ptr2->getLeft() != nullptr) // suchen nach Minimum des rechten Teilbaums
			{
				ptr3 = ptr2; // ptr3 is the parent of the minimum node
				ptr2 = ptr2->getLeft(); //the minimum node from right subtree
			}
			ptr2->setLeft(anker->getLeft()); // das Minimum vom rechten Teilbaum übernimmt die Folgewerte von Anker
			ptr3->setLeft(ptr2->getRight()); // Elternknoten von Minimum(ptr2) kriegt den rechten Teilbaum von Minimum(ptr2) an sein linkes

			if (anker->getRight() != ptr2) //incase getRight the minimum
			{
				ptr2->setRight(anker->getRight());
			}

			delete anker;
			anker = ptr2;
			return true;
		}
	}

	while (ptr->getNodeOrderID() != orderID) // der zu löschende Knoten wird gesucht
	{
		ptr3 = ptr; // elternknoten von ptr(Vorgänger des zu löschenden Knotens)
		if (orderID < ptr->getNodeOrderID()) // wenn kleiner nach links, ansonsten geht rechts
		{
			ptr = ptr->getLeft();
		}
		else
		{
			ptr = ptr->getRight();
		}
		if (ptr == nullptr) // falls nicht gefunden
		{
			return false;
		}
	}

	if (ptr->getNodeOrderID() == orderID) //gefunden 
	{
		if (ptr->getRight() == nullptr && ptr->getLeft() == nullptr) // Fall 1 => kein Nachfolger
		{
			if (ptr->getNodeOrderID() < ptr3->getNodeOrderID())
			{
				ptr3->setLeft(nullptr); // nach dem elternknoten des zu löschenden Knotens kommt ein nullptr 
			}
			else
			{
				ptr3->setRight(nullptr); // nach dem elternknoten des zu löschenden Knotens kommt ein nullptr 
			}
			delete ptr;
			return true;
		}
		if (ptr->getRight() != nullptr && ptr->getLeft() == nullptr) // Fall 2 => 1 Nachfolger | anker hat einen rechten Nachfolger
		{
			if (ptr->getNodeOrderID() < ptr3->getNodeOrderID())
			{
				ptr3->setLeft(ptr->getRight()); // der linke Nachfolger vom Elternknoten soll jetzt auf den rechten Nachfolger vom ptr zeigt
			}
			else
			{
				ptr3->setRight(ptr->getRight()); // der rechte Nachfolger vom Elternknoten soll jetzt auf den rechten Nachfolger vom ptr zeigt
			}
			delete ptr;
			return true;
		}
		if (ptr->getLeft() != nullptr && ptr->getRight() == nullptr) // Fall 2 => 1 Nachfolger | anker hat einen linken Nachfolger
		{
			if (ptr->getNodeOrderID() < ptr3->getNodeOrderID())
			{
				ptr3->setLeft(ptr->getLeft()); // der linke Nachfolger vom Elternknoten soll jetzt auf den linken Nachfolger vom ptr zeigt
			}
			else
			{
				ptr3->setRight(ptr->getLeft()); // der rechte Nachfolger vom Elternknoten soll jetzt auf den linken Nachfolger vom ptr zeigt
			}
			delete ptr;
			return true;
		}
		if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) // Fall 3 => hat 2 Nachfolger
		{
			ptr2 = ptr->getRight(); // suchen nach min. von rechtem Teilbaum
			ptr4 = ptr; // neuer knoten zum speichern des elternknoten vom minimum

			while (ptr2->getLeft() != nullptr)
			{
				ptr4 = ptr2; // elternknoten von dem minimum
				ptr2 = ptr2->getLeft();
			}
			ptr2->setLeft(ptr->getLeft()); // das min. vom rechten Teilbaum übernimmt die folgewerte von dem zu löschenden Knoten
			ptr4->setLeft(ptr2->getRight()); // elternknoten von ptr2 kriegt den rechten Teilbaum von ptr2 an sein linkes
			if (ptr->getRight() != ptr2)
			{
				ptr2->setRight(ptr->getRight());
			}

			if (ptr3->getRight() == ptr)
			{
				ptr3->setRight(ptr2); // elternknoten von ptr kriegt ptr als sein nächstes rechten
			}
			else
			{
				ptr3->setLeft(ptr2); // elternknoten von ptr kriegt ptr als sein nächstes linkes
			}
			delete ptr;
			return true;
		}
	}
}

bool Tree::TreeSearch(TreeNode* node, string name) {
	bool found = false;

	if (node == nullptr)
	{
		return found;
	}

	if (node->getName() == name)
	{
		found = true;
		cout << "NodeID: " << node->getNodeOrderID() << ", Name: " << node->getName()
			<< ", Alter: " << node->getAge() << ", Einkommen: " << node->getIncome()
			<< ", PLZ: " << node->getPostCode() << ", PosID: " << node->getNodeChronologicalID() << endl;
	}

	if (node->getLeft() != nullptr)
	{
		found = TreeSearch(node->getLeft(), name) || found; // sobald eins von beiden bedingungen zutrifft ist es wahr
	}

	if (node->getRight() != nullptr)
	{
		found = TreeSearch(node->getRight(), name) || found;
	}

	return found;
}

bool Tree::searchNode(string name) {
	return TreeSearch(anker, name);
}

void Tree::printPreorder(TreeNode* node) {
	if (node != nullptr) {
		cout << right << setw(5) << node->getNodeChronologicalID() << '|' << setw(23) << right << node->getName() << '|' << setw(9) << right << node->getAge() << '|'
			<< setw(17) << right << node->getIncome() << '|' << setw(19) << right << node->getPostCode() << '|' << node->getNodeOrderID() << endl;
		printPreorder(node->getLeft());
		printPreorder(node->getRight());
	}
}

void Tree::printAll() { //Anzeige des vollständigen Baums nach Preorder
	if (anker == nullptr)
		cout << "Kein Eintrag gefunden" << endl;
	else {
		cout << right << setw(5) << "ID" << '|' << setw(23) << right << "Name" << '|' << setw(9) << right << "Age" << '|'
			 << setw(17) << right << "Income" << '|' << setw(19) << right << "PostCode" << '|' << "OrderID" << endl;
		cout << "-----+-----------------------+---------+-----------------+-------------------+--------------" << endl;
		printPreorder(anker);
	}
}

void Tree::levelOrder() {
	cout << right << setw(5) << "ID" << '|' << setw(23) << right << "Name" << '|' << setw(9) << right << "Age" << '|'
		<< setw(17) << right << "Income" << '|' << setw(19) << right << "PostCode" << '|' << setw(7) << right << "OrderID" << '|' << setw(7) << right << "Level" <<endl;
	cout << "-----+-----------------------+---------+-----------------+-------------------+-------+-------" << endl;
	
	int level = 0;
	queue<TreeNode*> q;
	TreeNode* node = anker;
	if (node != nullptr) {
		q.push(node);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			cout << right << setw(5) << node->getNodeChronologicalID() << '|' << setw(23) << right << node->getName() << '|' << setw(9) << right << node->getAge() << '|'
				<< setw(17) << right << node->getIncome() << '|' << setw(19) << right << node->getPostCode() << '|' << setw(7) << right << node->getNodeOrderID() << '|' 
				<< setw(7) << right << level << endl;
			if (node->getLeft() != nullptr) {
				q.push(node->getLeft());
			}
			if (node->getRight() != nullptr) {
				q.push(node->getRight());
			}
			level++;
		}
	}
}