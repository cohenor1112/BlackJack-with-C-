#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include <iostream>
using namespace std;

class Card {
public:
	//de/constractors:
	Card(int card_serial);
	~Card();
	Card(Card& c);
	//getters,setters:
	char get_name() const;
	char get_game_value() const;
	static int toss_val();
	static int get_max_cards();
	static int get_max_kind_cards();
	//statics:
	static char n_cards_made;
	static char n_cards_kind[13];
private:
	//members:
	unsigned char m_value;
	unsigned char m_game_value;
	char m_name;
	//statics:
	const static char n_max_cards = 52;
	const static char n_max_kind_cards = 4;
	//functions:
	unsigned char serial_2_name(const int card_serial);
	unsigned char serial_2_gv(const int card_serial);
	//friends:
	friend ostream& operator<<(ostream& os, const Card& card);
};

#endif // !_CARD_H_