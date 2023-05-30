#include <iostream>
#include <array>
#include <algorithm>
#include <cstdlib>
#include <time.h>

//const int g_ascii_2 = 50;
const int g_numberCards = 52;

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
    Levels level;
    Suits suit;
};

void printCard(const Card &p_card)
{
    char letterLevel, letterSuit;
  
    switch (p_card.level)
    {
        case CARD_2:  letterLevel = '2';  break;
        case CARD_3:  letterLevel = '3';  break;
        case CARD_4:  letterLevel = '4';  break;
        case CARD_5:  letterLevel = '5';  break;
        case CARD_6:  letterLevel = '6';  break;
        case CARD_7:  letterLevel = '7';  break;
        case CARD_8:  letterLevel = '8';  break;
        case CARD_9:  letterLevel = '9';  break;
        case CARD_10:  letterLevel = '0';  break;
        case CARD_V:   letterLevel = 'V';  break;
        case CARD_D:   letterLevel = 'D';  break;
        case CARD_K:   letterLevel = 'K';  break;
        case CARD_T:   letterLevel = 'T';  break;
    
    }
    switch (p_card.suit)
    {
        case CLUBS:  letterSuit = 'C';  break;
        case DIAMONDS:  letterSuit = 'D';  break;
        case HEARTS:  letterSuit = 'H';  break;
        case SPADES:  letterSuit = 'S';  break;
    }
    std::cout << letterLevel << letterSuit;

}

void cardInit(std::array <Card, g_numberCards> &p_deck)
{
    for (int countSuit = 0;  countSuit < MAX_SUITS; ++countSuit)
    {
        for (int countLevel = 0; countLevel < MAX_RANGE; ++countLevel)
        {
            p_deck[(countSuit*13)+(countLevel)].level = static_cast<Levels>(countLevel);
            p_deck[(countSuit*13)+(countLevel)].suit = static_cast<Suits>(countSuit);
        }
        
    }
    
}

void printDeck(const std::array<Card, g_numberCards> &p_deck)
{
    for (const auto element : p_deck)
    {
        printCard(element);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

void swapCard(Card &firstCard, Card &secondCard)
{
    std::swap(firstCard, secondCard);
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand()*fraction*(max - min + 1) + min);
}

void shuffleDeck(std::array<Card, g_numberCards> &p_deck)
{
    for(auto &element : p_deck)
    {
        int numRandomCard = getRandomNumber(0, 51);
        swapCard(element, p_deck[numRandomCard]);
    }
}

int getCardValue(Card &p_card)
{
    return (static_cast<int>(p_card.level)+2);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card, g_numberCards> deck;
    cardInit(deck);
    printDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);
    std::cout << std::endl;
    std::cout << getCardValue(deck[4]) << std::endl;
    std::cout << getCardValue(deck[8]) << std::endl;
    std::cout << getCardValue(deck[20]) << std::endl;
    std::cout << getCardValue(deck[10]) << std::endl;
    std::cout << getCardValue(deck[42]) << std::endl;
    std::cout << getCardValue(deck[35]) << std::endl;
    
    return 0;
}
