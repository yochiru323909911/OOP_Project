#include "Level.h"
#include "RandomCar.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Police.h"
#include "Design.h"
//=================================================================================================
//
Level::Level(const int numLevel)
	:m_credits(0), m_creditsGoal((numLevel + 5) * 10), m_life(3), m_gameBoard(numLevel, m_LevelTime, m_credits, *m_myCar.get(), m_life),
	 m_myCar(std::make_unique<PlayerCar>(m_gameBoard)), m_infoDisplay(numLevel, m_LevelTime, m_credits, m_creditsGoal, m_life),
	m_bgSound(Design::getDesign().getSound(LEVEL_SOUND_PLACE))
{	
	m_LevelTime = (numLevel* MINUTE) + rand() % MINUTE;
}
//=================================================================================================
//פונקציה זו מריצה את הלולאה הראשית של השלב
bool Level::run()
{
	m_bgSound.setVolume(30);
    m_bgSound.play();
	m_bgSound.setLoop(true);
	sf::Clock timer;
	Direction_t direction=UP;
	Design::getDesign().getWindow().setView({ m_myCar->getPos(), sf::Vector2f{ SIZE_VIEW_X, SIZE_VIEW_Y } });
	while (Design::getDesign().getWindow().isOpen() && !m_infoDisplay.isTimeOver()&&!m_myCar->getDrown()&&(m_life>=0))
	{
		auto event = sf::Event{};
		bool arrowIsPressed=false;
		Design::getDesign().getWindow().clear();
		m_gameBoard.createNewView(m_myCar->getPos());   
		m_gameBoard.drawBoard();
		m_myCar->draw();
		m_infoDisplay.show();
		Design::getDesign().getWindow().display();
		while (Design::getDesign().getWindow().pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				Design::getDesign().getWindow().close();
				exit(EXIT_SUCCESS);
			}
			if ((event.type == sf::Event::KeyPressed))
			    direction = checkArrowPressed(arrowIsPressed);
		}
		float deltaTime = timer.restart().asSeconds();
		m_gameBoard.moveObjects(deltaTime);
		handlePress(arrowIsPressed, deltaTime, direction);
		m_gameBoard.eraseIf();
		timer.restart();
	}
	playerCarDrowing();
	if (m_credits >= m_creditsGoal)
		return true;
	return false;
}

//=================================================================================================
//פונקציה זו מדפיסה את סוף השלב כשמכונית השחקן טובעת באגם
void Level::playerCarDrowing()
{
	while (m_myCar->getDrown())
	{
		Design::getDesign().getWindow().clear();
		m_gameBoard.drawBoard();
		m_myCar->drownInRiver();
		m_infoDisplay.show();
		Design::getDesign().getWindow().display();
	}
}
//=================================================================================================
//פונקציה זו מזיזה את השחקן בהתאם ללחיצות המשתמש
void Level::handlePress(bool arrowIsPressed, float deltaTime, Direction_t direction)
{
	if (arrowIsPressed)
	{
		m_myCar->movePlayer(deltaTime, direction);
		moveTheView();
	}
}
//=================================================================================================
//פונקציה זו משנה את המשתנה שהיא מקבלת לטרו אם נלחץ מקש חץ ומעדכנת את סוג המקש שנלחץ
Direction_t Level::checkArrowPressed(bool& arrowIsPressed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		arrowIsPressed = true;
		return UPLEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		arrowIsPressed = true;
		return UPRIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		arrowIsPressed = true;
		return DOWNLEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		arrowIsPressed = true;
		return DOWNRIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		arrowIsPressed = true;
		return UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		arrowIsPressed = true;
		return DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		arrowIsPressed = true;
		return RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		arrowIsPressed = true;
		return LEFT;
	}
}
//=================================================================================================
//פונקציה זו מזיזה את קטע החלון שרואים בהתאם למיקום של השחקן
void Level::moveTheView()
{
	if (m_myCar->getPos().y < WIND_SIZE_Y - HIGHT_ROAD / 2)
		Design::getDesign().getWindow().setView({ m_myCar->getPos(), sf::Vector2f{ SIZE_VIEW_X, SIZE_VIEW_Y } });
}

