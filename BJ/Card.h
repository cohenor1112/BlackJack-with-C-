#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
using namespace std;
#include <time.h>
#include<string>



class Card
{

private:
	int BJ_value;                                                            // BJ value
	string card_name;                                                       //card name

	static int number_of_cards_already_made;                                //the number of cards that made till now
	static int cards_hist[14];                                             //the number of cards from each type that made till now ([0]not ligal!!, [1]CARD A's------> [13]CARD K's) 
	static int total_number_of_cards_need;                                //total number of cards in 1 dequeue (52)
	static int number_of_same_card;                                      //the number of cards to create for every type in 1 dequeue (4)
	//Extras:
	static string cards_names[];                                       //string array for the name(symbol) of the cards ("A","1","2"...."K")

public:
	Card(int value);                                                        //ctor
	//using default dtor
	//using default copy ctor
	static int toss_val();                                                  //Scores a numerical value to the card according to the rules of 4 cards per card type
	friend ostream& operator<<(ostream& os, const Card& c);                 //printing card
	//Extras:
	unsigned int give_BJ_value(const int card_number);                        //give the card valid bj value
	unsigned int get_BJ_value();                                             //returns the card valid bj value
	const string give_name_to_card(const int card_number);                  //using in the constractur to initialize the private member "card_name"
	const string get_card_name();                                          //return the card name(symbol)

};

#endif

