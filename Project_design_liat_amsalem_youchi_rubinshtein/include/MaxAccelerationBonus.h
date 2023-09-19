#pragma once
#include "Bonus.h"
class MaxAccelerationBonus:public Bonus
{
private:
	static bool m_registerit;
public:
	MaxAccelerationBonus(const sf::Vector2f& pos, GameBoard& gameBoard);
	void hitBonus(int& maxSpeed);
	virtual ~MaxAccelerationBonus() = default;
};
