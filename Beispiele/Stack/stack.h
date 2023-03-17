#pragma once

class Stack {
private:
	int* stack; //Stapel als Array
	int n; //Array-Größe
	int top; //Leseposition

public:
	Stack();
	Stack(int n);
	~Stack();
	void push(int item);
	int pop();
	bool isEmpty();
	bool isFull();
	void printAll();
};

