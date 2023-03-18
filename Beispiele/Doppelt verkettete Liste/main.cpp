#include "list.h"
#include <iostream>
using namespace std;

int main() {
	DoublyLinkedList myList; //create an empty LinkedList

	//add first node
	Node* first = new Node();
	first->key = 9;
	first->next = nullptr;
	first->prev = nullptr;
	myList.head = first;
	myList.tail = first;

	myList.insertAfter(first, 16);
	myList.insertBack(1);
	myList.insertBack(4);

	myList.remove(first);
	myList.insertFront(9);
	myList.print();

	cout << myList.anzahl() << endl;
	myList.printReverse();
}