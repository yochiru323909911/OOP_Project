#include "Help.h"

//=================================================================================================
//זוהי פונקציית הבניה של המחלקה
Help::Help() 
	: Command(HELP_PLACE, { 460,510 }), m_instruction(Design::getDesign().getPicture(INSTUCTIONS_PLACE)),
	m_exitInstruction(Design::getDesign().getPicture(EXIT_INSTRUCTIONS_PLACE))
{
	m_instruction.setPosition(150, 100);
	m_exitInstruction.setOrigin(sf::Vector2f(m_exitInstruction.getTexture()->getSize() / 2u));
	m_exitInstruction.setPosition(m_instruction.getPosition().x+m_instruction.getGlobalBounds().width, m_instruction.getPosition().y);
}
//=================================================================================================
//פונקציה זו מטפלת בבחירת המשתמש בקריאת הוראות המשחק
void Help::execute()
{
	auto event = sf::Event{};
	while (Design::getDesign().getWindow().isOpen())
	{
		Design::getDesign().getWindow().draw(m_instruction);
		Design::getDesign().getWindow().draw(m_exitInstruction);
		Design::getDesign().getWindow().display();
		if (Design::getDesign().getWindow().waitEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				Design::getDesign().getWindow().close();
				exit(EXIT_SUCCESS);
			}
			auto location = Design::getDesign().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			if (m_exitInstruction.getGlobalBounds().contains(location))
				break;
		}
	}
}