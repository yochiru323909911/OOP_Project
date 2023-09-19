#include "Command.h"

//=================================================================================================
//זוהי פונקציית הבנאי של המחלקה
Command::Command(const int name, const sf::Vector2f pos)
	:m_pic(Design::getDesign().getPicture(name))
{
	m_pic.setPosition(pos);
	m_pic.setOrigin(450/2, 150/2);
}
//=================================================================================================
//פונקציה זו מדפיסה על המסך את התמונה
void Command::drawPic()
{
	 Design::getDesign().getWindow().draw(m_pic); 
	 scale(false);
}
//=================================================================================================
//פונקציה זו מחזירה אמת אם המיקום שקיבלה הוא על התמונה, אחרת היא מחזירה שקר
bool Command::isIntersectPic(const sf::Vector2f& location)
{
	if (m_pic.getGlobalBounds().contains(location))
		return true;
	return false;
}
//=================================================================================================
//פונקציה זו מגדילה את התמונה מעט אם היא מקבלת אמת ומחזירה אותה לגודלה המקורי אם היא מקבלת שקר
void Command::scale(const bool toScale)
{
	if (toScale)
		m_pic.setScale(1.1, 1.1);
	else
		m_pic.setScale(1,1);
}