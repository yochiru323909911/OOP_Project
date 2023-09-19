#include "KillBonus.h"
#include "FactoryBonus.h"

//=================================================================================================
//זוהי פונקציית הבנאי של מחלקת בונוס הריגת מכוניות
KillBonus::KillBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(KILL_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//זוהי פונקציה שמטפלת במקרה ששחקן אכל בונוס של הריגת מכוניות

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
//זוהי התחברות לפקטורי שיוצר את הבונוסים
bool KillBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<KillBonus>(pos, gameBoard); }, KILL_BONUS);
