#include "Card.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

//initialize static members:
int Card::number_of_cards_already_made(0); // Initial start value
int Card::cards_hist[14] = { 0 };
int Card::total_number_of_cards_need(52);
int Card::number_of_same_card(4);
string Card::cards_names[] = { "NULL", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

Card::Card(int value)
//initialize members in ctor
	: BJ_value(0), card_name("NULL")
{
	if (number_of_cards_already_made == total_number_of_cards_need)
	{
		cout << "there are already " << number_of_cards_already_made << " cards" << endl;
	}
	else
	{
		BJ_value = give_BJ_value(value);
		card_name = give_name_to_card(value);
		number_of_cards_already_made++;
		cards_hist[value]++;
	}
}

int Card::toss_val()
{
	int rand_card_number;
	rand_card_number = 1 + rand() % 13;
	while (cards_hist[rand_card_number] == number_of_same_card)
	{
		rand_card_number = 1 + rand() % 13;
	}
	return rand_card_number;
}

////friend function:
ostream& operator<<(ostream& os, const Card& card)
{
	os << card.card_name << " ";
	return os;

}

//Extras:

unsigned int Card::give_BJ_value(const int card_number)
{
	if (card_number == 1)                               //value of card_NO=1 is by default 11
		return	11;
	else if (card_number > 1 && card_number < 10)       //value of cards 2-9 is card_NO itself 
	{
		return card_number;
	}
	else if (card_number >= 10 && card_number <= 13)    //value of cards 10 - 13 is 10
	{
		return 10;
	}
}

unsigned int Card::get_BJ_value()
{
	return this->BJ_value;
}

const string Card::give_name_to_card(const int card_number)
{
	return cards_names[card_number];
}


const string Card::get_card_name()
{
	return this->card_name;
}