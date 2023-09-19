#include "Fence.h"
#include <SFML/Graphics.hpp>
//=================================================================================================
//������� �� ��� �������� ����� �� ���
Fence::Fence(const sf::Vector2f& pos, StateObstacle_t state)
	:StaticObj(FENCE_PLACE, pos, { (OBSTACLE_WIDTH / 2), OBSTACLE_HIGHT })
{
	if (state == HORIZONTAL)
		m_picture.rotate(270);
}
//=================================================================================================
//������� �� ��� �������� ���� �� ��� ������ ������� ������ ��� ����� �� ������ ����� ������
Fence::Fence(const sf::Vector2f& pos, StateObstacle_t state, int sizeRect, const sf::Vector2f& origin)
	:StaticObj(FENCE_PLACE, pos, origin)
{
	m_picture.setTextureRect(sf::IntRect(0, 0, OBSTACLE_WIDTH, sizeRect));
	if (state == HORIZONTAL)
		m_picture.rotate(270);
}