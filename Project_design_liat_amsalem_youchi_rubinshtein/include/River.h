#pragma once
#include "StaticObj.h"
#include "FactoryObstacles.h"
#include "Consts.h"

class River :public StaticObj
{
private:
public:
	River(const sf::Vector2f& pos, StateObstacle_t state, Direction_t dir);
	River(const sf::Vector2f& pos, StateObstacle_t state, int sizeRect, const sf::Vector2f& origin, Direction_t dir);
	virtual ~River() = default;
};