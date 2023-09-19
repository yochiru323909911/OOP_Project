#include "CreditBonus.h"
#include "FactoryBonus.h"
//=================================================================================================
//���� �������� ����� �� ����� ����� �� ������
CreditBonus::CreditBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//���� ������� ������ ����� ����� ��� ����� �� ������
void CreditBonus::hitBonus()
{
	if (!m_taken)
	{
		m_gameBoard.setCredits(CREDIT); 
		hit();
	}
}
//=================================================================================================
//���� ������� ������� ����� �� ��������
bool CreditBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<CreditBonus>(pos, gameBoard); }, CREDIT_BONUS);