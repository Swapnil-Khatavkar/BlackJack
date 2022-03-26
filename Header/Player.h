#pragma once
#include "Dealer.h"
class Player :
    public Dealer
{
private:
    int m_balance{ 1000 };
    int m_betAmount{ 0 };
public:
    Player(std::string name)//can not use initialization with ":" because m_name is not initialized at the moment
    {
        m_name = name;
    }
    const int& GetBetAmount()const;
    void SetBetAmount(int amount);
    const int& GetBalance()const;
    void AddBetToBalance();
    void SubtractBetFromBalance();
};

