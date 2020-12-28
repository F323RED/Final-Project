#include <string>

using namespace std;

#ifndef POKER_CARD_H
#define POKER_CARD_H

class PokerCard
{
private:
	int faceID;
	int suitID;

public:
	static const string FACES_NAME[13];	// Reference of face name
	static const string SUITS_NAME[4];

	// Constructers
	PokerCard();
	PokerCard(int face, int suit);

	
	string toString();	// Translate this face and suit to string
	
	int GetFace();
	int GetSuit();
};

#endif