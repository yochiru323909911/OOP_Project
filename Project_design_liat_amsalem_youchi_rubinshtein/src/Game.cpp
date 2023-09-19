#include "Game.h"
//=================================================================================================
//פונקציה זו מריצה את לולאת המשחק. הפונקציה רצה על כל השלבים
void Game::run()
{
	for(int i_level =3; i_level <= MAX_LEVELS;)
	{
		auto level=Level(i_level);
		if (level.run())
		{
			showMessage(WIN_PIC_PLACE, WIN_SOUND_PLACE);
			i_level++;
		}
		else
			showMessage(FAILED_PIC_PLACE, FAIL_SOUND_PLACE);
	}
}
//=================================================================================================
//פונקציה זו מדפיסה הודעה למסך לאחר ניצחון או כישלון
void Game::showMessage(const int typeMsg, const int typeSound)
{
	m_messagePic.setTexture(Design::getDesign().getPicture(typeMsg));
	m_messagePic.setOrigin(m_messagePic.getTexture()->getSize().x/2, m_messagePic.getTexture()->getSize().y / 2);
	m_messagePic.setPosition(Design::getDesign().getWindow().getView().getCenter());
	Design::getDesign().getWindow().draw(m_messagePic);
	m_sound.setBuffer(Design::getDesign().getSound(typeSound));
	m_sound.play();
	Design::getDesign().getWindow().display();
	sf::sleep(sf::seconds(3));
}