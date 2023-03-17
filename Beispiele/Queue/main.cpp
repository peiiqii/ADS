#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	Queue myQueue(6);

	myQueue.enqueue(15);
	myQueue.enqueue(6);
	myQueue.enqueue(2);
	myQueue.enqueue(19);
	myQueue.enqueue(17);
	myQueue.enqueue(3);
	myQueue.printAll();

	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	cout << "Entnommenes Element vom Queue = " << myQueue.dequeue() << endl;
	myQueue.printAll();
}
