#include <iostream>
#include "stack.h"

using namespace std;

int main() {
	Stack myStack(6);

	myStack.push(15);
	myStack.push(6);
	myStack.push(2);
	myStack.push(19);
	myStack.push(17);
	myStack.push(3);
	myStack.printAll();

	cout << "Entnommenes Element vom Stapel = " << myStack.pop() << endl;
	myStack.printAll();
}