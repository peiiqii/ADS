/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{

private:
    int NodeOrderID = Age + PostCode + int(Income);
    int NodeChronologicalID;
    string Name;
    int Age;
    double Income;
    int PostCode;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int NodeOrderId, int NodeChronologicalId, string name, int age, double income, int postcode, TreeNode* left, TreeNode* right) 
        : NodeOrderID(NodeOrderId), NodeChronologicalID(NodeChronologicalId), Name(name), Age(age), Income(income), PostCode(postcode), left(left), right(right){}
    
    int getNodeOrderID() { return NodeOrderID; }
    void setNodeOrderID(int NodeOrderId) { TreeNode::NodeOrderID = NodeOrderId; }

    int getNodeChronologicalID() { return NodeChronologicalID; }
    void setNodeChronologicalID(int NodeChronologicalId) { TreeNode::NodeChronologicalID = NodeChronologicalId; }

    string getName() { return Name; }
    void setName(string name) { TreeNode::Name = name; }

    int getAge() { return Age; }
    void setAge(int age) { TreeNode::Age = age; }

    double getIncome() { return Income; }
    void setIncome(double income) { TreeNode::Income = income; }

    int getPostCode() { return PostCode; }
    void setPostCode(int postcode) { TreeNode::PostCode = postcode; }

    TreeNode* getLeft() { return left; }
    void setLeft(TreeNode* left) { TreeNode::left = left; }

    TreeNode* getRight() { return right; }
    void setRight(TreeNode* right) { TreeNode::right = right; }

    void print();
};

