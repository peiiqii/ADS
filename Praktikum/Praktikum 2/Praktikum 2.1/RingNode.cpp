/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

RingNode::RingNode() {
	oldAge = 0;
	description = "";
	symbolicData = "";
	next = nullptr;
}

RingNode::RingNode(int oldAge, string description, string symbolicData) {
	this->oldAge = oldAge;
	this->description = description;
	this->symbolicData = symbolicData;
	next = nullptr;
}

int RingNode::getAge() {
	return oldAge;
}

void RingNode::setAge(int age) {
	this->oldAge = age;
}

string RingNode::getDescription() {
	return description;
}

void RingNode::setDescription(string descr) {
	this->description = descr;
}

string RingNode::getData() {
	return symbolicData;
}

void RingNode::setData(string data) {
	this->symbolicData = data;
}

RingNode* RingNode::getNext() {
	return next;
}

void RingNode::setNext(RingNode* next) {
	this->next = next;
}