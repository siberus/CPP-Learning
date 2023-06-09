#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

const int g_numberCards = 52;

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS   
};

enum CardRank
{
   RANK_2,
   RANK_3,
   RANK_4,
   RANK_5,
   RANK_6,
   RANK_7,
   RANK_8,
   RANK_9,
   RANK_10,
   RANK_JACK,
   RANK_QUEEN,
   RANK_KING,
   RANK_ACE,
   MAX_RANKS
};

struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard(const Card &card)
{
    //char letterLevel, letterSuit;
  
    switch (card.rank)
    {
        case RANK_2:        std::cout << '2';  break;
        case RANK_3:        std::cout << '3';  break;
        case RANK_4:        std::cout << '4';  break;
        case RANK_5:        std::cout << '5';  break;
        case RANK_6:        std::cout << '6';  break;
        case RANK_7:        std::cout << '7';  break;
        case RANK_8:        std::cout << '8';  break;
        case RANK_9:        std::cout << '9';  break;
        case RANK_10:       std::cout << '0';  break;
        case RANK_JACK:     std::cout << 'J';  break;
        case RANK_QUEEN:    std::cout << 'Q';  break;
        case RANK_KING:     std::cout << 'K';  break;
        case RANK_ACE:      std::cout << 'A';  break;
    
    }
    switch (p_card.suit)
    {
        case SUIT_CLUB:      std::cout <<  'C';  break;
        case SUIT_DIAMOND:   std::cout <<  'D';  break;
        case SUIT_HEART:     std::cout <<  'H';  break;
        case SUIT_SPADE:     std::cout <<  'S';  break;
    }
}

void printDeck(const std::array<Card, g_numberCards> deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

void swapCard(Card &firstCard, Card &secondCard)
{
    Card temp = firstCard;
    firstCard = secondCard;
    secondCard = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand()*fraction*(max - min + 1) + min);
}

void shuffleDeck(std::array<Card, g_numberCards> &deck)
{
    for(int index = 0; index < g_numberCards; ++index)
    {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(deck[index], deck[swapIndex]);
    }
}

int getCardValue(const Card &card)
{
        switch (card.rank)
        {
        case RANK_2:        return 2;
        case RANK_3:        return 3;
        case RANK_4:        return 4;
        case RANK_5:        return 5;
        case RANK_6:        return 6;
        case RANK_7:        return 7;
        case RANK_8:        return 8;
        case RANK_9:        return 9;
        case RANK_10:       return 10;
        case RANK_JACK:     return 10;
        case RANK_QUEEN:    return 10;
        case RANK_KING:     return 10;
        case RANK_ACE:      return 11;
        }

        return 0;
}

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: "; 
    char choice; 
    do 
    { 
        std::cin >> choice; 
    } while (choice != 'h' && choice != 's'); 
    if (choice == 'h')
        return choice;    
}

void cardInit(std::array <Card, g_numberCards> &p_deck)
{
    int card = 0;
    for (int suit = 0; suit < MAX_SUITS; ++suit)
    {
        for (int rank = 0; rank < MAX_RANKS; ++rank)
        {
            p_deck[card].suit = static_cast<CardSuit>(suit);
            p_deck[card].rank = static_cast<CardSuit>(rank);
            ++card;
        }
        
    }
    
}

bool playBlackjack(const std::array <Card, g_numberCards> deck)
{
    const Card *cardPtr = &deck[0];
    int playerTotal  = 0;
    int dealerTotal = 0;
    // Дилер получает одну карту
    dealerTotal += getCardValue(*cardPtr++); 
    std::cout << "The dealer is showing: " << dealerTotal << std::endl;
    // Игрок получает две карты
    playerTotal += getCardValue(*cardPtr++); 
    playerTotal += getCardValue(*cardPtr++);
    // Игрок начинает
    while (true)
    {
        std::cout << "You have: " << playerTotal << std::endl;
        // Смотрим, не больше ли 21 очка у игрока
        if (playerTotal > 21) 
            return false;
        char choice = getPlayerChoice();
        if (choice == 's')
            break; 
        //Игрок берет карту
        playerTotal += getCardValue(*cardPtr++);
    }

    // Если игрок не проиграл и у него не больше 21 очка, 
    //то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17 очков
    while (dealerTotal < 17)
    {
        dealerTotal += getCardValue(*cardPtr++);
        std::cout << "The dealer now has: " << dealerTotal << std::endl;
    }
    
    // Если у дилера больше 21 очка, то игрок победил 
    if (dealerTotal > 21) 
        return true; 
    return (playerTotal > dealerTotal);
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    std::array<Card, g_numberCards> deck;
    cardInit(deck);
    shuffleDeck(deck);
    if(playBlackjack(deck))
    {
        std::cout << "You  won!!!" << std::endl;
    }
    else
    {
        std::cout << "You  lose!!!" << std::endl;
    }
    std::cin.clear(); 
    std::cin.ignore(32767, '\n'); 
    std::cin.get();
    
    return 0;
}
