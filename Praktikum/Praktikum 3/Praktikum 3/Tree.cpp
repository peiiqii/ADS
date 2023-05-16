#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include "Tree.h"
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

/**
 * Rekursive Hilfsfunktion f�r die Suche nach einem Knoten mittels Namensvergleich.
 * Da der Name kein Alleinstellungsmerkmal ist, muss der gesamte Baum in Preorder durchlaufen und gepr�ft werden.
 * Eine Score ermittelt die Fundh�ufigkeit eines Namens.
 *
 * \param[in] node Aktueller Knoten im Baum
 * \param[in] Name String nach dem gesucht wird
 * \param[out] score Anzahl der gefundenen Knoten mit entsprechendem Namen
 */
void searchNode_RecHelper(TreeNode* node, std::string Name, int &score)
{
	if (node->getName() == Name)
	{
		node->print();
		score++;
	}
	if (node->getLeft() != nullptr)
		searchNode_RecHelper(node->getLeft(), Name, score);
	if (node->getRight() != nullptr)
		searchNode_RecHelper(node->getRight(), Name, score);
}

/**
 * Rekursive Suche nach Knoten (preorder)
 *
 * \string Name Der String der im Baum gesucht werden soll
 */
bool Tree::searchNode(std::string Name) 
{
	if (anker == nullptr) return false;
	
	int search_score = 0;
	searchNode_RecHelper(anker, Name, search_score);
	
	if(search_score > 0) return true;
	
	return false;
}

/**
 * Ausgabe aller Knoten in Tabellenform Levelorder-BST
 *
 */
void Tree::printAll() //Levelorder-BST
{ //preorder
	if (anker == nullptr)
		cout << "Kein Eintrag gefunden" << endl;
	else {
		TreeNode* run = anker;
		cout << left << setw(11) << "NodeOrderID" << '|' << setw(15) << left << "Name" << '|' << setw(7) << left << "Age" << '|'
			<< setw(12) << left << "Income" << '|' << setw(14) << left << "PostCode" << '|' << "OrderID" << endl;
		cout << "-----------+---------------+-------+------------+--------------+---------+" << endl;
		print_preorder(anker);
	}
}

void Tree::print_preorder(TreeNode* temp){
	if (temp != nullptr) {
		temp->print();
		print_preorder(temp->getLeft());
		print_preorder(temp->getRight());
	}
}

void Tree::printLevel()
{
	cout << left << setw(11) << "NodeOrderID" << '|' << setw(15) << left << "Name" << '|' << setw(7) << left << "Age" << '|'
		<< setw(12) << left << "Income" << '|' << setw(14) << left << "PostCode" << '|' << "Red" << endl;
	cout << "-----------+---------------+-------+------------+--------------+---------+" << endl;

	if (anker == nullptr)
	{
		cout << "leerer Baum";
		return;
	}
	else
	{
		TreeNode* ausgabe = anker;
		std::queue<TreeNode*> aktuell;

		aktuell.push(ausgabe);

		while (!aktuell.empty()) {

			ausgabe = aktuell.front();
			aktuell.pop();

			ausgabe->printColor();

			if (ausgabe->getLeft() != nullptr)
			{
				aktuell.push(ausgabe->getLeft());
			}

			if (ausgabe->getRight() != nullptr)
			{
				aktuell.push(ausgabe->getRight());
			}
		}
	}
}

bool Tree::ist4erKnoten(TreeNode* node)
{
	if (!node->getRed())
	{
		if (node->getLeft() && node->getLeft()->getRed())
		{
			if (node->getRight() && node->getRight()->getRed())
			{
				return true;
			}
		}
	}
	return false;
}

bool Tree::split4Node(TreeNode* split)
{
	if (split == nullptr)
		return false;

	if (ist4erKnoten(split))
	{
		if (split == anker)  split->setRed(false);
		else split->setRed(true); // Elternknoten wird auf rot gesetzt
	
		split->getLeft()->setRed(false);
		split->getRight()->setRed(false);

		return true;
	}
	return false;
}

int Tree::proofRBCriterion() // überprüft Schwarzausgeglichenheit
{
	return proofRB(anker);
}

