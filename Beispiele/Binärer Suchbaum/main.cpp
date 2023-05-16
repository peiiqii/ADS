#include <iostream>
#include "binaryTree.h"
using namespace std;

int main() {
	BinaryTree tree;
	
	tree.insert(40);
	tree.insert(20);
	tree.insert(60);
	tree.insert(10);
	tree.insert(70);
	tree.insert(65);
	tree.add(63);
	tree.add(68);

	tree.printLevelorder();

	tree.removeNode(40);
	tree.printLevelorder();
}
