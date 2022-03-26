#pragma once


#include <random>
#include <algorithm>

#include "Card.h"

class Deck
{
    private:
        std::array<Card, 52>m_decK;
        int m_cardCounter{ 0 };
    
    public:
        Deck()
        {
            int index{ 0 };
            for (int suits = 0; suits < static_cast<int>(Card::Suit::max_suit); suits++)
            {
                for (int ranks = 0; ranks < static_cast<int>(Card::Rank::max_rank); ranks++)
                {
                    m_decK[index] = { static_cast<Card::Suit>(suits), static_cast<Card::Rank>(ranks) };
                    ++index;
                }
    
            }
        }
        const Card& DealCard()
        {
            if (m_cardCounter == 50)
            {
                Shuffle();
                m_cardCounter = 0;
            }
                
            return m_decK[m_cardCounter++];
        }
        void Shuffle();
     
        friend std::ostream& operator<< (std::ostream& out, const Deck d);
 
};

