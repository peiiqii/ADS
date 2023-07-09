#include "PriorityQueueArray.h"
#include <iostream>

int main() 
{
	const unsigned capacity = 8;

	// Priority Queue auf Basis eines Arrays  -----------------------------------------------------------------
	PriorityQueueArray PQArray(capacity);
	PQArray.push_front(PQItem{ 26, 6 });
	PQArray.push_front(PQItem{ 34, 99 });
	PQArray.push_front(PQItem{ 26, 4 });
	PQArray.push_front(PQItem{ 23, 2 });
	PQArray.push_front(PQItem{ 12, 1 });
	PQArray.push_front(PQItem{ 43, 7 });
	PQArray.push_front(PQItem{ 23, 9 });
	PQArray.print();

	auto maxElem = PQArray.pop_max();
	std::cout << "Element mit höchster Priorität entnehmen: PQItem( " << maxElem.prio << " , " << maxElem.data << ")" << std::endl << std::endl;
	PQArray.print();
	maxElem = PQArray.pop_max();
	std::cout << "Element mit höchster Priorität entnehmen: PQItem( " << maxElem.prio << " , " << maxElem.data << ")" << std::endl << std::endl;
	PQArray.print();
	std::cout << "\nNeues PQItem(24, 3) in PQArray einfügen" << std::endl;
	PQArray.push_front(PQItem{ 24, 3 });
	PQArray.print();
	std::cout << std::endl;
}