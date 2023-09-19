#pragma once
#include "Command.h"

class Help :public Command
{
private:
	sf::Sprite m_instruction;
	sf::Sprite m_exitInstruction;
public:
	Help();
	virtual void execute() override;
	virtual ~Help()=default;
};