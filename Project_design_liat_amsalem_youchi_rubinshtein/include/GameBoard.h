#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include "Car.h"
#include "Road.h"
#include "StaticObj.h"
#include "Fence.h"
#include "PlayerCar.h"
#include "Calculates.h"
class Bonus;

class GameBoard
{
private:
	std::vector<std::unique_ptr<Car>> m_cars;
	std::vector<std::unique_ptr<StaticObj>>m_staticsObj ;
	std::vector<std::unique_ptr<Road>> m_road;
	std::vector<std::unique_ptr<StaticObj>>m_prevObstacles;
	sf::Sprite m_backgroundPic;
	int& m_LevelTime;
	int& m_credits;
	int& m_life;
	int m_numLevel;
	PlayerCar& m_playerCar;
	std::unique_ptr<Road> m_curRoad;
	Calculates m_calculates;

public:
	GameBoard(const int numLevel, int& m_LevelTime, int& credits, PlayerCar& myCar, int& life);
	void findRange(sf::Vector2f& startRange, sf::Vector2u& endRange, const int minusEdge);
	void drawBoard();
	void eraseIf();
	void moveObjects(float deltaTime);
	void createNewView(const sf::Vector2f& playerCarPos);
	void createObjsOnRoad();
	void checkFences();
	void insertBonuses();
	void deleteObj(StaticObj *objToDelete);
	void deleteCar(Car* carToDelete);
	void setTime(int timeToAdd);
	void setCredits(int creditToAdd);
	GameObject* checkColision(Car* car);
	bool isColideCars(Car* car);
	void createRandCar();
	void minusLife() { m_life--; }
};
