#include "PriorityQueueArray.h"
#include <iostream>

PriorityQueueArray::PriorityQueueArray(int maxN)
{
	this->N = 0;
	this->size = maxN;
	this->pqItem = new PQItem[size];
}

PriorityQueueArray::~PriorityQueueArray() 
{
	delete[] pqItem;
}

bool PriorityQueueArray::empty() const
{
	return N == 0;
}

bool PriorityQueueArray::isFull() const
{
	return N == size;
}

void PriorityQueueArray::push_front(PQItem newItem) //Hinzufuegen eines neuen Elementes
{
	if (!isFull()) {
		pqItem[N] = newItem;
		N++;
	}
	else {
		std::cout << "ERROR: Priority Queue ist voll." << std::endl;
	}
}

PQItem PriorityQueueArray::pop_max() //Holen und Entfernen des Elementes mit hoechster Priorität
{
	PQItem maxItem{ -1,-1 };
	int	maxPrio = std::numeric_limits<int>::max();
	unsigned maxIdx = 0;
	for (unsigned i = 0; i < N; i++) {
		if (pqItem[i].prio < maxPrio) {
			maxItem = pqItem[i];
			maxPrio = maxItem.prio;
			maxIdx = i;
		}
	}
	// Elemente im Array aufrücken + O(n)
	for (unsigned i = maxIdx; i < N - 1; i++) {
		pqItem[i] = pqItem[i + 1];
	}
	N--;
	return maxItem;
}

void PriorityQueueArray::print() 
{
	std::cout << "PQArray: [ ";
	for (int i = 0; i < N; i++) {
		std::cout << "( " << pqItem[i].prio << " , " << pqItem[i].data << " ) ";
	}
	std::cout << " ]" << std::endl;
}
