#pragma once

class PQItem {
public:
	int data;
	int prio;
};

class PriorityQueueArray {
private:
	PQItem* pqItem; // Zeiger auf Array
	int N;			// Anzahl items in PQ
	int size;		// PQ Groesse

public:
	PriorityQueueArray(int maxN);
	~PriorityQueueArray();
	bool empty() const;
	bool isFull() const;
	void push_front(PQItem newItem); // Hinzufuegen eines neuen Elementes
	PQItem pop_max(); // Holen und Entfernen des Elementes mit hoechster Priorität
	void print();
};
