#include <iostream>

enum Levels
{
   CARD_2,
   CARD_3,
   CARD_4,
   CARD_5,
   CARD_6,
   CARD_7,
   CARD_8,
   CARD_9,
   CARD_10,
   CARD_V,
   CARD_D,
   CARD_K,
   CARD_T,
   MAX_RANGE
};

enum Suits
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    MAX_SUITS   
};

struct Card
{
    int level;
    int suit;
};

void printCard(const Card &p_card)
{
    char letterLevel, letterSuit;
    

}


