#include "FileExceptions.h"
#include "Consts.h"
//=================================================================================================
//������� �� ��� �������� ����� �� ����� ������ �����
//��� ����� ������ ������� ���� ����� ������
FileExceptions::FileExceptions(const std::string& error)
{
	m_error.setFont(Design::getDesign().getFont());
	m_error.setString(error);
	m_error.setColor(sf::Color::Red);
	m_error.setPosition({ Design::getDesign().getWindow().getView().getCenter().x - SIZE_EXCEPTION,
		Design::getDesign().getWindow().getView().getCenter().y });
}
//=================================================================================================
//������� �� ������ �� ����� ������
void FileExceptions::handleException()
{
	Design::getDesign().getWindow().clear();
	Design::getDesign().getWindow().draw(m_error);
	Design::getDesign().getWindow().display();
}