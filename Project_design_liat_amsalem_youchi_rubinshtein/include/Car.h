#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.h"

class GameBoard;

class Car:public GameObject
{
protected:
	float m_speed;
	Direction_t m_direction;
	GameBoard& m_gameBoard;
	sf::Sound m_sound;
public:
	Car(const int type, const int speed, const Direction_t&, const sf::Vector2f& pos, GameBoard& gameBoard, const int sound_place);
	const sf::Vector2f& getMoveByDirc();
	//void hitRoadSides();
	void hitByCar();
	Direction_t changeDirection();
	virtual void move(float deltaTime);
	float& setSpeed() { return m_speed; }
	void changeCar();
	Direction_t getDirection() { return m_direction; }
	virtual ~Car() = 0 {}
};