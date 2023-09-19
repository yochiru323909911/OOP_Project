#pragma once
#include "Bonus.h"

class KillBonus :public Bonus
{
private:
	static bool m_registerit;
public:
	KillBonus(const sf::Vector2f& pos, GameBoard& gameBoard);
	void hitBonus(PlayerCar* playerCar);
	virtual ~KillBonus() = default;
};

