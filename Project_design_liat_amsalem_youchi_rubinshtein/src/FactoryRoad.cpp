#include "FactoryRoad.h"
#include "Road.h"
//=================================================================================================
//פונקציה זו יוצרת כביש חדש
std::unique_ptr<Road> FactoryRoad::createRoad(Road& prevRoad, bool& isRiver)
{
	sf::Vector2f pos;
	Direction_t dir;
	dir = checkCorrectDir(prevRoad.getDirection());
	pos = m_calculates.NewRoadPosition[prevRoad.getDirection()][dir](prevRoad);
	if (isRiver == true && dir == UP)
		return std::make_unique<Road>(pos, dir, BRIDGE_PLACE);
	isRiver = false;
	return std::make_unique<Road>(pos, dir, ROAD_PLACE);
}
//=================================================================================================
//פונקציה זו בודקת האם הכיוון של הכביש תקין
Direction_t FactoryRoad::checkCorrectDir(Direction_t prevDir)
{
	Direction_t myDir = Direction_t(rand() % 3);
	if (myDir == LEFT && prevDir == RIGHT)
		return UP;
	if(myDir == RIGHT&& prevDir ==LEFT)
		return UP;
	return myDir;
}



