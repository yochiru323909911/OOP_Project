#pragma once
#include "Consts.h"
#include <SFML/Audio.hpp>
#include "RandomCar.h"
#include "Calculates.h"
class GameBoard;
class Car;
//=========================================
class PlayerCar: public Car
{
private:
	int m_maxSpeed;
	sf::Sprite m_animationBoom;
	sf::Sound m_MoveFastsound;
	sf::Vector2f m_playerCarPos;
	bool m_drownInRiver;
	bool m_toKill;
	sf::Clock m_killRandCarTimer;
	int m_index;
	Calculates m_calculates;
public:
	PlayerCar(GameBoard& gameBoard);
	virtual void draw();
	void handleMoveFast(float deltaTime, Direction_t pressedDirc);
	void movePlayer(float deltaTime, Direction_t pressedDirc);
	void restartKillTimer() { m_killRandCarTimer.restart(); }
	void hitRandomCar(RandomCar& randCar);
	void drownInRiver();
	void playSound();
	bool getDrown();
	void hitSmartCar();
	void setDirection(Direction_t newDirc);
	int& setMaxSpeed() { return m_maxSpeed; }
	void setDrownInRiver(bool inRiver) { m_drownInRiver = inRiver; }
	void setKill(bool toKill) { m_toKill = toKill; }
	sf::Vector2f& setplayerCarPos() { return m_playerCarPos; }
	virtual ~PlayerCar() = default;
};

