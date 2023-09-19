#pragma once
#include "Bonus.h"
#include "GameBoard.h"

class CreditBonus:public Bonus
{
private:
	static bool m_registerit;

public:
	CreditBonus(const sf::Vector2f& pos, GameBoard& gameBoard);
	void hitBonus();
	virtual ~CreditBonus() = default;
};
