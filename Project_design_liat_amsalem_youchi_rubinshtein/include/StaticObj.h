#pragma once
#include "GameObject.h"
#include <memory>

class StaticObj :public GameObject
{
protected:
public:
	StaticObj(const int typePic, const sf::Vector2f& pos, const sf::Vector2f& origin = { 0,0 }) 
		:GameObject(typePic, pos, origin)  {}
	virtual bool isTaken()const { return false; }
	virtual ~StaticObj() = default;
};