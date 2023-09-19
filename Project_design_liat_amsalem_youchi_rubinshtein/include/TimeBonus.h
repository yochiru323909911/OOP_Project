#pragma once
#include "Bonus.h"

class TimeBonus:public Bonus
{
private:
	static bool m_registerit;
public:
	TimeBonus(const sf::Vector2f& pos, GameBoard& gameBoard);
	 void hitBonus();
	 virtual ~TimeBonus() = default;
};

