#include "MaxAccelerationBonus.h"
#include "Consts.h"
#include "FactoryBonus.h"

//=================================================================================================
//���� �������� ����� �� ������
MaxAccelerationBonus::MaxAccelerationBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(MAX_SPEED_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//���� ������� ������ ����� �� ����� ����� ����� ��������
void MaxAccelerationBonus::hitBonus(int& maxSpeed)
{
	if (!m_taken)
	{
		maxSpeed += ADDSPEED;
		hit();
	}
}
//=================================================================================================
//��� ������� ������� ����� �� ��������
bool MaxAccelerationBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<MaxAccelerationBonus>(pos, gameBoard); }, MAX_ACCELRERATION_BONUS);