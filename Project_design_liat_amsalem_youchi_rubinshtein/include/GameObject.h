#pragma once
#include <SFML/Graphics.hpp>
#include "Consts.h"
#include <memory>

class GameObject
{
protected:
	sf::Sprite m_picture;
public:
	GameObject(const int typePic, const sf::Vector2f& pos, const sf::Vector2f& origin = { 0,0 });
	virtual void draw();
	virtual ~GameObject() = 0{}
	void setPosPic(const sf::Vector2f& newPos);
	const sf::Vector2f& getPos()const;
	 sf::Sprite& getPic() { return m_picture; }
};