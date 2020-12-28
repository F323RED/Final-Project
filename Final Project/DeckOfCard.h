#include "PokerCard.h"
#include "Queue.h"
#include <vector>

using namespace std;

#ifndef DECK_OF_CARD_H
#define DECK_OF_CARD_H

class DeckOfCard
{
private:
	Queue<PokerCard> cardQueue;

public:
	DeckOfCard();

	void Reset();		// Reset the deck

	void Shuffle();
	void Shuffle(int n);

	bool MoreCards();	// Check if any card left
	int CardLeft();

	PokerCard DealCard();
};

#endif
