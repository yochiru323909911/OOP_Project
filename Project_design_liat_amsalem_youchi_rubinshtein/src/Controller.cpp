//=================================================================================
#include "Controller.h"
#include "MainMenu.h"
#include "Design.h"
#include "Game.h"
#include "Help.h"
#include <memory>
#include "Play.h"
#include "Exit.h"
//=================================================================================
//פונקציה זו היא הפונקציה שרצה על כל המשחק
void Controller::run()
{
    auto game = Game();
    m_mainMenu.add(std::make_unique<Play>(game));
    m_mainMenu.add(std::make_unique<Help>());
    m_mainMenu.add(std::make_unique<Exit>());
    m_mainMenu.activate();
}
//=================================================================================