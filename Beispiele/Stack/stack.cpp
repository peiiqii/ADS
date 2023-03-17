#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
	this->stack = new int[10];
	this->n = 10;
	this->top = -1;
}

Stack::Stack(int n) {
	this->stack = new int[n];
	this->n = n;
	this->top = -1;
}

Stack::~Stack() {
	delete[] this->stack;
}

void Stack::push(int item) {
	if (!isFull()) {
		top += 1;
		stack[top] = item;
	}
	else {
		cout << "Overflow error: Stack is full." << endl;
	}
}

int Stack::pop() {
	if (!isEmpty()) {
		top -= 1;
		return stack[top + 1];
	}
	else {
		cout << "Underflow error: Stack is empty." << endl;
	}
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

bool Stack::isFull() {
	if (top == n - 1) return true;
	else return false;
}

void Stack::printAll() {
	cout << "Stapel-Inhalt: " << endl;
	for (int i = 0; i <= top; i++) {
		cout << stack[i] << " ";
		cout << endl;
	}
}