#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Fence.h"
#include "Consts.h"
#include "Calculates.h"
class Road;

class FactoryRoad
{
private:
	std::vector< std::unique_ptr<Road>> m_roadsVec;//
	FactoryRoad() = default;
	FactoryRoad(const FactoryRoad&) = delete;
	Calculates m_calculates;
public:
	std::unique_ptr<Road> createRoad(Road&, bool& isRiver);
	Direction_t checkCorrectDir(Direction_t prevDir);
	static FactoryRoad& getFactoryRoad()
	{
		static FactoryRoad m_factoryRoad;
		return m_factoryRoad;
	}
};
