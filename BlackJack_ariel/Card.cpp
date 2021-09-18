//////////////////////////////////////////////////////
///////////////////// Card.cpp ///////////////////////
//////////////////////////////////////////////////////
//													//
//	includes:										//
#include "Card.h"									//
#include <iostream>									//
#include <time.h>									//
//													//
//	statics init:									//
using namespace std;								//
char Card::n_cards_made = 0;						//
char Card::n_cards_kind[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
//													//
//////////////////////////////////////////////////////


/////////////////// constractors: /////////////////////

//////////////////////////////////
Card::Card(int card_serial) {
//////////////////////////////////
	//we decided to keep the option to the customer of this class
	//to decide weather to use the tol_val() tool and create 1 deck
	//or to create manually as many cards as they want
	/*if (card_serial == 0) {
		m_value = 0;
		m_game_value = 0;
		m_name = NULL;
	}
	else {*/
	if (card_serial < 0 || card_serial > 13)
		card_serial = 1; // default card_serial if input serial is invalid
		m_value = card_serial;
		m_game_value = serial_2_gv(card_serial);
		m_name = serial_2_name(card_serial);
	//}
}

//////////////////////////////////
Card::Card(Card& other) {
//////////////////////////////////
	//'present #3' can handle this but you requested us to 
	//write copy constractor
	m_name = other.m_name;
	m_game_value = other.m_game_value;
	m_value = other.m_value;
}

//////////////////////////////////
Card::~Card() {
//////////////////////////////////
	//there are no dynamic memory allocation in this class
}

//////////////////// Convertors: //////////////////////

//////////////////////////////////
unsigned char Card::serial_2_name(const int card_serial) {
//////////////////////////////////
	switch (card_serial) {
	case 1:
		return 'A';
		break;
	case 11:
		return 'J';
		break;
	case 12:
		return 'Q';
		break;
	case 13:
		return 'K';
		break;
	default:
		if (card_serial < 0 || card_serial > 13) {
			return '?';	// not defined
		}
		else {
			return '0' + card_serial;
		}
	}
}

//////////////////////////////////
unsigned char Card::serial_2_gv(const int card_serial) {
//////////////////////////////////
	if (card_serial < 0 || card_serial > 13) {
		return -1;
	}
	else if(card_serial==1) {
		//special ace value - 11, the game will know weather to count it as 1 or 11
		return 11;
	}
	else if (card_serial > 10) {
		return 10;
	}
	else {
		return card_serial;
	}
}

//////////////////// Functions: //////////////////////

//////////////////////////////////
int Card::toss_val() {
//////////////////////////////////
	//We chose to start with shuffled deck 
	int card_serial = 0;
	do {
		card_serial = rand() % 13 + 1;
	} while (n_cards_kind[card_serial-1] >= 4);
	Card::n_cards_kind[card_serial - 1]++;
	return card_serial;
}

//////////////////////////////////
ostream& operator<<(ostream& os, const Card& card) {
//////////////////////////////////
	if (card.m_name == ('0' + 10)) {
		os << "10";  //since we use char for card name we're using this character as
	}				 //a special character to represent '10'
	else {
		os << card.m_name;
	}
	return os;
}

//////////////////// Gets,Sets: ///////////////////////

char Card::get_name() const {
	return m_name;
}

char Card::get_game_value() const {
	return m_game_value;
}

int Card::get_max_cards() { //static function
	return n_max_cards;
}

int Card::get_max_kind_cards() { //static function
	return n_max_kind_cards;
}