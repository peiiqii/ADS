#include "DoubleStack.h"
#include <iostream>
using namespace std;

DoubleStack::DoubleStack(int n) {
	this->m_size = n;
	this->m_array = new int[n];
	this->m_i_stack0 = -1;
	this->m_i_stack1 = n / 2 - 1;
	this->m_allocation_size = n*2;
}

DoubleStack::~DoubleStack() {
	delete[] this->m_array;
}

void DoubleStack::resize() {
	int* temp = new int[m_size];
	for (int i = 0; i < m_size; i++) {
		temp[i] = m_array[i];
	}
	delete[] m_array;

	this->m_size = m_allocation_size;
	this->m_i_stack1 = m_i_stack1 + (m_size / 4);

	m_array = new int[m_size];
	
	//Copy Stack0 elements
	for (int i = 0; i < (m_size / 4); i++) {
		m_array[i] = temp[i];
	}
	
	//Copy Stack1 elements
	int z = m_size / 2;
	for (int i = m_size / 4; i < (m_size / 2); i++) {
		m_array[z] = temp[i];
		z++;
	}
	delete[] temp;
}

void DoubleStack::push0(const int& item)
{	 
	if (m_i_stack0 == m_size / 2 - 1) { //if stack0 is full
		resize();
		cout << "Stack0 is full, the array will be resized." << endl;
	}
	m_i_stack0 += 1;
	m_array[m_i_stack0] = item;
}

void DoubleStack::push1(const int& item)
{
	if (m_i_stack1 == m_size - 1) { //if stack1 is full
		resize();
		cout << "Stack1 is full, the array will be resized." << endl;
	}
	m_i_stack1 += 1;
	m_array[m_i_stack1] = item;
}

int DoubleStack::pop0() {
	if (m_i_stack0 == -1) {  //if stack0 is empty
		cout << "Stack UnderFlow" << endl;
	}
	else {
		m_i_stack0 -= 1;
		return m_array[m_i_stack0 + 1];
	}
}

int DoubleStack::pop1() {
	if (m_i_stack1 == m_size / 2 - 1) { //if stack1 is empty
		cout << "Stack UnderFlow" << endl;
	}
	else {
		m_i_stack1 -= 1;
		return m_array[m_i_stack1 + 1];
	}
}

void DoubleStack::printAll() {
	cout << "Double Stack as Array: [ ";
	for (int i = 0; i <= m_i_stack0; i++) {
		cout << m_array[i] << " ";
	}
	for (int i = m_size/2; i <= m_i_stack1; i++) {
		cout << m_array[i] << " ";
	}
	cout << "]";
}