/*************************************************
* ADS Praktikum 3
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

class TreeNode{
	
private:
		///////////////////////////////////////
		// Ihr Code hier:	
		int NodeChronologicalID;
		int NodeOrderID;
		std::string Name;
		int Age;
		double Income;
		int PostCode;
		TreeNode * left;
		TreeNode * right;
		bool red;
		TreeNode* parent = nullptr;
		//
		////////////////////////////////////
public:
		///////////////////////////////////////
		// Ihr Code hier:
		TreeNode() = delete;
		explicit TreeNode(int nNodePos, int id, std::string name, int age, double income, int postCode);
		int getNodeChronologicalID() const;
		int getNodeOrderID() const;
		int getAge() const;
		void setAge(int);
		double getIncome() const;
		void setIncome(double);
		int getPostCode() const;
		void setPostCode(int);
		std::string getName() const;
		void setName(std::string Name);
		TreeNode* getLeft() const;
		TreeNode* getRight() const;
		void setLeft(TreeNode*);
		void setRight(TreeNode*);
		void print() const;	
		void printColor() const;

		bool getRed() const;
		void setRed(bool);

		TreeNode* getParent();
		void setParent(TreeNode*);
		//
		////////////////////////////////////
};
