#pragma once
#include "Game.h"
#include "MainMenu.h"

class Controller
{
private:
	MainMenu m_mainMenu;
public:
	Controller() = default;
	void run();
};