#pragma once
#include<string>

struct GameStats
{
    static const int maxScore{ 21 };
    static const int minScore{ 17 };
};

class Dealer
{
    protected:
        int m_score{ 0 };
        std::string m_name{ "Dealer" };
    
    public:
    
        Dealer() = default;
    
        const int& GetScore()const;
        void AddScore(int value);
        const std::string& GetName()const;
        bool IsBust()const;
        bool HasBlackJack()const;
        void Reset();

};

