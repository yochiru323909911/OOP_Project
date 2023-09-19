#include "TimeBonus.h"
#include "FactoryBonus.h"

//=================================================================================================
//���� �������� ����� �� ������
TimeBonus::TimeBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(TIME_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//���� ������� ������ ����� �� ����� ����� ����� ������
void TimeBonus::hitBonus()
{
	if (!m_taken)
	{
		m_gameBoard.setTime(MINUTE / 6);
		hit();
	}
}
//=================================================================================================
// ���� ������� ������� ����� �� ��������
bool TimeBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<TimeBonus>(pos, gameBoard); }, TIME_BONUS);