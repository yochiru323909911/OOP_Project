//#include "FactorySmartCar.h"
//#include "SmartCar.h"
//#include "GameBoard.h"
//#include "Road.h"
////=================================================================================================
////פונקציה זו יוצרת מכונית חכמה במקרה והזמן שהוקצב לה הגיע
//std::unique_ptr<SmartCar> FactorySmartCar::createSmartCar(const Road& roadDir, GameBoard& gameBoard, PlayerCar& playerCar)
//{
//	static sf::Clock timer;
//	static bool timerOver = true;
//	if (timerOver)
//	{
//		timer.restart();
//		m_timeToCreateNewCar = ((MINUTE / 2) + rand() % MINUTE);
//		timerOver = false;
//	}
//	if (timer.getElapsedTime().asSeconds() >= m_timeToCreateNewCar)
//	{
//		timerOver = true;
//		return makeSmartCar(gameBoard, roadDir, playerCar);
//	}
//	return NULL;
//}
////=================================================================================================
////פונקציה זו יוצרת בפועל מכונית חכמה
//std::unique_ptr<SmartCar> FactorySmartCar::makeSmartCar(GameBoard& gameBoard, const Road& roadDir, PlayerCar& playerCar)
//{
//	sf::Vector2f startRange, pos;
//	sf::Vector2u sizeRange;
//	std::unique_ptr <SmartCar> newCar;
//	Direction_t dir;
//	for (int i = 0; gameBoard.isColideCars(newCar.get()); i += 10)
//	{
//		makeFirstPos(dir, pos, roadDir, i);
//		newCar = m_smartCarCreats[rand()% m_smartCarCreats.size()](dir, pos, gameBoard, playerCar);  //change!
//	}
//	return std::move(newCar);
//}
////=================================================================================================
////פונקציה זו מכניסה לוקטור של הפונקציות את הפונקציה שקיבלה שיוצרת מכונית חכמה
//bool FactorySmartCar::registerSmartCar(std::function< std::unique_ptr<SmartCar>(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard, PlayerCar& playerCar)> createFunc)
//{
//	m_smartCarCreats.emplace_back(createFunc);
//	return true;
//}
////=================================================================================================
////פונקציה זו מייצרת מיקום למכונית החכמה
//void FactorySmartCar::makeFirstPos(Direction_t& dir, sf::Vector2f& pos, Road roadDir, int i)
//{
//	switch (roadDir.getDirection())
//	{
//	case LEFT:
//	{
//		pos = { roadDir.getPos().x - WIDTH_ROAD - SPACE - i, roadDir.getPos().y };
//		dir = UP;
//		break;
//	}
//	case RIGHT:
//	{
//		pos = { roadDir.getPos().x + WIDTH_ROAD + SPACE + i, roadDir.getPos().y };
//		dir = UP;
//		break;
//	}
//	case UP:
//	{
//		pos = { roadDir.getPos().x, roadDir.getPos().y -HIGHT_ROAD+SPACE+i };
//		dir = LEFT;
//		break;
//	}
//	}
//}


#include "FactorySmartCar.h"
#include "SmartCar.h"
#include "GameBoard.h"
#include "Road.h"
//=================================================================================================
//פונקציה זו יוצרת מכונית חכמה במקרה והזמן שהוקצב לה הגיע
std::unique_ptr<SmartCar> FactorySmartCar::createSmartCar(const Road& roadDir, GameBoard& gameBoard, PlayerCar& playerCar)
{
	static sf::Clock timer;
	static bool timerOver = true;
	if (timerOver)
	{
		timer.restart();
		m_timeToCreateNewCar = ((MINUTE / 2) + rand() % MINUTE);
		timerOver = false;
	}
	if (timer.getElapsedTime().asSeconds() >= m_timeToCreateNewCar)
	{
		timerOver = true;
		return makeSmartCar(gameBoard, roadDir, playerCar);
	}
	return NULL;
}
//=================================================================================================
//פונקציה זו יוצרת בפועל מכונית חכמה
std::unique_ptr<SmartCar> FactorySmartCar::makeSmartCar(GameBoard& gameBoard, Road roadDir, PlayerCar& playerCar)
{
	Calculates calc;
	sf::Vector2f pos;
	std::unique_ptr <SmartCar> newCar;
	Direction_t dir;
	for (int i = 0; gameBoard.isColideCars(newCar.get()); i += 10)
	{
		pos = roadDir.getPos();
		dir = calc.matPos[roadDir.getDirection()](pos, i);
		newCar = m_smartCarCreats[rand() % m_smartCarCreats.size()](dir, pos, gameBoard, playerCar);  //change!
	}
	return std::move(newCar);
}
//=================================================================================================
//פונקציה זו מכניסה לוקטור של הפונקציות את הפונקציה שקיבלה שיוצרת מכונית חכמה
bool FactorySmartCar::registerSmartCar(std::function< std::unique_ptr<SmartCar>(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard, PlayerCar& playerCar)> createFunc)
{
	m_smartCarCreats.emplace_back(createFunc);
	return true;
}
