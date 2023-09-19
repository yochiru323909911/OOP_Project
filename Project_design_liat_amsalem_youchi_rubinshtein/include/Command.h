#pragma once
#include <SFML/Graphics.hpp>
#include "Design.h"

class Command
{
protected:
	sf::Sprite m_pic;
public:
	Command(const int name, const sf::Vector2f pos);
	void drawPic(); 
	void scale(const bool toScale);
	bool isIntersectPic(const sf::Vector2f& location);
	virtual void execute() = 0 {}
	virtual ~Command() = default;
};