//////////////////////////////////////////////////////
//////////////////// Player.cpp //////////////////////
//////////////////////////////////////////////////////
//													//
//	includes:										//
#include "Dequeue.h"								//
//													//
//	statics init:									//
//													//
//													//
//////////////////////////////////////////////////////


/////////////////// constractors: /////////////////////

//////////////////////////////////
Dqueue::Dqueue(const unsigned size) {
//////////////////////////////////
	Card** queue = new Card*[size];
	for (unsigned i = 0; i < size; i++) {
		queue[i] = NULL;
	}
	m_queue = queue;
	m_left = 0;
	m_right = 0;
	m_capacity = size;
	m_size = 0;
}

//Dqueue::~Dqueue(const Dqueue& other) {
//
//}

//////////////////////////////////
Dqueue::~Dqueue() {
//////////////////////////////////
	for (int i = 0; i < m_capacity; i++)
		delete m_queue[i];
	delete[] m_queue;
}

//////////////////// Functions: //////////////////////

//////////////////////////////////
void Dqueue::push_back(Card* card) {
//////////////////////////////////
	if (!m_size)
		m_queue[m_left] = card;
	else if (m_size == m_capacity)
		return;
	else {
		next_index('l');
		m_queue[m_left] = card;
	}
	m_size++;
}

//////////////////////////////////
Card* Dqueue::pop_back() {
//////////////////////////////////
	if (!m_size)
		return NULL;
	Card* card = m_queue[m_left];
	m_queue[m_left] = NULL;
	prev_index('l');
	m_size--;
	return card;
}

//////////////////////////////////
void Dqueue::push_front(Card* card) {
//////////////////////////////////
	if (!m_size) 
		m_queue[m_right] = card;
	else if (m_size == m_capacity)
		return;
	else {
		next_index('r');
		m_queue[m_right] = card;
	}
	m_size++;
}

//////////////////////////////////
Card* Dqueue::pop_front() {
//////////////////////////////////
	if (!m_size)
		return NULL;
	Card* card = m_queue[m_right];
	m_queue[m_right] = NULL;
	prev_index('r');
	m_size--;
	return card;
}

//////////////////////////////////
const Card& Dqueue::front() const {
//////////////////////////////////
	return *m_queue[m_right];
}

//////////////////////////////////
const Card& Dqueue::back() const {
//////////////////////////////////
	return *m_queue[m_left];
}

//////////////////////////////////
int  Dqueue::size() const {
//////////////////////////////////
	return m_size;
}

//////////////////////////////////
bool Dqueue::is_empty() {
//////////////////////////////////
	if (m_size == 0)
		return true;
	return false;
}

//////////////////////////////////
void Dqueue::next_index(const char& operation) {
//////////////////////////////////
	if (m_size == m_capacity)
		return;
	if (operation == 'r') {
		if (m_right >= m_capacity - 1)
			m_right = 0;
		else
			m_right++;
	}
	else if (operation == 'l') {
		if (m_left == 0)
			m_left = m_capacity - 1;
		else
			m_left--;
	}
	else 
		return;
}

//////////////////////////////////
void Dqueue::prev_index(const char& operation) {
//////////////////////////////////
	if (is_empty())
		return;
	if (operation == 'r') {
		if (m_right == 0) //m_capacity - 1)
			m_right = m_capacity - 1;
		else
			m_right--;
	}
	else if (operation == 'l') {
		if (m_left == m_capacity - 1)
			m_left = 0;
		else
			m_left++;
	}
	else
		return;
}