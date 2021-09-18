//////////////////////////////////////////////////////
//////////////////// Player.cpp //////////////////////
//////////////////////////////////////////////////////
//													//
//	includes:										//
#include "Player.h"									//
#include <string>									//
using namespace std;								//
//													//
//	statics init:									//
//													//
//													//
//////////////////////////////////////////////////////

/////////////////// constractors: /////////////////////

Player::Player(string name) :m_name(name) {
	m_win_rounds = 0;
	m_lose_rounds = 0;
	m_num_of_cards = 0;
	//m_cards = 0;
	m_cards_value = 0;
	m_num_of_aces = 0;
}

//Player::Player(Player& other) {
//	m_win_rounds = other.m_win_rounds;
//	m_lose_rounds = other.m_lose_rounds;
//	m_num_of_cards = other.m_num_of_cards;
//	m_cards_value = other.m_cards_value;
//	m_num_of_aces = other.m_num_of_aces;
//}

Player::~Player() {
	
}

//////////////////// Gets,Sets: ///////////////////////

string Player::get_name() const {
	return m_name;
}

//void Player::set_name(std::string player_name) {
//	m_name = player_name;
//}

char Player::get_win_count() const {
	return m_win_rounds;
}

char Player::get_lose_count () const {
	return m_lose_rounds;
}

char Player::get_cards_value() const {
	return m_cards_value;
}

void Player::record_win() {
	m_win_rounds++;
}

void Player::record_lose() {
	m_lose_rounds++;
}

void Player::reset_score() {
	m_cards_value = 0;
}

//////////////////// Functions: //////////////////////

//////////////////////////////////
void Player::set_card(const Card* card) {
//////////////////////////////////
	char value = card->get_game_value();
	if (value == 11)		//check if card serial is 11 (ace) and increment
		m_num_of_aces++;	// aces counter
	m_cards_value += value;
	if ((m_cards_value > 21) && (m_num_of_aces > 0)) {
		m_num_of_aces--;	//if score is above 21 BUT there is at least 1 ace
		m_cards_value -= 10;//in hand
	}
}

//void Player::print_cards() {
//	int value = 0;
//	for (int i = 0; i < m_num_of_cards; i++) {
//		cout << m_cards[i] << " ";
//		value += (m_cards[i].get_game_value());
//	}
//	cout << "total of " << value << ")";
//}

//////////////////////////////////
ostream& operator<<(ostream& os, const Player& player) {
//////////////////////////////////
	os << "out of " << player.m_cards_value << " rounds, you won " << player.m_win_rounds << " times and lost " << player.m_lose_rounds << "times";
	return os;
}