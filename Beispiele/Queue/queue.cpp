#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue() {
	this->queue = new int[8]; //Array
	this->n = 8; //max. Anzahl
	this->front = -1; //Leseindex
	this->rear = -1; //Schreibindex
}

Queue::Queue(int n) {
	this->n = n; //max. Anzahl
	this->queue = new int[n]; //Array
	this->front = -1; //Leseindex
	this->rear = -1; //Schreibindex
}

Queue::~Queue() {
	delete[] this->queue;
}

void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Overflow error: Circular Queue is full." << endl;
	}
	else {
		if (isEmpty()) {
			front++;
		}
		rear = (rear + 1) % n;
		queue[rear] = item;
	}
}

int Queue::dequeue() {
	if (isEmpty()) {
		cout << "Underflow error: Circular Queue is empty." << endl;
	}

	int temp = queue[front];
	if (front == rear) {  //wenn there's only one element in the queue
		front = rear = -1;
	}
	else {
		front = (front + 1) % n;
	}
	return temp;
}

bool Queue::isEmpty() {
	return front == -1;
}

bool Queue::isFull() {
	return (rear + 1) % n == front;
}

void Queue::printAll() {
	cout << "Queue-Inhalt: " << endl;
	if (!isEmpty()) {
		for (int i = front; i <= rear; i++) {
			cout << queue[i] << endl;
		}
	}
	else {
		cout << "Underflow error: Circular Queue is empty." << endl;
	}
}