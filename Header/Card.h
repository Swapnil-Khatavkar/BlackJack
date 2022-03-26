#pragma once

#include <iostream>
#include <string_view>
#include <array>


class Card
{
    public:
        enum class Suit
        {
            club,
            diamond,
            heart,
            spade,
            max_suit
        };

        enum class Rank
        {
            ace,
            two,
            three,
            four,
            five,
            six,
            seven,
            eight,
            nine,
            ten,
            jack,
            queen,
            king,
            max_rank
        };
 
    private:
        Suit m_suit{ Suit::spade };
        Rank m_rank{ Rank::ace };
    
    public:
        Card() = default;
        Card(Suit suit, Rank rank) :m_suit{ suit }, m_rank{ rank }
        {}
    
        int GetValue();
    
        static std::string_view GetSuitString(Suit suit);
        static std::string_view GetRankString(Rank rank);
    
        friend std::ostream& operator<<(std::ostream & out, const Card & card);
};

