#include "GameBoard.h"
#include "Fence.h"
#include "Design.h"
#include "RandomCar.h"
#include "Consts.h"
#include "FactoryRoad.h"
#include "FactoryObstacles.h"
#include "Police.h"
#include "FactorySmartCar.h"
#include "River.h"
#include "FactoryBonus.h"

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת לוח המשחק
GameBoard::GameBoard(const int numLevel, int& LevelTime, int& credits, PlayerCar& myCar, int& life)
	:m_backgroundPic(Design::getDesign().getPicture(BACKGROUND_PLACE)), m_credits(credits), m_life(life),
	m_LevelTime(LevelTime), m_playerCar(myCar), m_numLevel(numLevel), m_calculates()
{
	m_road.emplace_back(std::make_unique<Road>(sf::Vector2f{ (WIND_SIZE_X/2),WIND_SIZE_Y+100 }, UP, ROAD_PLACE));
	m_prevObstacles = FactoryObstacles::getFactoryFence().createObstacles(m_road.back()->getPos(), m_road.back()->getDirection(), UP, false);
}
//=================================================================================================
//פונקציה זו מוצאת ומחזירה את התחום הכלוא בכביש האחרון ומורידה ממנו טווח מסוים של מסגרת שהתחום לא יהיה כלול בה
void GameBoard::findRange(sf::Vector2f& startRange, sf::Vector2u& sizeRange, const int minusEdge)
{
	sf::Vector2f pos = m_road.back()->getPos();
	switch (m_road.back()->getDirection())
	{
	case UP:
	{
		startRange = {pos.x-WIDTH_ROAD/2, pos.y - HIGHT_ROAD};
		sizeRange = { WIDTH_ROAD, HIGHT_ROAD };
		break;
	}
	case RIGHT:
	{
		startRange = { pos.x, pos.y - WIDTH_ROAD / 2 };
		sizeRange = { HIGHT_ROAD, WIDTH_ROAD };
		break;
	}
	case LEFT:
	{
		startRange = { pos.x - HIGHT_ROAD, pos.y - WIDTH_ROAD / 2 };
		sizeRange = { HIGHT_ROAD, WIDTH_ROAD };
		break;
	}
	}
	startRange.x += minusEdge;
	startRange.y += minusEdge;
	sizeRange.x -= (2*minusEdge);
	sizeRange.y -= (2*minusEdge);
}
//=================================================================================================
//פונקציה זו מציירת על החלון את לוח המשחק והאובייקטים שעליו
void GameBoard::drawBoard()
{
	auto centerView = Design::getDesign().getWindow().getView().getCenter();
	m_backgroundPic.setPosition({ centerView.x - SIZE_VIEW_X / 2, centerView.y - SIZE_VIEW_Y / 2 });
	Design::getDesign().getWindow().draw(m_backgroundPic);

	for (int i = 0; i < m_road.size(); i++)
		m_road[i]->draw();
	for (int i = 0; i < m_staticsObj.size(); i++)
		m_staticsObj[i]->draw();
	for (int i = 0; i < m_cars.size(); i++)
		m_cars[i]->draw();
}
//=================================================================================================
//פונקציה זו מוחקת מוקטור הסטטיים בונוסים רק אם הם כבר נלקחו
void GameBoard::eraseIf()
{
	std::erase_if(m_staticsObj, [](const auto& bonus) { return bonus->isTaken(); });
}
//=================================================================================================
//פונקציה זו מזיזה את האובייקטים התזוזתיים שעל הכביש שהם המכוניות
void GameBoard::moveObjects(float deltaTime)
{
	for (int car=0;car< m_cars.size();car++)
	{
		if (m_road.back()->getPic().getGlobalBounds().intersects(m_cars[car]->getPic().getGlobalBounds()))
			m_cars[car]->changeCar();
		m_cars[car]->move(deltaTime);
	}
}
//=================================================================================================
//פונקציה זו יוצרת מכוניות רנדומליות
void GameBoard::createRandCar()
{
	sf::Vector2f startRange, pos;
	sf::Vector2u sizeRange;
	Direction_t dir = m_road.back()->getDirection();
	std::unique_ptr <RandomCar> newCar;
	findRange(startRange, sizeRange, (CAR_LENGTH / 2));
	auto amountCars = 1 + rand() % 2;
	for (int indCar = 0; indCar < amountCars; )
	{
		pos = sf::Vector2f(startRange.x + rand() % sizeRange.x, startRange.y + rand() % sizeRange.y);
		newCar = std::make_unique<RandomCar>(dir, pos, *this);
		int index;
		for (index = 0; index < m_cars.size(); index++)
			if (m_cars[index]->getPic().getGlobalBounds().intersects(newCar->getPic().getGlobalBounds()))
				break;

		if (index == m_cars.size()) {
			m_cars.emplace_back(std::move(newCar));
			indCar++;
		}
	}
}
//=================================================================================================
//פונקציה זו בודקת האם יש ליצור אובייקטים חדשים ואם כן אז היא שולחת לפונקציה שעושה זאת
void GameBoard::createNewView(const sf::Vector2f&)
{
	bool flag = false;
	if (m_road.back()->getDirection() == UP)
		if ((m_road.back()->getPos().y) >= Design::getDesign().getWindow().getView().getCenter().y - (SIZE_VIEW_Y / 2))
			flag = true;
	if (m_road.back()->getDirection() == RIGHT)
		if ((m_road.back()->getPos().x) <= Design::getDesign().getWindow().getView().getCenter().x + (SIZE_VIEW_X / 2))
			flag = true;
	if (m_road.back()->getDirection() == LEFT)
		if ((m_road.back()->getPos().x) >= Design::getDesign().getWindow().getView().getCenter().x - (SIZE_VIEW_X / 2))
			flag = true;
	if (flag)
		createObjsOnRoad();
}
//=================================================================================================
//פונקציה זו יוצרת אובייקטים חדשים על לוח המשחק
void GameBoard::createObjsOnRoad()
{
	bool isRiver= false;
	std::unique_ptr<SmartCar> newCar;
	if (m_numLevel >= SIZE)
	{
		if (rand() % SIZE == 1)
			isRiver = true;
	}
	m_curRoad = std::move(FactoryRoad::getFactoryRoad().createRoad(*m_road.back().get(), isRiver));
	checkFences();
	insertBonuses();
	if(m_road.size()>=2)
	newCar = FactorySmartCar::getFactorySmartCar().createSmartCar(*m_road[m_road.size()-2].get(), *this, m_playerCar);
	if (newCar)
		m_cars.emplace_back(std::move(newCar));
	m_road.emplace_back(std::move(m_curRoad));
	m_prevObstacles = FactoryObstacles::getFactoryFence().createObstacles(m_road.back()->getPos(), m_road.back()->getDirection(), m_road[m_road.size() - 2]->getDirection(), isRiver);
	createRandCar();
}
//=================================================================================================
//פונקציה זו בודקת אם המכשולים שמסביב לכביש מוכלים בכביש הבא. אם כן היא יוצרת אחרים קטנים יותר במקומם
void GameBoard::checkFences()
{
	for (int i = 0; i < m_prevObstacles.size(); i++)
	{
		if (!m_curRoad->getPic().getGlobalBounds().intersects(m_prevObstacles[i]->getPic().getGlobalBounds()))
			m_staticsObj.emplace_back(std::move(m_prevObstacles[i]));
		else
		{
			auto fence = m_calculates.RoadsDirections[m_curRoad->getDirection()][m_road.back()->getDirection()](m_prevObstacles[i]->getPos());
			if (fence)
				m_staticsObj.emplace_back(std::move(fence));
		}
	}
}
//=================================================================================================
//פונקציה זו מכניסה את הבונוסים שנוצרו לתוך הוקטור של האובייקטים הסטטיים במשחק
void GameBoard::insertBonuses()
{
	auto m_bonuses = FactoryBonus::getFactoryBonus().createBonus(*this);
	for(auto & bonus:m_bonuses)
		m_staticsObj.emplace_back(std::move(bonus));
}
//=================================================================================================
//פונקציה זו מוחקת את האובייקט הסטטי שהיא קיבלה מתוך הוקטור שהוא קיים בו
void GameBoard::deleteObj(StaticObj *objToDelete)
{
	for (int i = 0; i < m_staticsObj.size(); i++)
	{
		if (m_staticsObj[i].get() == objToDelete)
			m_staticsObj.erase(m_staticsObj.begin()+i);
	}
}
//=================================================================================================
//פונקציה זו מוחקת את המכונית שהיא קיבלה מתוך הוקטור שהיא קיימת בו
void GameBoard::deleteCar(Car* carToDelete)
{
	for (int i = 0; i < m_cars.size(); i++)
	{
		if (m_cars[i].get() == carToDelete)
			m_cars.erase(m_cars.begin() + i);
	}
}
//=================================================================================================
//פונקציה זו מוסיפה מעט זמן לפרק זמן שנבחר 
void GameBoard::setTime(int timeToAdd)
{
	m_LevelTime += timeToAdd;
}
//=================================================================================================
//פונקציה זו מוסיפה נקודות למספר הנקודות הקיימות
void GameBoard::setCredits(int creditToAdd)
{
	m_credits += creditToAdd;
}
//=================================================================================================
//פונקציה זו בודקת התנגשות של המכונית שהיא קיבלה עם כל האובייקטים שעל הלוח
GameObject* GameBoard::checkColision(Car* car)
{
	if (car!= &m_playerCar && car->getPic().getGlobalBounds().intersects(m_playerCar.getPic().getGlobalBounds()))
		return &m_playerCar;
	for (auto &iCar:m_cars)
		if(iCar.get()!=car &&car->getPic().getGlobalBounds().intersects(iCar->getPic().getGlobalBounds()))
			return iCar.get();
	for (auto& iStatic : m_staticsObj)
		if (car->getPic().getGlobalBounds().intersects(iStatic->getPic().getGlobalBounds()))
			return iStatic.get();
	return nullptr;
}
//=================================================================================================
//פונקציה זו בודקת התנגשות של המכונית עם המכוניות האחרות
bool GameBoard::isColideCars(Car* car)
{
	if (car == nullptr)
		return true;
	for (int i = 0; i < m_cars.size(); i++)
		if (car != m_cars[i].get() && m_cars[i]->getPic().getGlobalBounds().intersects(car->getPic().getGlobalBounds()))
			return true;
	return false;
}