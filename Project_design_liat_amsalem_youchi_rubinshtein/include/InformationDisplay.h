#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

class InformationDisplay
{
private:
	std::vector<sf::Sprite> m_icons;
	std::vector < sf::Text> m_texts;
	sf::Clock m_clock;
	sf::Sound m_timerSound;
	int& m_levelTime;
	int& m_credits;
	int& m_life;
	std::string m_creditsGoal;

public:
	InformationDisplay(int numlevel, int& levelTime, int& credits, const int creditsGoal, int& life);
	void show();
	void convertClockToTime(const int time_in_seconds);
	bool isTimeOver();
};