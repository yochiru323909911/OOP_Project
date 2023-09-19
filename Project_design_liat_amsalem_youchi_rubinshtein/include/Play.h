#pragma once
#include "Game.h"
#include "Command.h"

class Play :public Command
{
private:
	Game& m_game;

public:
	Play(Game& game);
	virtual void execute() override;
	virtual ~Play() = default;
};