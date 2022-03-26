#include "Player.h"

const int& Player::GetBetAmount() const
{
	return m_betAmount;
}

void Player::SetBetAmount(int amount)
{
	m_betAmount = amount;
}

const int& Player::GetBalance() const
{
	return m_balance;
}

void Player::AddBetToBalance()
{
	m_balance += m_betAmount;
}

void Player::SubtractBetFromBalance()
{
	m_balance -= m_betAmount;
}
