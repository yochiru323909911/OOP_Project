#pragma once
#include "Design.h"
#include <string>
#include <SFML/Graphics.hpp>

class FileExceptions
{
private:
	sf::Text m_error;

public:
	FileExceptions(const std::string& error);
	void handleException();

};