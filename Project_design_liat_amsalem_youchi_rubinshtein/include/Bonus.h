#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObj.h"
#include <SFML/Audio.hpp>
#include <string>
#include "GameBoard.h"

class Bonus:public StaticObj
{
protected:
	sf::Sound m_sound;
	GameBoard& m_gameBoard;
	bool m_taken;
public:
	Bonus(const int picture_place, const sf::Vector2f pos, GameBoard& gameBoard);
	void hit();
	virtual void draw() override;
	virtual bool isTaken()const override { return m_taken && m_sound.getStatus() == sf::SoundSource::Stopped; }
	virtual ~Bonus() = 0 {}
};