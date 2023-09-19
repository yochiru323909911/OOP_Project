#pragma once
#include <vector>
#include "StaticObj.h"
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

class Road;
class PlayerCar;
struct Calculates
{
	Calculates();
	std::vector<std::vector<std::function<std::unique_ptr<StaticObj>(const sf::Vector2f& pos)>>>RoadsDirections;
	std::vector<std::vector<std::function<sf::Vector2f (Road& prevRoad)>>>NewRoadPosition;
	std::vector<std::vector<std::function<void(PlayerCar&)>>> PressDirection;
	std::vector<std::function<Direction_t(sf::Vector2f&, const int)>> matPos;

};

