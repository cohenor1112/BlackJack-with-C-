#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#include <iostream>
#include "Card.h"

class Dqueue {
public:
	//constractors:
	Dqueue(unsigned size);
	//Dqueue(const Dqueue& other);
	~Dqueue();
	//setters/getters:

	//functions:
	void push_back(Card* card);
	Card* pop_back();
	void push_front(Card* card);
	Card* pop_front();
	const Card& front() const;
	const Card& back() const;
	int  size() const;
	bool is_empty();
private:
	//members:
	int m_size;
	int m_capacity;
	int m_left;
	int m_right;
	Card** m_queue;
	//internal functions:
	void next_index(const char& operation); //increment requested index
	void prev_index(const char& operation); //decrement requested index
};

#endif // !_DEQUEUE_H_