#include "River.h"

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת נהר
River::River(const sf::Vector2f& pos, StateObstacle_t state, Direction_t dir)
	:StaticObj(RIVER_PLACE, pos, { (RIVER_WIDTH / 2), RIVER_HIGHT })
{
	if(dir==LEFT)
	m_picture.setTextureRect({ 0, 0, RIVER_WIDTH , RIVER_HIGHT});
	else
		m_picture.setTextureRect({ RIVER_WIDTH, 0, RIVER_WIDTH , RIVER_HIGHT });
	if (state == HORIZONTAL)
		m_picture.rotate(270);

	m_picture.scale(1, 0.85);
}
//=================================================================================================
//פונקציה זו היא פונקציית בניה של נהר שמקבלת פרמטרים נוספים כדי לחתוך את התמונה לגודל המתאים
River::River(const sf::Vector2f& pos, StateObstacle_t state, int sizeRect, const sf::Vector2f& origin, Direction_t dir)
	:StaticObj(RIVER_PLACE, pos, origin)
{
	if (dir == LEFT)
		m_picture.setTextureRect({ 0, 0, RIVER_WIDTH , sizeRect });
	else
		m_picture.setTextureRect(sf::IntRect(RIVER_WIDTH, 0, RIVER_WIDTH, sizeRect));
		//m_picture.setTextureRect({ RIVER_WIDTH, 0, RIVER_WIDTH , RIVER_HIGHT });
	
	if (state == HORIZONTAL)
		m_picture.rotate(270);
	m_picture.scale(1, 0.85);
}