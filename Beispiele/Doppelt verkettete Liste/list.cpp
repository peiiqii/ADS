#include <iostream>
#include "list.h"

DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {

}

void DoublyLinkedList::insertFront(int key) {
	Node* newNode = new Node(key);
	newNode->next = head;
	newNode->prev = nullptr;
	if (head != nullptr) 
		head->prev = newNode;
	head = newNode;
}

void DoublyLinkedList::insertBack(int key) {
	Node* newNode = new Node(key);
	newNode->prev = tail;
	newNode->next = nullptr;
	if (tail != nullptr)
		tail->next = newNode;
	tail = newNode;
}

void DoublyLinkedList::insertAfter(Node* node, int key) {
	Node* newNode = new Node(key);

	if (node->next != nullptr) {
		node->next->prev = newNode;
	}
	else {
		tail = newNode;
	}
	newNode->next = node->next;
	node->next = newNode;
	newNode->prev = node;
}

void DoublyLinkedList::remove(Node* delNode) {
	if (delNode->prev == nullptr) { //Fall 1: delNode ist der erster Knoten == head
		head = delNode->next;
	}
	else { //Fall 2: delNode ist nicht der erste Knoten
		delNode->prev->next = delNode->next;
	}
	if (delNode->next != nullptr) {
		delNode->next->prev = delNode->prev;
	}
	else {
		tail = delNode->prev;
	}
	delete delNode;
}

bool DoublyLinkedList::search(int key) {
	Node* newNode = head;
	while (newNode != nullptr && newNode->key != key) newNode = newNode->next;
	if (newNode == nullptr) return false; //Element nicht in der Liste
	return true;
}

void DoublyLinkedList::print() {
	Node* temp = head;
	std::cout << "Doubly Linked List: ";
	while (temp != nullptr) {
		if (temp->next == nullptr) {
			std::cout << temp->key << std::endl;
		}
		else {
			std::cout << temp->key << " <--> ";
		}
		temp = temp->next;
	}
}

int DoublyLinkedList::anzahl() {
	Node* temp = head;
	int anzahl = 0;
	while (temp != nullptr) {
		anzahl++;
		temp = temp->next;
	}
	return anzahl;
}

void DoublyLinkedList::printReverse() {
	Node* temp = tail;
	std::cout << "Reversed Doubly Linked List: ";
	while (temp != nullptr) {
		if (temp->prev == nullptr) {
			std::cout << temp->key << std::endl;
		}
		else {
			std::cout << temp->key << " <--> ";
		}
		temp = temp->prev;
	}
}