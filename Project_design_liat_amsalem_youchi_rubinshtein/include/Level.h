#pragma once
#include "GameBoard.h"
#include <SFML/Graphics.hpp>
#include "PlayerCar.h"
#include "Car.h"
#include <memory>
#include <SFML/Audio.hpp>
#include "InformationDisplay.h"

class Level
{
private:
	sf::Sound m_bgSound;
	std::unique_ptr<PlayerCar> m_myCar;  //?
	GameBoard m_gameBoard;
	int m_credits;
	int m_LevelTime;
	int m_creditsGoal;
	InformationDisplay m_infoDisplay;
	void playerCarDrowing();
	void handlePress(bool arrowIsPressed, float deltaTime, Direction_t direction);
	Direction_t checkArrowPressed(bool& arrowIsPressed);
	void moveTheView();
	int m_life;

public:
	Level(const int numLevel);
	bool run();
	bool levelOver();
};