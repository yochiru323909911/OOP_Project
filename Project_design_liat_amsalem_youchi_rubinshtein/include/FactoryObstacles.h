#pragma once
#include <iostream>
#include <vector>
#include "Road.h"
#include <memory>
#include <map>
#include "StaticObj.h"
#include "Consts.h"
#include <string>
#include "Design.h"

class Fence;
class River;

class FactoryObstacles
{
private:
	FactoryObstacles() = default;
	FactoryObstacles(const FactoryObstacles&) = delete;
	std::vector<std::unique_ptr<StaticObj>> m_fences;

public:
	std::vector<std::unique_ptr<StaticObj>> createObstacles(const sf::Vector2f& curRoadPos, const Direction_t& direct, const Direction_t& prevRoadDirect, const bool isRiver);
	static FactoryObstacles& getFactoryFence()
	{
		static FactoryObstacles m_factoryFence;
		return m_factoryFence;
	}
};

