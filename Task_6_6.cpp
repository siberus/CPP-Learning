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

bool getChoice()
{
    std::cout << "(h) to hit, or (s) to stand: "; 
    char choice; 
    do 
    { 
        //std::cout << '\b';
        std::cin >> choice; 
    } while (choice != 'h' && choice != 's'); 
    if (choice == 'h')
        return true;
    else
        return false;    
}



void cardInit(std::array <Card, g_numberCards> &p_deck)
{
    int i = 0;
    for (int countSuit = 0;  countSuit < MAX_SUITS; ++countSuit)
    {
        for (int countLevel = 0; countLevel < MAX_RANGE; ++countLevel)
        {
           /*  p_deck[(countSuit*13)+(countLevel)].level = static_cast<Levels>(countLevel);
            p_deck[(countSuit*13)+(countLevel)].suit = static_cast<Suits>(countSuit); */
            p_deck[i].level = static_cast<Levels>(countLevel);
            p_deck[i].suit = static_cast<Suits>(countSuit);
            ++i;
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

int getCardValue(const Card &p_card)
{
    int value = static_cast<int>(p_card.level)+2;
    if( (value > 10) && (value < 14) )
        value = 10;
    if (value == 14)
        value = 11;
    return value;
}

bool playBlackjack(const std::array <Card, g_numberCards> &p_deck)
{
    const Card *cardPtr = &p_deck[0];
    int playerCount  = 0;
    int dealerCount = 0;
    // Дилер получает одну карту
    dealerCount += getCardValue(*cardPtr++); 
    std::cout << "The dealer is showing: " << dealerCount << std::endl;
    // Игрок получает две карты
    playerCount += getCardValue(*cardPtr++); 
    playerCount += getCardValue(*cardPtr++);
    // Игрок начинает
    while (true)
    {
        std::cout << "You have: " << playerCount << std::endl;
        // Смотрим, не больше ли 21 очка у игрока
        if (playerCount > 21) 
            return false;
        if (!getChoice())
            break; 
        //Игрок берет карту
        playerCount += getCardValue(*cardPtr++);
    }

    // Если игрок не проиграл и у него не больше 21 очка, 
    //то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17 очков
    while (dealerCount < 17)
    {
        dealerCount += getCardValue(*cardPtr++);
        std::cout << "The dealer now has: " << dealerCount << std::endl;
    }
    
    // Если у дилера больше 21 очка, то игрок победил 
    if (dealerCount > 21) 
        return true; 
    return (playerCount > dealerCount);

   /*  std::cout << "Your cards: " << std::endl;
    printCard(p_deck[indexDeck]);
    std::cout << std::endl;
    player += getCardValue(p_deck[indexDeck]);
    ++indexDeck;
    while (getChoise())
    {
        printCard(p_deck[indexDeck]);
        std::cout << std::endl;
        player += getCardValue(p_deck[indexDeck]);
        ++indexDeck;
    }
    if (player > 21)
    {
        return false;
    }
    while (diller < 17)
    {
        diller += getCardValue(p_deck[indexDeck]);
        ++indexDeck;
    }
    if (diller > 21)
    {
        return true;
    }
    return player < diller ? false : true; */
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<Card, g_numberCards> deck;
    cardInit(deck);
    //printDeck(deck);
    shuffleDeck(deck);
    //printDeck(deck);

    if(playBlackjack(deck))
    {
        std::cout << " You  won!!!" << std::endl;
    }
    else
    {
        std::cout << " You  lose!!!" << std::endl;
    }
    
    return 0;
}