int Tree::proofRB(TreeNode* p) {
	int leftHeight = 0;
	int rightHeight = 0;

	if (p == nullptr) {
		return -1;
	}
	else {
		TreeNode* l_kind = p->getLeft();
		TreeNode* r_kind = p->getRight();

		if (!l_kind && !r_kind) // Kein Nachfolger - ein Blattknoten
			return 0;
		else if (l_kind && r_kind)
		{
			if (l_kind->getRed() && r_kind->getRed()) // Beide Nachfolger rot
			{
				leftHeight = proofRB(l_kind);
				rightHeight = proofRB(r_kind);
				if (leftHeight == rightHeight)
					return leftHeight;
				else return -1;
			}

			else if (!l_kind->getRed() && !r_kind->getRed()) //Beide Nachfolger schwarz
			{
				leftHeight = proofRB(l_kind);
				rightHeight = proofRB(r_kind);
				if (leftHeight == rightHeight)
					return leftHeight + 1;
				else return -1;
			}

			else if (!l_kind->getRed() && r_kind->getRed()) // Einer der Nachfolger ist rot
			{
				rightHeight = proofRB(r_kind);
				leftHeight = proofRB(l_kind);
				if (rightHeight - leftHeight == 1)
					return rightHeight;
				else return -1;
			}
			else if (l_kind->getRed() && !r_kind->getRed()) {
				rightHeight = proofRB(r_kind);
				leftHeight = proofRB(l_kind);
				if (leftHeight - rightHeight == 1)
					return leftHeight;
				else return -1;
			}
		}
		else if (!l_kind && r_kind) // Nur rechter Nachfolger
		{
			rightHeight = proofRB(r_kind);

			if (r_kind->getRed())
				return rightHeight;
			else
				return rightHeight + 1;

		}
		else if (l_kind && !r_kind) // Nur Linker Nachfolger
		{
			leftHeight = proofRB(l_kind);

			if (l_kind->getRed())
				return leftHeight;
			else
				return leftHeight + 1;

		}
	}
}

void Tree::balance(TreeNode* tree) {

	if (tree != nullptr)
	{
		balance(tree->getLeft());
		balance(tree->getRight());
		//fehler
		if (tree->getRed() && tree->getParent()->getRed()) //2 nacheinander folgende rote Knoten 
		{

			TreeNode* node = tree;
			TreeNode* p = tree->getParent();
			TreeNode* pp = tree->getParent()->getParent();

			if (pp->getRight() == p && p->getRight() == node) //Linksrotation
			{
				rotateTreeLeft(pp, p);
			}
			if (pp->getLeft() == p && p->getLeft() == node) //Rechtsrotation
			{
				rotateTreeRight(pp, p);
			}
			if (pp->getLeft() == p && p->getRight() == node) //Links-Rechts Rotation
			{
				rotateTreeLeft(p, node);
				rotateTreeRight(pp, node);
			}
			if (pp->getRight() == p && p->getLeft() == node) //Rechts-Links Rotation
			{
				rotateTreeRight(p, node);
				rotateTreeLeft(pp, node);
			}
		}
	}
}

bool Tree::rotateTreeRight(TreeNode* p1, TreeNode* p2)
{
	TreeNode* pparent = p1->getParent();
	TreeNode* p1_temp = p1;
	TreeNode* p2_temp = p2;

	if (pparent == nullptr) // Wenn der Anker rotiert werden soll
	{
		if (p2->getRight() != nullptr)
		{
			// der rechte Nachfolger von p2 wird als linker Nachfolger von p1 gesetzt
			p2->getRight()->setParent(p1_temp);
			p1_temp->setLeft(p2->getRight());
		}
		else
		{
			p1_temp->setLeft(nullptr);
		}

		p2_temp->setParent(nullptr);
		p2_temp->setRight(p1_temp);
		p1_temp->setParent(p2_temp);

		p1_temp->setRed(true);
		p2_temp->setRed(false); //P2 als Wurzel muss schwarz sein

		anker = p2_temp;

		return true;
	}

	p1->setLeft(p2->getRight());
	p2->setRight(p1);

	if (pparent->getNodeOrderID() > p2->getNodeOrderID())
	{
		pparent->setLeft(p2);
	}
	else
	{
		pparent->setRight(p2);
	}

	p2->setParent(pparent);
	p1->setParent(p2);

	p2->setRed(false);
	p1->setRed(true);

	return true;
}

bool Tree::rotateTreeLeft(TreeNode* p1, TreeNode* p2) {
	TreeNode* Parent = p1->getParent();
	TreeNode* p1_temp = p1;
	TreeNode* p2_temp = p2;

	if (Parent == nullptr) // Wenn der Anker rotiert werden soll
	{
		if (p2->getLeft() != nullptr)
		{
			p2->getLeft()->setParent(p1_temp);
			p1_temp->setRight(p2->getLeft());
		}
		else
		{
			p1_temp->setRight(nullptr);
		}

		p2_temp->setParent(nullptr);
		p2_temp->setLeft(p1_temp);
		p1_temp->setParent(p2_temp);

		p1_temp->setRed(true);
		p2_temp->setRed(false);

		anker = p2_temp;

		return true;
	}
	p2 = p1->getRight();
	p1->setRight(p2->getLeft());
	p2->setLeft(p1);
	if (Parent->getNodeOrderID() > p2->getNodeOrderID())
	{
		Parent->setLeft(p2);
	}
	else
	{
		Parent->setRight(p2);
	}

	p2->setParent(Parent);
	p1->setParent(p2);

	p2->setRed(false);
	p1->setRed(true);

	return true;
}

