#include "GameObject.h"
#include "Design.h"

//=================================================================================================
//���� �������� ����� �� ������
GameObject::GameObject(const int typePic, const sf::Vector2f& pos, const sf::Vector2f& origin)
	: m_picture(Design::getDesign().getPicture(typePic))
{
	m_picture.setOrigin(origin);
	m_picture.setPosition(pos);
}

//=================================================================================================
//������� �� ������ �� ������ �� �������� �� �����
const sf::Vector2f& GameObject::getPos()const
{
	return m_picture.getPosition();
}
//=================================================================================================
//������� �� ������ �� �������� �� �����
void GameObject::draw()
{
	Design::getDesign().getWindow().draw(m_picture);
}
//=================================================================================================
//������� �� ���� �� ����� �������� ������ ������ ����
void GameObject::setPosPic(const sf::Vector2f& newPos)
{
	m_picture.setPosition(newPos);
}
