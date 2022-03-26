#include "Deck.h"
#include <ctime>

void Deck::Shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_decK.begin(), m_decK.end(), mt);
}

std::ostream& operator<< (std::ostream& out, const Deck d)
{
    for (const auto card : d.m_decK)
    {
        out << card << '\n';
    }
    return out;
}