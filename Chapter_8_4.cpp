#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>

class Card
{
    public: 
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

    private:
    CardRank m_rank;
    CardSuit m_suit;

    public:
    Card (CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) : m_rank(rank), m_suit(suit) {}

    void printCard () const
{
    switch (m_rank)
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
    switch (m_suit)
    {
        case SUIT_CLUB:      std::cout <<  'C';  break;
        case SUIT_DIAMOND:   std::cout <<  'D';  break;
        case SUIT_HEART:     std::cout <<  'H';  break;
        case SUIT_SPADE:     std::cout <<  'S';  break;
    }
}
    
const int getCardValue() const
{
        switch (m_rank)
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

};

class Deck
{
    private:
    static const int numberCards = 52;
    std::array <Card, numberCards> m_deck;
    int m_cardIndex = 0;

    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0); // const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
            return static_cast<int>(rand()*fraction*(max - min + 1) + min);
    }

     void swapCard(Card &firstCard, Card &secondCard)
    {
        Card temp = firstCard;
        firstCard = secondCard;
        secondCard = temp;
    }

    public:
    Deck() 
    {
        int card = 0;
        for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
        {
            for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
            {
                m_deck[card] = Card( static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
                ++card;
            }   
        }
    }

    void printDeck() const
    {
        for (const auto &card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }
        std::cout << std::endl;
    }

    void shuffleDeck()
    {
        for(int index = 0; index < numberCards; ++index)
        {
            int swapIndex = getRandomNumber(0, 51);
            swapCard(m_deck[index], m_deck[swapIndex]);
        }
        m_cardIndex = 0;
    }

    const Card& dealCard()
    {
        assert (m_cardIndex < 52);
        return m_deck[m_cardIndex++];
    }
};
char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: "; 
    char choice; 
    do 
    { 
        std::cin >> choice; 
    } while (choice != 'h' && choice != 's'); 
    
    return choice;
}

bool playBlackjack(Deck &deck)
{
    int playerTotal  = 0;
    int dealerTotal = 0;
    // Дилер получает одну карту
    dealerTotal += deck.dealCard().getCardValue(); 
    std::cout << "The dealer is showing: " << dealerTotal << std::endl;
    // Игрок получает две карты
    playerTotal += deck.dealCard().getCardValue(); 
    playerTotal += deck.dealCard().getCardValue();
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
        playerTotal += deck.dealCard().getCardValue();
    }

    // Если игрок не проиграл и у него не больше 21 очка, 
    //то тогда дилер получает карты до тех пор, пока у него не получится в сумме 17 очков
    while (dealerTotal < 17)
    {
        dealerTotal += deck.dealCard().getCardValue();
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
    // используем системные часы в качестве стартового значения 
    rand(); // пользователям Visual Studio: делаем сброс первого случайного числа 
    Deck deck;
    deck.shuffleDeck(); 
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