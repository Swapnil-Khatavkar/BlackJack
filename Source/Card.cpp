#include "Card.h"


int Card::GetValue()
{
    switch (m_rank)
    {
        case Rank::ace:     return 11;  break;
        case Rank::two:     return 2;   break;
        case Rank::three:   return 3;   break;
        case Rank::four:    return 4;   break;
        case Rank::five:    return 5;   break;
        case Rank::six:     return 6;   break;
        case Rank::seven:   return 7;   break;
        case Rank::eight:   return 8;   break;
        case Rank::nine:    return 9;   break;
        case Rank::ten:     return 10;  break;
        case Rank::jack:    return 10;  break;
        case Rank::queen:   return 10;  break;
        case Rank::king:    return 10;  break;
        default:
            return 0;
            break;
    }
}

std::string_view Card::GetSuitString(Suit suit)
{
    static std::array<std::string, static_cast<int>(Suit::max_suit)>suits{
        "Club","Diamond","Heart","Spades"
    };
    return suits.at(static_cast<int>(suit));
}


std::string_view Card::GetRankString(Rank rank)
{
    static std::array<std::string, static_cast<int>(Rank::max_rank)>ranks{
        "Ace"
        , "Two", "Three", "Four", "Five", "Six", "Seven"
        , "Eight", "Nine", "Ten", "Jack", "Queen", "King"
    };
    return ranks.at(static_cast<int>(rank));
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    return out << card.GetRankString(card.m_rank) << " of " << card.GetSuitString(card.m_suit);
}
