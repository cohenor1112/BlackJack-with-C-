#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <time.h>
#include <string>
#include <iostream>
using namespace std;

#include "Card.h"
#include "Dequeue.h"
#include "Player.h"

class BlackJack
{

private:
	//player pointer
	Player* player_ptr;
	//array of pointers type Card
	Card** card_arr;
	//pack of cards type Dequeue
	Dequeue* card_pile;
	//array of pointers type Card to the player (Stores pointer of cards he took)
	Card** player_cards_pointers;
	//array of string of the Card that the player took 
	string* player_card[11];
	//array of pointers type Card to the dealer (Stores pointer of cards he took)
	Card** dealer_cards_pointers;
	//array of string of the Card that the dealer took 
	string* dealer_card[11];
	//stores how many round the player played
	int rounds;
	//Extras:
	string player_name;
	Player* Dealer_ptr;
	//index of player last card given
	int p_card_indx;
	//index of dealer last card given
	int d_card_indx;
	//1 if player chose to quit the game and 0 if doesnt
	bool player_done;
	//player sum of hand
	unsigned int p_sum;
	//dealer sum of hand
	unsigned int d_sum;
	//counting the number of aces the player has in his hand
	int p_ace_counter;
	//counting the number of aces the dealer has in his hand
	int d_ace_counter;

public:
	//Ctor
    //Initializes the members player_ptr , player_card , dealer_card , /*Dealer_ptr ,*/ p_card_indx, d_card_indx, player_done , rounds, p_sum, d_sum, p_ace_counter, d_ace_counter
    //creates dealer(type player) , 52 cards (type Card) ,card pile (type dequeue) ,and dealer and player hands(pointers to Card) 
	BlackJack();
	//Dtor
	//Delete all created dynamic allocations.
	~BlackJack();
	//creates player(type player) and starting the blackjack game
	void play();
	//prints how much the player won and lost
	void end_print(Player& gamer);
    //Extras:
	//printing to the player his options and returns 1 if he chose new round or 2 if he chose to quit
	unsigned int game_option();
	//takes (and remove) from the card pile a card and moving it to the player/dealer hand
	void add_card_p(Player& player, Dequeue& card_pile);
	//prints the player/dealer cards
	void print_cards(Player& player);
	//prints to the player his options and returns 1 if he chose to take new card or 2 if he chose to stand
	unsigned int while_playing_choose_option();
	//prints who won (dealer or player)
	void who_won(Player& dealer, Player& player);
	//restarts everything (dealer/player hand and their sum of hands, card pile) to a new round/to quit the game
	void restart(Dequeue& card_pile);
};


#endif