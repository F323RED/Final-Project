#include "PokerCard.h"
#include <vector>
#include <string>

using namespace std;

#ifndef CARD_TYPE_CHECKER_H
#define CARD_TYPE_CHECKER_H

// Card types, from big to small
enum CardType
{
	ROYAL_FLUSH,	// 同花大順
	STRAIGHT_FLUSH,	// 同花順
	FOUR_KIND,		// 四條
	FULL_HOUSE,		// 葫蘆
	FLUSH,			// 同花
	STRAIGHT,		// 順子
	THREE_KIND,		// 三條
	TWO_PAIR,		// 兩對
	PAIR,			// 一對
	HIGH_CARD,		// 散牌
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