#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

class Player
{

private:
	string p_name;                    //player name
	unsigned int cards_sum;          //player cards sum
	unsigned int r_won;             //rounds that the player won
	unsigned int r_lose;           //rounds that the player lose

public:
	Player(string name); //ctor
	//using defult dtor
	//using defult cctor
	friend ostream& operator<<(ostream& os, const Player& player); // print name and card_sum

	//"Extras":
	string get_name();                                    //return the player name     
	unsigned int get_cards_sum();                        //return the cards sum of the player
	void update_cards_sum(unsigned int _cards_sum);     //update the cards sum  
	unsigned int get_wins();                           //return the number of rounds that the player win
	unsigned int get_loses();                         //return the number of rounds that the player win
	void update_wins_and_loses(bool win_flag);       //update the number of wins or loses according the current round result

};



#endif