/*
Author : F323RED
Date : 2020/12/25
Describe : Card game, I guess.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "DeckOfCard.h"
#include "CardTypeChecker.h"

using namespace std;

int main()
{
	DeckOfCard deck;

	// Phase 1, Deal and print cards for players

	int cardPerPlayer = deck.CardLeft() / 4;
	deck.Shuffle(3);

	for (int player = 0; player < 4; player++) {
		switch (player) {
		case 0:
			cout << "Player A :\n\n";
			break;
		case 1:
			cout << "Player B :\n\n";
			break;
		case 2:
			cout << "Player C :\n\n";
			break;
		case 3:
			cout << "Player D :\n\n";
			break;
		}

		for (int card = 0; card < cardPerPlayer; card++)
		{
			cout << deck.DealCard().toString() << "\n";
		}

		cout << "-------------------------\n";
	}

	// Phase 2, Check your luck

	vector<PokerCard> handOfCard(5);

	deck.Reset();
	deck.Shuffle(3);	// Shuffle 3 times to make it more "random"

	for (int i = 0; i < 5; i++)
	{
		handOfCard[i] = deck.DealCard();
		cout << handOfCard[i].toString() << "\n";
	}

	cout << "\n" << CardTypeChecker::toString(CardTypeChecker::CardTypeCheck(handOfCard))
		<< "\n\n";

	/*
	// Test
	vector<PokerCard> nude(5);
	int counter[11] = { 0 };

	for (int i = 0; i < 100000; i++)
	{
		deck.Reset();
		deck.Shuffle(5);

		for (int i = 0; i < 5; i++)
		{
			nude[i] = deck.DealCard();
		}

		CardType t = CardTypeChecker::CardTypeCheck(nude);
		counter[(int)t]++;
	}

	for (int i = 0; i < 11; i++)
	{
		cout << setw(20) << left << (CardTypeChecker::toString((CardType)i) + " : ") << counter[i] << "\n";	// ((float)counter[i] / 100000) * 100
	}
	*/
}