#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <iostream>
#include "Card.h"
#include "Dequeue.h"
#include "Player.h"
#include "Stack.h"

class BlackJack {
public:
	BlackJack();
	~BlackJack();
	void play();
private:
	void init_deck();
	//members:
	Player* m_player; 
	Player* m_dealer;
	Dqueue* m_Deck;
	Card** m_player_cards;
	int m_player_cards_idx;
	Card** m_dealer_cards;
	int m_dealer_cards_idx;
	char m_num_of_rounds;
	//functions:
	void set_player_dialog(Player* player);
	int manu_dialog() const;
	int game_dialog() const;
	void shuffle();
	void print_cards(Card**& cards, const Player* player) const;
	void take_card(Player* player);
	void serve_cards();	//serve cards at start of a game-2 cards per player
	void dealers_turn();
	void declare_winner_and_reset();
	//takes all cards back to deck
	void reset_deck(Dqueue* deck, Card** dealer, Card** player);
	void dealer_wins();
	void player_wins();
	bool is_negative(int& a) const;
	bool is_dealer(const Player* p) const;
};

#endif // !_BLACKJACK_H_