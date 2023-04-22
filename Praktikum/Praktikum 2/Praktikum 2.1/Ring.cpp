/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>
using namespace std;

Ring::Ring() {
	this->countNodes = 0;
	this->anker = nullptr;
}

void Ring::incrementAges()
{
	//increase oldAge of all nodes by 1 except for the anker(newly added node)
	RingNode* temp = anker->getNext();
	while (temp != anker) {
		temp->setAge(temp->getAge() + 1);
		temp = temp->getNext();
	}
}

void Ring::addNewNode(string Beschreibung, string Data) {
	RingNode* newNode = new RingNode(0, Beschreibung, Data);

	//if ring is empty -> newNode will be anker
	if (anker == nullptr) 
	{
		anker = newNode;
		anker->setNext(anker);
		countNodes++;
	}
	else if (countNodes < 6) //ring is not full
	{
		newNode->setNext(anker->getNext()); //newNode->next=last node of the list
		anker->setNext(newNode); //newNode infront of temp
		anker = newNode;
		countNodes++;
	}
	else //ring full
	{
		RingNode* delNode = anker->getNext();

		anker->setNext(newNode); //newNode infront of temp
		newNode->setNext(delNode->getNext()); //newNode->next->next= second last node of the list
		
		delNode->setNext(nullptr); //notwendig??
		delete delNode; //das älteste Element löschen
		anker = newNode;
	}
	incrementAges();
}

bool Ring::search(string Data) {
	
	if (anker == nullptr) return false; //if empty ring then false
	RingNode* temp = anker;
	do {
		if (temp->getData() == Data) {
			std::cout << " Gefunden in Backup: Alter " << temp->getAge() 
					  << ", Beschreibung: " << temp->getDescription() 
					  << ", Daten: " << temp->getData() << std::endl;
			return true;
		}
		temp = temp->getNext();
	} while (temp->getNext() != anker);

	return false;
}

void Ring::print() {
	if (anker == nullptr)
	{
		std::cout << "Ring enthaelt keine Elemente" << std::endl;
	}
	else {
		for (int i = 0; i < countNodes; i++) {
			RingNode* temp = anker;
			do{
				if (temp->getAge() == i) {
					std::cout << "Alter " << temp->getAge()
						<< ", Beschreibung: " << temp->getDescription()
						<< ", Daten: " << temp->getData() << std::endl;
					std::cout << "-------------------------" << std::endl;
					break;
				}
				temp = temp->getNext();
			} while (temp != anker);
		}
	}
}