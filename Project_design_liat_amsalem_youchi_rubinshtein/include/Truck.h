#pragma once
#include "SmartCar.h"
#include <SFML/Graphics.hpp>
#include "FactorySmartCar.h"
#include <memory>

class GameBoard;

class Truck :public SmartCar
{
private:
	static bool m_registerit;
public:
	Truck(const Direction_t& dir, sf::Vector2f pos, GameBoard& gameBoard, PlayerCar& playerCar)
		:SmartCar(TRUCK_PLACE, TRUCK_SPEED, dir, pos, gameBoard, TRUCK_SOUND_PLACE, playerCar) {}  //UPDATE speed and pos
	virtual ~Truck() = default;
};