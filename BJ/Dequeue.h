#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#include <iostream>
using namespace std;
#include "Card.h"

class Dequeue
{

private:
	//1)Number of organs in array
	unsigned int m_size;
	//2)Size of array 
	const int m_capacity = 52;
	//3)Array of pointers with m_capacity length
	Card** m_queue;
	//4)Index of the first organ in array m_queue
	int m_left;
	//Extras:
	//Index of the last organ in array m_queue 
	int m_right;

public:
	//1)Ctor
	//Initializes the members m_size ,m_left and m_right to 0
	//creating array m_queue of pointer (length of the array is m_capacity (52)) , and initialize every pointer to point to NULL 
	Dequeue();
	//2)Dtor
	//Delete all created dynamic allocations (the pointer that are in the array m_queue and the m_queue itself
	~Dequeue();
	//3)
	//push to the back of the array m_queue if it is'nt full ,and updating m_size
	void push_back(Card* card);
	//4)
	//pop the last organ in array m_queue if it is'nt empty ,and updating m_size
	Card* pop_back();
	//5)
	//push to the front of the array m_queue if it is'nt full ,and updating m_size
	void push_front(Card* card);
	//6)
	//pop the first organ in array m_queue if it is'nt empty ,and updating m_size
	Card* pop_front();
	//7)
	//Returns the first organ of m_queue
	const Card& front() const;  
	//8)
	//Returns the last organ of m_queue
	const Card& back() const;   
	//9)
	//Returns the number of organs in m_queue
	unsigned int size() const; 
	//10)
	//Returns 1 if m_queue is empty and 0 if not
	bool is_empty() const;                                                           
	//Extras:
	//Returns 1 if m_queue is full and 0 if not
	bool is_full() const;
	//Receives a push instruction ("push back" or "push front") and updating the appropriate index according to the instruction . (Auxiliary function for the push functions). It refers to the fact that the array is a cyclical array
	void for_push_next_index(const string& push_back_or_push_front);
	////Receives a pop instruction ("pop back" or "pop front") and updating the appropriate index according to the instruction . (Auxiliary function for the pop functions) .It refers to the fact that the array is a cyclical array
	void for_pop_prev_index(const string& pop_back_or_pop_front);
	//Receives an array of pointers to cards and fills m_queue
	void first_fill_Dequeue(Card* card_arr[]);
	//Mixes the queue randomly
	void mix_Dequeue();
	//Gets two indexes and changes them to be random (in range 0-51)
	void random_2_indexes_0_to_51(unsigned int& index_a, unsigned int& index_b);
	//Switches between two pointers
	void swap_cards(Card*& card_a_pointer, Card*& card_b_pointer);
};

#endif		// _DEQUEUE_H_

//?many questions about const - where to write const? where to write static?