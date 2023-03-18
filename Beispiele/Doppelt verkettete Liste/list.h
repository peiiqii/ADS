#pragma once
#include "node.h"

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList(); //Konstruktor
	~DoublyLinkedList(); //Destruktor

	void insertFront(int key); //Einf�gen eines Knotens am Anfang
	void insertBack(int key); //Einf�gen eines Knotens am Ende
	void insertAfter(Node* node, int key); //Einf�gen nach einem bestimmten Knoten

	void remove(Node* delNode); //L�schen eines bekannten Knotens aus der Liste
	bool search(int key); //Suche nach Listenelement
	void print(); //Ausgaben der Liste
	int anzahl(); //L�nge der Liste
	void printReverse(); //die Liste r�ckw�rts ausgeben
};