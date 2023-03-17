#pragma once

class Queue {
private:
	int* queue; //Array Pointer
	int n; //Array-Größe
	int front; //Leseposition
	int rear; //Schreibposition
public:
	Queue();
	Queue(int n);
	~Queue();
	void enqueue(int item);
	int dequeue();
	bool isEmpty();
	bool isFull();
	void printAll();
};
