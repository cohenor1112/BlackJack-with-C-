#include "Player.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG

Player::Player(string name) : r_won(0), r_lose(0), cards_sum(0)
{
	this->p_name = name;
}

ostream& operator<<(ostream& os, const Player& player)
{
	os << player.p_name << ": " << "(sum of cards: " << player.cards_sum << ")" << endl;
	return os;
}

//"Extras":

string Player::get_name()
{
	return this->p_name;
}

unsigned int Player::get_cards_sum()
{
	return this->cards_sum;
}

void Player::update_cards_sum(unsigned int _cards_sum)
{
	this->cards_sum = _cards_sum;
}

unsigned int Player::get_wins()
{
	return this->r_won;
}

unsigned int Player::get_loses()
{
	return this->r_lose;
}

void Player::update_wins_and_loses(bool win_flag)
{
	if (win_flag == true)
		this->r_won++;
	else
		this->r_lose++;
}

