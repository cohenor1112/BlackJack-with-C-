#include "BlackJack.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif 

BlackJack::BlackJack() 
	: player_ptr() , player_card() , dealer_card() , /*Dealer_ptr() ,*/ p_card_indx(-1), d_card_indx(-1), player_done(0) , rounds(0), p_sum(0), d_sum(0), p_ace_counter(0), d_ace_counter(0)
{
	Dealer_ptr = new Player("Dealer");
	card_arr = new Card * [52];
	player_cards_pointers = new Card * [11];
	dealer_cards_pointers = new Card * [11];
	for (int i =0; i < 52; i++)
		card_arr[i] = new Card(Card::toss_val());
	card_pile = new Dequeue;
	card_pile->first_fill_Dequeue(card_arr);
}

BlackJack::~BlackJack()
{
	delete card_pile;
	delete Dealer_ptr;
	delete[] card_arr;
	delete[] player_cards_pointers;
	delete[] dealer_cards_pointers;
	delete player_ptr;
}

void BlackJack::play()
{
	cout << "Welcome to Blackjack!" << endl;
	cout << "please enter your name: ";
	cin >> player_name;
	player_ptr = new Player(player_name);     // build player
	while (!player_done)
	{
		unsigned int game_choice = this->game_option();
		if (game_choice == 1)
		{
			card_pile->mix_Dequeue();
			add_card_p(*Dealer_ptr, *card_pile);
			add_card_p(*Dealer_ptr, *card_pile);
			add_card_p(*player_ptr, *card_pile);
			add_card_p(*player_ptr, *card_pile);
			print_cards(*Dealer_ptr);
			print_cards(*player_ptr);
			unsigned int player_choice_hit_stand = 2;
			bool once_stand_flag = false;
			while (d_sum < 17) 
			{
				add_card_p(*Dealer_ptr, *card_pile);
				print_cards(*Dealer_ptr);
				if (d_sum > 21)
				{
					break; //player win!
				}
				if (once_stand_flag == false)
					player_choice_hit_stand = this->while_playing_choose_option();
				if (once_stand_flag == false && player_choice_hit_stand == 1)
				{
					add_card_p(*player_ptr, *card_pile);
					print_cards(*player_ptr);
					if (p_sum > 21)
					{
						once_stand_flag = true;             //?
						break; //dealer win!
					}
				}
				else
				{
					once_stand_flag = true;
				}
			}
			while (d_sum > 16 && once_stand_flag == false)
			{
				if (d_sum > 21)
				{
					break; // player wins!
				}
				player_choice_hit_stand = this->while_playing_choose_option();
				if (player_choice_hit_stand == 1)
				{
					add_card_p(*player_ptr, *card_pile);
					print_cards(*player_ptr);
					if (p_sum > 21)
					{
						break; //dealer win!
					}
				}
				else
				{
					once_stand_flag = true;
				}
			}
			who_won(*Dealer_ptr, *player_ptr);
			restart(*card_pile);
		}
		else if (game_choice == 2)
		{
			restart(*card_pile);
			this->end_print(*player_ptr);
			player_done = 1;

			return;
		}
	}
}

void BlackJack::end_print(Player& gamer)
{
	cout << "out of " << rounds << " rounds" << ", you won: " << gamer.get_wins() << " and lost: " << gamer.get_loses() << endl << "Bye Bye";
}

//Extras:

unsigned int BlackJack::game_option()
{
	cout << "choose option: " << endl;
	cout << "1.New round" << endl;
	cout << "2.Quit game" << endl;
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2)
		cin >> choice;
	return choice;
}

void BlackJack::add_card_p(Player& player, Dequeue& card_pile)
{
	if (player.get_name() == "Dealer")
	{
		d_card_indx++;
		dealer_cards_pointers[d_card_indx] = card_pile.pop_front();
		if (dealer_cards_pointers[d_card_indx]->get_BJ_value() == 11)
			d_ace_counter++;
		//update sum
		d_sum = d_sum + dealer_cards_pointers[d_card_indx]->get_BJ_value();
		if (d_sum > 21 && d_ace_counter > 0)
		{
			d_ace_counter--;
			d_sum -= 10;
		}
		player.update_cards_sum(d_sum);
	}
	else
	{
		p_card_indx++;
		player_cards_pointers[p_card_indx] = card_pile.pop_front();
		if (player_cards_pointers[p_card_indx]->get_BJ_value() == 11)
			p_ace_counter++;
		//update sum
		p_sum = p_sum + player_cards_pointers[p_card_indx]->get_BJ_value();
		if (p_sum > 21 && p_ace_counter > 0)
		{
			p_ace_counter--;
			p_sum -= 10;
		}
		player.update_cards_sum(p_sum);
	}
	return;
}

void BlackJack::print_cards(Player& player)
{
	if (player.get_name() == "Dealer")
	{
		cout << player;
		for (int i = 0; i <= d_card_indx; i++)
		{
			cout << dealer_cards_pointers[i]->get_card_name() << " ";
		}
	}
	else
	{
		cout << player;
		for (int i = 0; i <= p_card_indx; i++)
		{
			cout << player_cards_pointers[i]->get_card_name() << " ";
		}
	}
	cout << endl;
	return;
}

unsigned int BlackJack::while_playing_choose_option()
{
	cout << "choose option: " << endl;
	cout << "1.take a card from a pile" << endl;
	cout << "2.no more cards" << endl;
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2)
		cin >> choice;
	return choice;
}

void BlackJack::who_won(Player& dealer, Player& player)                        //need to try to leshaper!
{
	if (d_sum > 21)
	{
		cout << player.get_name() << " wins!" << endl;
		rounds++;
		player.update_wins_and_loses(1);
		return;
	}
	if (p_sum > 21)
	{
		cout << "Dealer wins!" << endl;
		rounds++;
		player.update_wins_and_loses(0);
		return;
	}
	if (d_sum > p_sum)
	{
		cout << "Dealer wins!" << endl;
		rounds++;
		player.update_wins_and_loses(0);
		return;
	}
	else if (d_sum < p_sum)
	{
		cout << player.get_name() << " wins!" << endl;
		rounds++;
		player.update_wins_and_loses(1);
		return;
	}
	else
	{
		cout << "It's a tie! " << endl;
		rounds++;
		return;
	}
}

void BlackJack::restart(Dequeue& card_pile)
{
	int i = 0;
	for (i = 0; i <= p_card_indx; i++)
	{
		card_pile.push_front(player_cards_pointers[i]);
	}
	for (i = 0; i <= d_card_indx; i++)
	{
		card_pile.push_front(dealer_cards_pointers[i]);
	}
	d_card_indx = -1;
	p_card_indx = -1;
	d_sum = 0;
	p_sum = 0;
	player_ptr->update_cards_sum(p_sum);
	Dealer_ptr->update_cards_sum(d_sum);
}
