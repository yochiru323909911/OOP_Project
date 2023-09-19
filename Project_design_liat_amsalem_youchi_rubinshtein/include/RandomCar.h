#pragma once
#include "Car.h"

class GameBoard;

class RandomCar :public Car
{
private:
public:
	RandomCar(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard);
	void hitRandomCar();
	virtual ~RandomCar() = default;
};



