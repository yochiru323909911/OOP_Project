#pragma once
#include <memory>
#include <vector>
#include <functional>
#include "Consts.h"
#include <SFML/Graphics.hpp>
#include "PlayerCar.h"

class GameBoard;
class SmartCar;
class Road;

class FactorySmartCar
{
private:
	std::vector<std::function<std::unique_ptr<SmartCar>(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard, PlayerCar& playerCar)>>m_smartCarCreats;
	FactorySmartCar() = default;
	FactorySmartCar(const FactorySmartCar&) = delete;
	int m_timeToCreateNewCar;
public:
	std::unique_ptr<SmartCar> createSmartCar(const Road& roadDir, GameBoard& gameBoard, PlayerCar& playerCar);
	std::unique_ptr<SmartCar> makeSmartCar(GameBoard& gameBoard, Road roadDir, PlayerCar& playerCar);
	bool registerSmartCar(std::function< std::unique_ptr<SmartCar>(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard, PlayerCar& playerCar)>);
//	void makeFirstPos(Direction_t& dir, sf::Vector2f& pos, Road roadDir, int i);
	static FactorySmartCar& getFactorySmartCar()
	{
		static FactorySmartCar m_factorySmartCar;
		return m_factorySmartCar;
	}
	//std::vector<std::unique_ptr<SmartCar>> getVec();
};