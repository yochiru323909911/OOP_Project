#include "Road.h"
#include "FactoryRoad.h"
#include "StaticObj.h"

//=================================================================================================
//זוהי פונקציית הבניה של כביש
Road::Road(const sf::Vector2f& pos, Direction_t dirc, const int pic)
	:m_direct(dirc), StaticObj(pic, pos, { WIDTH_ROAD/2, HIGHT_ROAD })  
{
	if (m_direct == RIGHT)
		m_picture.rotate(90);
	else if (m_direct == LEFT)
		m_picture.rotate(270);

}