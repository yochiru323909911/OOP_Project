#pragma once
#include "Command.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Exit:public Command
{

public:
	Exit() : Command(EXIT_PLACE, {460,710}) {}
	virtual void execute() override
	{
		exit(EXIT_SUCCESS);
	}
	virtual ~Exit()=default;
};