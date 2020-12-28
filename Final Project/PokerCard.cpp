#include "PokerCard.h"
#include <string>

using namespace std;

// Definition of face name and suit name
const string PokerCard::FACES_NAME[13] = 
{
		"Ace", "Deuce",
		"Three", "Four", "Five", "Six",
		"Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King"
};

const string PokerCard::SUITS_NAME[4] = 
{
		"Hearts", "Diamonds", "Clubs", "Spades"
};


// Define class methods
PokerCard::PokerCard(){ 
	faceID = 0;
	suitID = 0;
}

PokerCard::PokerCard(int face, int suit) {
	faceID = face;
	suitID = suit;

	// Check if value out of bound
	if (faceID < 0) {
		faceID = 0;
	}
	else if (faceID > 12) {
		faceID = 12;
	}


	if (suitID < 0) {
		suitID = 0;
	}
	else if (suitID > 3) {
		suitID = 3;
	}
}


string PokerCard::toString() {
	return FACES_NAME[faceID] + " of " + SUITS_NAME[suitID];
}

int PokerCard::GetFace() {
	return faceID;
}

int PokerCard::GetSuit() {
	return suitID;
}