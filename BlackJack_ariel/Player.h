#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <iostream>
#include "Card.h"
//using namespace std;

class Player {
public:
	//de/constractors:
	Player(std::string name);
	//Player(Player& other);
	~Player();
	//getters & setters:
	std::string get_name() const;
	//void set_name(std::string player_name);
	char get_win_count() const;
	char get_lose_count() const;
	char get_cards_value() const;
	void record_win();
	void record_lose();
	void reset_score();
	//functions:
	//void print_cards();
	void set_card(const Card* card);
private:
	std::string m_name;
	char m_num_of_cards;
	char m_cards_value;
	char m_win_rounds;
	char m_lose_rounds;
	char m_num_of_aces;
	//Card* m_cards;
	//friends:
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif // !_PLAYER_H_