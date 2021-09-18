#include "Stack.h"
#include <iostream>
using namespace std;
unsigned Stack::score = sizeof(unsigned);

// constractors
Stack::Stack(unsigned size) {
	m_capacity = size;
	m_top = 0;
	m_bottom = new int[size];
	memset(m_bottom, 0, size);
	score += sizeof(Stack) + sizeof(int)*m_capacity;
}

Stack::Stack(const Stack& other) {
	m_bottom = new int[other.m_capacity];
	memcpy(m_bottom, other.m_bottom,(other.m_top)*sizeof(int));
	m_capacity = other.m_capacity;
	m_top = other.m_top;
	score += sizeof(Stack) + sizeof(int) * m_capacity;
}

Stack::~Stack() {
	delete[] m_bottom;
	score -= (sizeof(Stack) + sizeof(int) * m_capacity);
}

//public:

void Stack::show(void) const {
	for (unsigned i = 0; i < (m_top) ; i++) {
		cout << m_bottom[i] << ",";
	}
}

unsigned Stack::get_top() const {
	return m_top;
}

void Stack::push(int value) {
	if (m_top == m_capacity) {
		resize(2 * m_capacity);
		m_capacity *= 2;
	}
	m_bottom[m_top++] = value;
}

bool Stack::pop(int& value) {
	if (!m_top)
		return false;
	value = m_bottom[--m_top];
	return true;
}

bool Stack::peek(int& value) const {
	if (!m_top)
		return false;
	value = m_bottom[m_top-1];
	return true;
}

Stack& Stack::assign(const Stack& other) {
	if (m_capacity >= other.m_top) {
		memcpy(m_bottom, other.m_bottom, other.m_top * sizeof(int));
	}
	else {
		//delete[] m_bottom;
		//I've decided to make the array as big as the other one in that case. to prevent a new assign
		resize(other.m_capacity);
		memcpy(m_bottom, other.m_bottom, (other.m_top) * sizeof(int));
		m_capacity = other.m_capacity;
	}
	m_top = other.m_top;
	return *this;
}

void Stack::resize(unsigned size) {
	int old_size = + sizeof(int) * m_capacity;
	int* new_arr = new int[size];
	memcpy(new_arr, m_bottom, (size) * sizeof(int)); //m_top
	delete[] m_bottom;
	m_bottom = new_arr;
	m_capacity = size;
	if (m_top > m_capacity)
		m_top = m_capacity;
	score += ((sizeof(int) * m_capacity) - old_size);
}

unsigned Stack::get_score() {
	return score;
}