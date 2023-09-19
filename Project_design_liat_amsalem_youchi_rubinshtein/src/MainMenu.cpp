#include "MainMenu.h"
#include "Level.h"
#include "Design.h"
#include "Command.h"
#include <iostream>
const int NOT = -1;

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת התפריט
MainMenu::MainMenu()
	:m_backgroundPic(Design::getDesign().getPicture(OPENSCREEN_PLACE))
{}
//=================================================================================================
//פונקציה זו מדפיסה את אפשרויות התפריט-הכפתורים
void MainMenu::show()
{
	Design::getDesign().getWindow().clear();
	Design::getDesign().getWindow().draw(m_backgroundPic);
	for (int indexOp = 0; indexOp < m_options.size(); indexOp++)
		m_options[indexOp]->drawPic();
	Design::getDesign().getWindow().display();
}
//=================================================================================================
//פונקציה זו מנהלת את האירועים השונים שקורים
void MainMenu::activate()
{
	while (Design::getDesign().getWindow().isOpen())
	{
		show();
		int  OneOption = NOT;
		if (auto event = sf::Event{}; Design::getDesign().getWindow().waitEvent(event))
		{
			auto location = Design::getDesign().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			switch (event.type)
			{
			case sf::Event::Closed: Design::getDesign().getWindow().close(); break;
			case sf::Event::MouseMoved: scaleOption(event); break;
			case sf::Event::MouseButtonReleased: OneOption = findButtonPressed(Design::getDesign().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })); break;
			}
		}
		if (OneOption != NOT)
			m_options[OneOption]->execute();
	}
}
//=================================================================================================
//פונקציה זו מדגישה כפתור ע"י הגדלתו אם העכבר מרחף עליו
void MainMenu::scaleOption(const sf::Event& eventType)
{
	int indPressed = findButtonPressed(Design::getDesign().getWindow().mapPixelToCoords({ eventType.mouseMove.x, eventType.mouseMove.y }));
	if (indPressed != NOT)
		m_options[indPressed]->scale(true);
}
//=================================================================================================
//פונקציה זו מוסיפה כפתור חדש לוקטור הכפתורים
void MainMenu::add(std::unique_ptr<Command> newButton)
{
	m_options.emplace_back(std::move(newButton));
}
//=================================================================================================
//פונקציה זו מוצאת על איזה כפתור לחץ המשתמש
int MainMenu::findButtonPressed(const sf::Vector2f& location)
{
	for (int indexOp = 0; indexOp < m_options.size(); indexOp++)
	{
		if (m_options[indexOp]->isIntersectPic(location))
			return indexOp;
	}
	return NOT;
}
