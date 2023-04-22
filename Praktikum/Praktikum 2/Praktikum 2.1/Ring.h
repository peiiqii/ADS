/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring{
	private:
		int countNodes;
		RingNode* anker;
	public:
		Ring();
		void addNewNode(string, string);
		bool search(string);
		void print();
		void incrementAges();

		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_countNodes(Ring& r);
};
