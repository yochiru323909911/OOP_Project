#pragma once
#include "SmartCar.h"
#include <SFML/Graphics.hpp>
#include "FactorySmartCar.h"
#include <memory>

class Motorcycle :public SmartCar
{
private:
	static bool m_registerit;
public:
	Motorcycle(const Direction_t& dir, sf::Vector2f pos, GameBoard& gameBoard, PlayerCar& playerCar)
		:SmartCar(MOTORCYCLE_PLACE, MOTORFYCLE_SPEED, dir, pos, gameBoard, MOTORCYCLE_SOUND_PLACE, playerCar) {}  //UPDATE speed and pos

	virtual ~Motorcycle() = default;
	//
};