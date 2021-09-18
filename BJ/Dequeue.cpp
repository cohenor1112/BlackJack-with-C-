#include "Dequeue.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

//there are no static methodes to initialize!

Dequeue::Dequeue()
	:m_size(0) ,m_left(0),m_right(m_size)
{
	m_queue = new Card * [m_capacity];
	memset(m_queue, NULL, m_capacity * sizeof(Card*));
}

Dequeue::~Dequeue()
{
	//Delete all created dynamic allocations:
	for (int i = 0; i < 52; i++)
	{
		delete m_queue[i];
	}
	delete[] m_queue;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Dequeue::push_back(Card* card)
{
	if(is_empty())    //empty dequeue
		m_queue[m_right] = card;
	else if (is_full()) //full dequeue
	{
		cout << "Dequeue is full ! - cant push a card !" << endl;
		return;
	}
	else 
	{
		for_push_next_index("push_back");
		m_queue[m_right] = card;
	}
	m_size++;
}

Card* Dequeue::pop_back()
{
	if (is_empty())
		return NULL;
	Card* card = m_queue[m_right];
	m_queue[m_right] = NULL;                     //card pointer is not in m_queue after this line
	for_pop_prev_index("pop_back");
	m_size--;
	return card;
}

void Dequeue::push_front(Card* card)
{
	if (is_empty())
		m_queue[m_left] = card;
	else if (is_full())
	{
		cout << "Dequeue is full ! - cant push a card !" << endl;
		return;
	}
	else {
		for_push_next_index("push_front");
		m_queue[m_left] = card;
	}
	m_size++;
}


Card* Dequeue:: pop_front()
{
	if (is_empty())
		return NULL;
	Card* card = m_queue[m_left];
	m_queue[m_left] = NULL;                     //card pointer is not in m_queue after this line
	for_pop_prev_index("pop_front");
	m_size--;
	return card;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

////

const Card& Dequeue::front() const 
{
	return *m_queue[m_left];
}

const Card& Dequeue::back() const
{
	return *m_queue[m_right];
}

unsigned int Dequeue::size() const
{
	return m_size;
}

bool Dequeue::is_empty() const
{
	if (m_size == 0)
		return true;
	else
		return false;
}

///

//Extras:

bool Dequeue::is_full() const
{
	if (m_size == m_capacity)
		return true;
	else
		return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void Dequeue::for_push_next_index(const string& push_back_or_push_front)
{
	if (m_size == m_capacity)
		return;
	if (push_back_or_push_front == "push_back") {
		if (m_right >= m_capacity - 1)
			m_right = 0;
		else
			m_right++;
	}
	else if (push_back_or_push_front == "push_front") {
		if (m_left == 0)
			m_left = m_capacity - 1;
		else
			m_left--;
	}
	else
		return;
}

void Dequeue::for_pop_prev_index(const string& pop_back_or_pop_front)
{
	if (is_empty())
		return;
	if (pop_back_or_pop_front == "pop_back") {
		if (m_right == 0) //m_capacity - 1)
			m_right = m_capacity - 1;
		else
			m_right--;
	}
	else if (pop_back_or_pop_front == "pop_front") {
		if (m_left == m_capacity - 1)
			m_left = 0;
		else
			m_left++;
	}
	else
		return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void Dequeue::first_fill_Dequeue(Card* card_arr[])
{
	for (unsigned int i = 0; i < m_capacity; i++)
	{
		push_front(card_arr[i]);
	}
}

void Dequeue::mix_Dequeue()
{
	unsigned int number_of_swaps = 251;
	unsigned int index_a = 0;
	unsigned int index_b = 0;
	for (unsigned i = 0; i < number_of_swaps; i++)
	{
		random_2_indexes_0_to_51(index_a, index_b);
		swap_cards(m_queue[index_a], m_queue[index_b]);
	}
}

void Dequeue::random_2_indexes_0_to_51(unsigned int& index_a, unsigned int& index_b)
{
	index_a = rand() % 52;
	index_b = rand() % 52;
}

void Dequeue::swap_cards(Card*& card_a_pointer, Card*& card_b_pointer)
{
	Card* tmp_card_pointer = card_a_pointer;
	card_a_pointer = card_b_pointer;
	card_b_pointer = tmp_card_pointer;
	return;
}
