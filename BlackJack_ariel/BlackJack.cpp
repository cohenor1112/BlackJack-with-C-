//////////////////////////////////////////////////////
/////////////////// BlackJack.cpp ////////////////////
//////////////////////////////////////////////////////
//													//
//	includes:										//
#include "BlackJack.h"								//
#include <iostream>									//
#include <time.h>									//
#include <string>									//
using namespace std;								//
//													//
//	statics init:									//
//													//
//													//
//////////////////////////////////////////////////////

/////////////////// constractors: /////////////////////

//////////////////////////////////
BlackJack::BlackJack() { 
//////////////////////////////////
	init_deck();
	set_player_dialog(m_player);
	m_dealer = new Player("Dealer");
	m_dealer_cards = new Card * [10];
	m_player_cards = new Card * [10];
	m_dealer_cards_idx = -1;
	m_player_cards_idx = -1;
	m_num_of_rounds = 0;
}

//////////////////////////////////
BlackJack::~BlackJack() {
//////////////////////////////////
	delete m_Deck;
	delete m_dealer;
	delete m_player;
	delete m_dealer_cards;
	delete m_player_cards;
}

///////////////////// Methods: ////////////////////////

//////////////////////////////////
void BlackJack::play() {
//////////////////////////////////
	while (1) {
		int answer = manu_dialog();
		if (answer == 1) {
			serve_cards();
			dealers_turn();
			while ((answer == 1) && (m_player->get_cards_value() < 21) &&( m_dealer->get_cards_value() < 21)) {
				answer = game_dialog();
				if (answer == 1) {
					take_card(m_player);
					print_cards(m_player_cards, m_player);
				}
			}
			declare_winner_and_reset();
		}
		else {
			cout << "out of " << (int)m_num_of_rounds << " rounds, you won " << (int)m_player->get_win_count();
			cout << " times and lost " << (int)m_player->get_lose_count() << " times" << endl;
			break;
		}
	}
}

//////////////////// Functions: ///////////////////////

//////////////////////////////////
void BlackJack::init_deck() {
//////////////////////////////////
	m_Deck = new Dqueue(Card::get_max_cards());
	for (int i = 0; i < Card::get_max_cards(); i++) {
		Card* c = new Card(Card::toss_val());
		m_Deck->push_front(c);
	}
}

//////////////////////////////////
void BlackJack::set_player_dialog(Player* player) {
//////////////////////////////////
	cout << "Hi, please enter your name:" << endl;
	string player_name;
	cin >> player_name;
	m_player = new Player(player_name);
}

//////////////////////////////////
int BlackJack::manu_dialog() const {
//////////////////////////////////
	int answer;
	cout << "Choose option:" << endl << "1. New round" << endl << "2. Quit game" << endl;
	do {
		cin >> answer;
	} while (!(answer == 1 || answer == 2));
	return answer;
}

//////////////////////////////////
int BlackJack::game_dialog() const {
//////////////////////////////////
	int answer;
	do {
		cout << "Choose option:" << endl << "1. Take a card from pile" << endl << "2. No more cards" << endl;
		cin >> answer;
	} while (!(answer == 1 || answer == 2));
	return answer;
}

//////////////////////////////////
void BlackJack::print_cards(Card**& cards,const Player* player) const {
//////////////////////////////////
	cout << player->get_name() << " cards:" << endl;
	int index = (player->get_name() == "Dealer") ? m_dealer_cards_idx : m_player_cards_idx;
	for (int i = 0; i <= index ; i++) {
		cout << *cards[i] << " ";
	}
	cout << "(Total of " << (int)player->get_cards_value() << ")" << endl;
}

//////////////////////////////////
void BlackJack::shuffle() {
//////////////////////////////////
	int max_cards = Card::get_max_cards();
	Card** temp_deck = new Card * [max_cards];
	//taking all cards to a temporary array to shuffle
	for (int i = 0; i < max_cards; i++)
		temp_deck[i] = m_Deck->pop_front();

	//We chose to swap 52 times 2 cards to shuffle. 
	//this process could be repeated but we decided that it is enough
	for (int i = 0; i < max_cards; i++) {
		int idx = (rand() % max_cards);
		swap(temp_deck[i], temp_deck[idx]);
	}

	//putting all cards in stack
	for (int i = 0; i < max_cards; i++)
		m_Deck->push_front(temp_deck[i]);

	delete temp_deck;
}

//////////////////////////////////
void BlackJack::serve_cards() {
//////////////////////////////////
	take_card(m_dealer); 
	take_card(m_dealer);
	take_card(m_player);
	take_card(m_player);
	print_cards(m_dealer_cards, m_dealer);
	print_cards(m_player_cards, m_player);
}

//////////////////////////////////
void BlackJack::take_card(Player* player) {
//////////////////////////////////
	Card* card = m_Deck->pop_front();
	if (is_dealer(player)) {//(player->get_name() == "Dealer") {
		m_dealer_cards[++m_dealer_cards_idx] = card; 
	}
	else {
		m_player_cards[++m_player_cards_idx] = card; 
	}
	player->set_card(card);
}

//////////////////////////////////
void BlackJack::dealers_turn() {
//////////////////////////////////
	while (m_dealer->get_cards_value() < 16) {
		take_card(m_dealer);
		print_cards(m_dealer_cards,m_dealer);
	}
}

//////////////////////////////////
void BlackJack::declare_winner_and_reset() {
//////////////////////////////////
	m_num_of_rounds++;
	int player_distance = 21 - m_player->get_cards_value();
	int dealer_distance = 21 - m_dealer->get_cards_value();
	// negative means 
	if (is_negative(player_distance) && (!is_negative(dealer_distance)))
		dealer_wins();			//player over 21, dealer below 21
	else if ((!is_negative(player_distance)) && is_negative(dealer_distance))
		player_wins();			//dealer over 21, player below 21
	else if ((player_distance < dealer_distance) && (!is_negative(player_distance)))
		player_wins();			//player distance is closer to 21 and not negative
	else if ((player_distance > dealer_distance) && (!is_negative(dealer_distance)))
		dealer_wins();			//dealer distance is closer to 21 and not negative
	else
		cout << "it's a tie! No one wins" << endl;
	m_player->reset_score();
	m_dealer->reset_score();
	reset_deck(m_Deck,m_dealer_cards,m_player_cards);
	shuffle();
}

//////////////////////////////////
void BlackJack::dealer_wins() {
//////////////////////////////////
	cout << m_dealer->get_name() << " wins" << endl;
	m_player->record_lose();
}

//////////////////////////////////
void BlackJack::player_wins() {
//////////////////////////////////
	cout << m_player->get_name() << " wins" << endl;
	m_player->record_win();
}

//////////////////////////////////
void BlackJack::reset_deck(Dqueue* deck,Card** dealer,Card** player) {
//////////////////////////////////
	for (char i = 0; i <= m_dealer_cards_idx; i++) {
		deck->push_front(dealer[i]);
		dealer[i] = NULL;
	}
	for (char i = 0; i <= m_player_cards_idx; i++) {
		deck->push_front(player[i]);
		player[i] = NULL;
	}
	m_dealer_cards_idx = -1;
	m_player_cards_idx = -1;
}

//////////////////////////////////
bool BlackJack::is_negative(int& a) const{
//////////////////////////////////
	if (a < 0)
		return true;
	else
		return false;
}

//////////////////////////////////
bool BlackJack::is_dealer(const Player* p) const {
	//////////////////////////////////
	if (p->get_name() == "Dealer")
		return true;
	else
		return false;
}