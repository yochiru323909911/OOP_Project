#pragma once
#include "Level.h"
#include <SFML/Audio.hpp>


class Game
{
private:
	sf::Sprite m_messagePic;
	sf::Sound m_sound;
public:
	void run();
	void showMessage(const int typeMsg, const int typeSound);
};