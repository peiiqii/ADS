/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

using namespace std;

class Tree
{
private:
    TreeNode* anker;
    int currentNodeChronologicalID;

    //Hilfsfunktionen
    void printPreorder(TreeNode* node);
    bool TreeSearch(TreeNode* node, string name);
    void loeschen(TreeNode* ptr); //Hilfsfunktion für Destruktor

public:
    Tree() : anker(nullptr), currentNodeChronologicalID(0) {}
    ~Tree();
    void addNode(string, int, double, int);
    bool deleteNode(int);
    bool searchNode(string);
    void printAll();
    void levelOrder();

    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
