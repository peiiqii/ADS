#pragma once

class Node {
public:
	int key;
	Node* prev;
	Node* next;
	Node() {
		key = 0;
		prev = nullptr;
		next = nullptr;
	}
	Node(int key) {
		this->key = key;
		prev = nullptr;
		next = nullptr;
	}
};