#include "GameObject.h"
#include "Design.h"

//=================================================================================================
//זוהי פונקציית הבניה של המחלקה
GameObject::GameObject(const int typePic, const sf::Vector2f& pos, const sf::Vector2f& origin)
	: m_picture(Design::getDesign().getPicture(typePic))
{
	m_picture.setOrigin(origin);
	m_picture.setPosition(pos);
}

//=================================================================================================
//פונקציה זו מחזירה את המיקום של האובייקט על החלון
const sf::Vector2f& GameObject::getPos()const
{
	return m_picture.getPosition();
}
//=================================================================================================
//פונקציה זו מציירת את האובייקט על החלון
void GameObject::draw()
{
	Design::getDesign().getWindow().draw(m_picture);
}
//=================================================================================================
//פונקציה זו משנה את מיקום האובייקט למיקום שהתקבל אצלה
void GameObject::setPosPic(const sf::Vector2f& newPos)
{
	m_picture.setPosition(newPos);
}
