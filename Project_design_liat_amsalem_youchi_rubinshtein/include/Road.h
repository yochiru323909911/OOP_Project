#pragma once
#include "StaticObj.h"

class Road :public StaticObj
{
private:
	static bool m_registerit;
	Direction_t m_direct;
public:
	Road(const sf::Vector2f& pos, Direction_t dirc, const int pic);
	Direction_t getDirection() { return m_direct; }
	const sf::Vector2f& getPos() { return m_picture.getPosition(); }
	void setPos(const sf::Vector2f& newPos) { m_picture.setPosition(newPos); } 
};