#pragma once
#include "SmartCar.h"
#include <SFML/Graphics.hpp>
#include "FactorySmartCar.h"
#include <memory>
class GameBoard;

class Police :public SmartCar
{
private:
	static bool m_registerit;
public:
	Police(const Direction_t& dir, sf::Vector2f pos, GameBoard& gameBoard, PlayerCar& playerCar)
		:SmartCar(POLICE_PLACE, POLICE_SPEED, dir, pos, gameBoard, POLICE_SOUND_PLACE, playerCar) {}  //UPDATE speed and pos
	//
	virtual ~Police() = default;
};
