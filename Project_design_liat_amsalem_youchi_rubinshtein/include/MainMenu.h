#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Help.h"
#include <iostream>
#include <memory>
#include "Command.h"

class MainMenu {
public:
	MainMenu();
	void add(std::unique_ptr<Command> c);
	int findButtonPressed(const sf::Vector2f& event);
	void activate();
	void scaleOption(const sf::Event& eventType);

private:
	sf::Sprite m_backgroundPic;
	std::vector<std::unique_ptr<Command>> m_options;
	void show();
};