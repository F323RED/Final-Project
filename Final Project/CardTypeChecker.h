#include "PokerCard.h"
#include <vector>
#include <string>

using namespace std;

#ifndef CARD_TYPE_CHECKER_H
#define CARD_TYPE_CHECKER_H

// Card types, from big to small
enum CardType
{
	ROYAL_FLUSH,	// �P��j��
	STRAIGHT_FLUSH,	// �P�ᶶ
	FOUR_KIND,		// �|��
	FULL_HOUSE,		// ��Ī
	FLUSH,			// �P��
	STRAIGHT,		// ���l
	THREE_KIND,		// �T��
	TWO_PAIR,		// ���
	PAIR,			// �@��
	HIGH_CARD,		// ���P
	ERROR			// Error
};

class CardTypeChecker
{
public:
	// static function to check specific card type
	static CardType CardTypeCheck(vector<PokerCard>& hand);

	static void Sorting(vector<PokerCard>& hand);
	static void SortingByFace(vector<PokerCard>& hand);
	static void SortingBySuit(vector<PokerCard>& hand);

	static string toString(CardType type);
};

#endif