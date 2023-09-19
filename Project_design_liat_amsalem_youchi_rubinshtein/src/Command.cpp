#include "Command.h"

//=================================================================================================
//���� �������� ����� �� ������
Command::Command(const int name, const sf::Vector2f pos)
	:m_pic(Design::getDesign().getPicture(name))
{
	m_pic.setPosition(pos);
	m_pic.setOrigin(450/2, 150/2);
}
//=================================================================================================
//������� �� ������ �� ���� �� ������
void Command::drawPic()
{
	 Design::getDesign().getWindow().draw(m_pic); 
	 scale(false);
}
//=================================================================================================
//������� �� ������ ��� �� ������ ������ ��� �� ������, ���� ��� ������ ���
bool Command::isIntersectPic(const sf::Vector2f& location)
{
	if (m_pic.getGlobalBounds().contains(location))
		return true;
	return false;
}
//=================================================================================================
//������� �� ������ �� ������ ��� �� ��� ����� ��� ������� ���� ������ ������ �� ��� ����� ���
void Command::scale(const bool toScale)
{
	if (toScale)
		m_pic.setScale(1.1, 1.1);
	else
		m_pic.setScale(1,1);
}