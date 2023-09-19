#include "Bonus.h"
#include "Design.h"
#include <string>

//=================================================================================================
//פונקציה זו היא הבנאי של מחלקת בונוס
Bonus::Bonus(const int picture_place, const sf::Vector2f pos, GameBoard& gameBoard)
	: StaticObj(picture_place, pos), m_gameBoard(gameBoard), m_taken(false)
{
	m_sound.setBuffer(Design::getDesign().getSound(BONUS_SOUND_PLACE));
}
//=================================================================================================
//פונקציה זו מציירת את הבונוס על החלון
void Bonus::draw()
{
	m_picture.setOrigin(sf::Vector2f(m_picture.getTexture()->getSize() / 2u));
	m_picture.rotate(0.5);
	Design::getDesign().getWindow().draw(m_picture);
}
//=================================================================================================
//פונקציה זו מממשת התנהגות של התנגשות עם בונוס
void Bonus::hit()
{
	m_sound.play();
	m_taken = true;
}