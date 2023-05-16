#include "TreeNode.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

TreeNode::TreeNode(int nNodePos,int id,std::string name,int age,double income ,int postCode) 
	: NodeChronologicalID{id},
      NodeOrderID{nNodePos}
	, Name{name}
	, Age{age}
	, Income{income}
	, PostCode{postCode}
	, left{nullptr}
	, right{nullptr}
{}

int TreeNode::getNodeChronologicalID() const {
 return this->NodeChronologicalID;
}

int TreeNode::getNodeOrderID() const {
	return this->NodeOrderID;
}

std::string TreeNode::getName() const {
	return this->Name;
}

void TreeNode::setName(std::string nName){
	this->Name = nName;
}

int TreeNode::getAge() const {
	return this->Age;
}

void TreeNode::setAge(int nAlter){
	this->Age = nAlter;
}

double TreeNode::getIncome() const {
	return this->Income;
}

void TreeNode::setIncome(double nIN){
	this->Income = nIN;
}

int TreeNode::getPostCode() const {
	return this->PostCode;
}

void TreeNode::setPostCode(int nPLZ){
	this->PostCode = nPLZ;
}

TreeNode* TreeNode::getLeft() const {
	return this->left;
}

void TreeNode::setLeft(TreeNode* nLeft){
	this->left = nLeft;
}

TreeNode * TreeNode::getRight() const {
	return this->right;
}

void TreeNode::setRight(TreeNode* nRight){
	this->right = nRight;
}

void TreeNode::print() const
{
	std::cout << setw(11) << this->NodeOrderID << '|' 
			  << setw(15) << this->Name << '|'
			  << setw(7) << this->Age << '|'
			  << setw(12) << this->Income << '|'
			  << setw(14) << this->PostCode << '|'
			  << this->NodeChronologicalID << std::endl;
}

void TreeNode::printColor() const
{
	std::cout << setw(11) << this->NodeOrderID << '|'
		<< setw(15) << this->Name << '|'
		<< setw(7) << this->Age << '|'
		<< setw(12) << this->Income << '|'
		<< setw(14) << this->PostCode << '|'
		<< this->red << std::endl;
}

bool TreeNode::getRed() const
{
	return this->red;
}

void TreeNode::setRed(bool red) {
	this->red = red;
}

TreeNode* TreeNode::getParent() { return parent; }
void TreeNode::setParent(TreeNode* newParent) { TreeNode::parent = newParent; }