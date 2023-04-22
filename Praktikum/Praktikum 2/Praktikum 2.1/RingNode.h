/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>
using namespace std;

class RingNode{
private:
	int oldAge;
	string description;
	string symbolicData;
	RingNode* next;

public:
	RingNode();
	RingNode(int, string, string);
	int getAge();
	void setAge(int);
	string getDescription();
	void setDescription(string);
	string getData();
	void setData(string);
	RingNode* getNext();
	void setNext(RingNode*);
};