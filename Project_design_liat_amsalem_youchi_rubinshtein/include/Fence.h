#pragma once
#include "StaticObj.h"
#include "FactoryObstacles.h"
#include "Consts.h"

class Fence :public StaticObj
{
private:
	
public:
	Fence(const sf::Vector2f& pos, StateObstacle_t state);
	Fence(const sf::Vector2f& pos, StateObstacle_t state, int sizeRect, const sf::Vector2f& origin);
	virtual ~Fence() = default;
};
