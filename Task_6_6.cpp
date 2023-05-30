#include <iostream>
#include <array>

int g_ascii_2 = 50;
int g_numberCards = 52;

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
    if(p_card.level < CARD_10)
    {  
        letterLevel = static_cast<char>(CARD_3 + g_ascii_0);
    }
    else
    {
        switch (p_card.level)
        {
        case CARD_10:
            letterLevel = '0';
            break;
        case CARD_V:
            letterLevel = 'V';
            break;
        case CARD_D:
            letterLevel = 'D';
            break;
        case CARD_K:
            letterLevel = 'K';
            break;
        case CARD_T:
            letterLevel = 'T';
            break;
        }
    }
    switch (p_card.suit)
    {
    case CLUBS:
        letterSuit = 'C';
        break;
    case DIAMONDS:
        letterSuit = 'D';
        break;
    case HEARTS:
        letterSuit = 'H';
        break;
    case SPADES:
        letterSuit = 'S';
        break;
    }
    std::cout << "Card: " << letterLevel << letterSuit << std::endl;

}

void cardInit(const std::array <Card, g_numberCards> &p_deck)
{

}

int main()
{
    Card cadr_1, card_2, card_3;
    cadr_1.level = CARD_3; cadr_1.suit = HEARTS;
    card_2.level = CARD_10; card_2.suit = SPADES;
    card_3.level = CARD_K; card_3.suit = DIAMONDS;
    printCard(cadr_1);
    printCard(card_2);
    printCard(card_3);
    //-------------------------------------------
    std::array<Card, 52> deck;
    cardInit(deck);


    return 0;
}
