#include "CurAccelerationBonus.h"
#include "FactoryBonus.h"
//=================================================================================================
//���� �������� ����� �� ������
CurAccelerationBonus::CurAccelerationBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(CUR_SPEED_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//���� ������� ������ ����� �� ����� ����� ����� ������
void CurAccelerationBonus::hitBonus(float& curSpeed, const float maxSpeed)
{
	if (!m_taken)
	{
		if ((curSpeed + ADDSPEED) <= maxSpeed)
			curSpeed += ADDSPEED;
		hit();
	}
}
//=================================================================================================
//���� ������� ������� ����� �� ��������
bool CurAccelerationBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<CurAccelerationBonus>(pos, gameBoard); }, CUR_ACCELERATION_BONUS);