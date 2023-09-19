#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "Consts.h"
#include <SFML/Graphics.hpp>

class StaticObj;
class GameBoard;
class Bonus;

class FactoryBonus
{
private:
	FactoryBonus() = default;
	FactoryBonus(const FactoryBonus&) = delete;
	std::vector<std::unique_ptr<StaticObj>> m_bonuses;
	std::vector < std::function<std::unique_ptr<Bonus>(const sf::Vector2f&, GameBoard&)>> m_createFuncs;

public:
	std::vector<std::unique_ptr<StaticObj>> createBonus(GameBoard&);
	static FactoryBonus& getFactoryBonus()
	{
		static FactoryBonus m_factoryBonus;
		return m_factoryBonus;
	}
	BonusType randTypeBonus();
	bool registerBonus(std::function<std::unique_ptr<Bonus>(const sf::Vector2f&, GameBoard&)> func, BonusType index);
};
