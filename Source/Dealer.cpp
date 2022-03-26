#include "Dealer.h"

const int& Dealer::GetScore() const
{
	return m_score;
}

void Dealer::AddScore(int value)
{
	m_score += value;
}

const std::string& Dealer::GetName() const
{
	return m_name;
}

bool Dealer::IsBust() const
{
	return m_score > GameStats::maxScore;
}

bool Dealer::HasBlackJack() const
{
	return m_score == GameStats::maxScore;
}

void Dealer::Reset()
{
	m_score = 0;
}
