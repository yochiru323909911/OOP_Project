#pragma once
#include "Bonus.h"
#include "Consts.h"

class CurAccelerationBonus:public Bonus
{
private:
	static bool m_registerit;
public:
	CurAccelerationBonus(const sf::Vector2f& pos, GameBoard& gameBoard);
	 void hitBonus(float& curSpeed, const float maxSpeed);
	 virtual ~CurAccelerationBonus() = default;
};
