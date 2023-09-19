#pragma once
#include "Car.h"
#include "GameBoard.h"

class SmartCar :public Car
{
private:
	sf::Clock m_timerLife;
	int m_lifeTime;
	PlayerCar& m_playerCar;
public:
	SmartCar(const int typeCar, const int speedCar, const Direction_t& direct, const sf::Vector2f& pos,
		     GameBoard& gameBoard, const int sound_place, PlayerCar& playerCar);
	virtual void move(float);
	virtual ~SmartCar() = default;
};



