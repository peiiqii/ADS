#pragma once
#include "node.h"

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList(); //Konstruktor
	~DoublyLinkedList(); //Destruktor

	void insertFront(int key); //Einfügen eines Knotens am Anfang
	void insertBack(int key); //Einfügen eines Knotens am Ende
	void insertAfter(Node* node, int key); //Einfügen nach einem bestimmten Knoten

	void remove(Node* delNode); //Löschen eines bekannten Knotens aus der Liste
	bool search(int key); //Suche nach Listenelement
	void print(); //Ausgaben der Liste
	int anzahl(); //Länge der Liste
	void printReverse(); //die Liste rückwärts ausgeben
};