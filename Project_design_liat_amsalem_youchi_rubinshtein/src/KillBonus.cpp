#include "KillBonus.h"
#include "FactoryBonus.h"

//=================================================================================================
//���� �������� ����� �� ����� ����� ����� �������
KillBonus::KillBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(KILL_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//���� ������� ������ ����� ����� ��� ����� �� ����� �������

void KillBonus::hitBonus(PlayerCar* playerCar)
{
	if (!m_taken)
	{
		playerCar->restartKillTimer();
		playerCar->setKill(true);
		hit();
	}
}
//=================================================================================================
//���� ������� ������� ����� �� ��������
bool KillBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<KillBonus>(pos, gameBoard); }, KILL_BONUS);
