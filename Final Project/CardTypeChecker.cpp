#include "CardTypeChecker.h"

CardType CardTypeChecker::CardTypeCheck(vector<PokerCard>& hand)
{
	if (hand.size() != 5)	// Must have 5 cards
	{
		return CardType::ERROR;
	}

	vector<PokerCard> cards = hand;
	SortingByFace(cards);

	bool flush = true;
	bool straight = true;

	int firstSuit = cards[0].GetSuit();
	int firstFace = cards[0].GetFace();
	int face[13] = { 0 };
	int suit[4] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		if (cards[i].GetSuit() != firstSuit) {
			flush = false;
		}

		if (cards[i].GetFace() != firstFace + i) {
			straight = false;
		}

		face[cards[i].GetFace()]++;
		suit[cards[i].GetSuit()];
	}

	if (flush)
	{
		// 1. Check Royal Flush(A, 10 , J, Q, K and same suit)
		if (face[0] == 1 && face[9] == 1 && face[10] == 1 && face[11] == 1 && face[12] == 1)
		{
			return CardType::ROYAL_FLUSH;
		}
		else		
		{
			if (straight)	// 2. Check Straight Flush
			{
				return CardType::STRAIGHT_FLUSH;
			}
			else			// 5. Check Flush
			{
				return CardType::FLUSH;
			}
		}
	}
	else	
	{
		if (straight)	// 6. Check Straight
		{
			return CardType::STRAIGHT;
		}

		bool threeKind = false;
		bool twoKind = false;
		bool doubleTwoKind = false;

		for (int i = 0; i < 13; i++)
		{
			if (face[i] == 4)	// 3. Check Four of a Kind
			{
				return CardType::FOUR_KIND;
			}
			else if (face[i] == 3)
			{
				threeKind = true;
			}
			else if (face[i] == 2)
			{
				if (twoKind)
				{
					doubleTwoKind = true;
				}
				else
				{
					twoKind = true;
				}
			}
		}

		if (threeKind)	
		{
			if (twoKind)	// 4. Check Full House
			{
				return CardType::FULL_HOUSE;
			}
			else	// 7. Check Three of a Kind
			{
				return CardType::THREE_KIND;
			}
		}
		else
		{
			if (doubleTwoKind)	// 8. Check Two Pair
			{
				return CardType::TWO_PAIR;
			}
			else if(twoKind)	// 9. Check Pair
			{
				return CardType::PAIR;
			}
			else	// 10. Check High Card
			{
				return CardType::HIGH_CARD;
			}
		}
	}
}

string CardTypeChecker::toString(CardType type)
{
	string cardType;

	switch (type)
	{
	case CardType::ROYAL_FLUSH :
		cardType = "Royal Flush";
		break;

	case CardType::STRAIGHT_FLUSH :
		cardType = "Straight Flush";
		break;

	case CardType::FOUR_KIND :
		cardType = "Four of a Kind";
		break;

	case CardType::FULL_HOUSE :
		cardType = "Full House";
		break;

	case CardType::FLUSH :
		cardType = "Flush";
		break;

	case CardType::STRAIGHT :
		cardType = "Straight";
		break;

	case CardType::THREE_KIND :
		cardType = "Three of a Kind";
		break;

	case CardType::TWO_PAIR :
		cardType = "Two Pair";
		break;

	case CardType::PAIR :
		cardType = "One Pair";
		break;

	case CardType::HIGH_CARD :
		cardType = "High Card";
		break;

	default:
		cardType = "Error";
		break;
	}

	return cardType;
}

void CardTypeChecker::Sorting(vector<PokerCard>& hand)
{
	int len = hand.size() - 1;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i); j++) {
			int value1 = hand[j].GetFace() + (hand[j].GetSuit() * 13);
			int value2 = hand[j + 1].GetFace() + (hand[j + 1].GetSuit() * 13);

			if (value1 > value2) {
				PokerCard temp = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = temp;
			}
		}
	}
}

void CardTypeChecker::SortingByFace(vector<PokerCard>& hand)
{
	int len = hand.size() - 1;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i); j++) {
			int value1 = hand[j].GetFace();
			int value2 = hand[j + 1].GetFace();

			if (value1 > value2) {
				PokerCard temp = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = temp;
			}
		}
	}
}

void CardTypeChecker::SortingBySuit(vector<PokerCard>& hand)
{
	int len = hand.size() - 1;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i); j++) {
			int value1 = hand[j].GetSuit();
			int value2 = hand[j + 1].GetSuit();

			if (value1 > value2) {
				PokerCard temp = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = temp;
			}
		}
	}
}
