class PQNode {
public:
	int data;
	int prio;
	PQNode* next;
};

class PriorityQueueList
{
private:
	
	PQNode* pqhead; // Zeiger auf 1. Listen-Element
public:
	PriorityQueueList();
	~PriorityQueueList();
	bool empty() const;
	void push_front(int item, int prio); // Hinzufuegen eines neuen Elementes
	PQNode pop_max(); // Element mit max. Prioritaet holen und entfernen
	void print();
};

#pragma once
