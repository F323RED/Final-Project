#include "DeckOfCard.h"
#include <cstdlib>
#include <ctime>

using namespace std;

DeckOfCard::DeckOfCard() : cardQueue(52){
	Reset();
}

void DeckOfCard::Reset() {
	cardQueue.Clear();	// Clear first to prevent unwanted issue

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cardQueue.Push(PokerCard(j, i));
		}
	}
}

void DeckOfCard::Shuffle() {
	int len = cardQueue.Length();

	srand(time(0));
	for (int i = 0; i < len; i++)
	{
		int j = rand() % len;

		// Maybe I can just use operator overloading?
		PokerCard temp = cardQueue[i];	// <- Yes, I can.
		cardQueue[i] = cardQueue[j];
		cardQueue[j] = temp;
	}
}

void DeckOfCard::Shuffle(int n)
{
	for (int i = 0; i < n; i++)
	{
		this->Shuffle();
	}
}

bool DeckOfCard::MoreCards() {
	return !cardQueue.IsEmpty();
}

int DeckOfCard::CardLeft() {
	return cardQueue.Length();
}

PokerCard DeckOfCard::DealCard() {
	return cardQueue.Pop();
}