bool Tree::addNode(string name, int age, double income, int postCode)
{
	int NodePosID = age + postCode + (int)income;
	TreeNode* newnode = new TreeNode(NodePosID, CurrentNodeChronologicalID++, name, age, income, postCode);
	newnode->setRed(true);

	TreeNode* temp = anker;

	if (anker == nullptr)//Fall 1: Neuer Knoten = anker
	{
		anker = newnode;
		newnode->setRed(false);
		return true;
	}
	while (1)
	{
		split4Node(temp);

		if (temp->getNodeOrderID() < newnode->getNodeOrderID()) //Fall 2: Neuer Knoten rechts am Baum einfügen
		{
			if (temp->getRight() != nullptr)
			{
				temp = temp->getRight();
			}
			else {
				temp->setRight(newnode);
				newnode->setParent(temp);
				balance(anker); //prüft 2 aufeinanderfolgende rote Knoten

				return true;
			}
		}
		else //Fall 3: Neuer Knoten links am Baum einfügen
		{
			if (temp->getLeft() != nullptr)
			{
				temp = temp->getLeft();
			}
			else
			{
				temp->setLeft(newnode);
				newnode->setParent(temp);
				balance(anker);

				return true;
			}
		}
	}
	return false;
}

void Tree::printLevelOrder()
{
	TreeNode* root = anker;

	queue<TreeNode*> q; //node Queue ( nur schwarze Knoten )
	queue<int> nq; //Niveau queue

	if (root == nullptr) {
		cout << "Baum ist leer." << endl;
		return;
	}

	// Wurzelknoten und Startniveau in die Queues einlegen
	q.push(root);
	nq.push(0);

	int prev_niveau = -1; //Niveauwechseln merken
	int niveau;

	while (!q.empty())
	{
		// Entnahme aus den Queues und löschen 
		TreeNode* curr = q.front();
		q.pop();
		niveau = nq.front();
		nq.pop();


		// Ausgabe für den Niveauwechsel 
		if (prev_niveau != niveau) {
			cout << endl << "Niveau " << niveau << ": ";
			prev_niveau = niveau;
		}

		cout << "( " << ((curr->getLeft()) ? to_string(curr->getLeft()->getNodeOrderID()) + ", " : "") << curr->getNodeOrderID() << ((curr->getRight()) ? ", " + to_string(curr->getRight()->getNodeOrderID()) : "") << " ) ";

		//Schwarze Nachfolger von den roten Knoten in die Queue einlegen -> niveau + 1
		if (!curr->getRed())
		{
			if (curr->getLeft() && curr->getLeft()->getLeft()) {
				q.push(curr->getLeft()->getLeft());
				nq.push(niveau + 1);
			}
			if (curr->getLeft() && curr->getLeft()->getRight()) {
				q.push(curr->getLeft()->getRight());
				nq.push(niveau + 1);
			}
			if (curr->getRight() && curr->getRight()->getLeft()) {
				q.push(curr->getRight()->getLeft());
				nq.push(niveau + 1);
			}
			if (curr->getRight() && curr->getRight()->getRight()) {
				q.push(curr->getRight()->getRight());
				nq.push(niveau + 1);
			}
		}
		else {
			if (curr->getLeft()) {
				q.push(curr->getLeft());
				nq.push(niveau + 1);
			}
			if (curr->getRight()) {
				q.push(curr->getRight());
				nq.push(niveau + 1);
			}
		}
	}
	cout << endl;
	return;
}

void Tree::printLevelOrder(int pos)
{
	TreeNode* root = anker;
	queue<TreeNode*> q;
	queue<int> nq;

	if (root == nullptr)
	{
		cout << "Baum ist leer" << endl;
		return;
	}

	// Wurzelknoten und Startniveau in die Queues pushen 
	q.push(root);
	nq.push(0);

	int prev_niveau = -1;
	int niveau;

	while (!q.empty())
	{
		// Entnahme aus den Queues und löschen 
		TreeNode* curr = q.front();
		q.pop();
		niveau = nq.front();
		nq.pop();

		// Ausgabe für den Niveauwechsel 
		if (prev_niveau != niveau)
		{
			if (niveau == pos)
				cout << "Niveau " << niveau << ": ";
			prev_niveau = niveau;
		}

		if (niveau == pos)
			cout << "( " << ((curr->getLeft()) ? to_string(curr->getLeft()->getNodeOrderID()) + " | " : "") << curr->getNodeOrderID() << ((curr->getRight()) ? " | " + to_string(curr->getRight()->getNodeOrderID()) : "") << " ) ";
		if (niveau > pos)
			return;

		if (!curr->getRed()) {
			if (curr->getLeft() && curr->getLeft()->getLeft()) {
				q.push(curr->getLeft()->getLeft());
				nq.push(niveau + 1);
			}
			if (curr->getLeft() && curr->getLeft()->getRight()) {
				q.push(curr->getLeft()->getRight());
				nq.push(niveau + 1);
			}
			if (curr->getRight() && curr->getRight()->getLeft()) {
				q.push(curr->getRight()->getLeft());
				nq.push(niveau + 1);
			}
			if (curr->getRight() && curr->getRight()->getRight()) {
				q.push(curr->getRight()->getRight());
				nq.push(niveau + 1);
			}
		}
		else {
			if (curr->getLeft()) {
				q.push(curr->getLeft());
				nq.push(niveau + 1);
			}

			if (curr->getRight()) {
				q.push(curr->getRight());
				nq.push(niveau + 1);
			}
		}
	}
	cout << endl;
	return;
}