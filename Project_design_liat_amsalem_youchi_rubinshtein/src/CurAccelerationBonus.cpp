#include "CurAccelerationBonus.h"
#include "FactoryBonus.h"
//=================================================================================================
//זוהי פונקציית הבנאי של המחלקה
CurAccelerationBonus::CurAccelerationBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(CUR_SPEED_BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//זוהי פונקציה שמטפלת במקרה של אכילת בונוס תאוצה נוכחית
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
//זוהי התחברות לפקטורי שיוצר את הבונוסים
bool CurAccelerationBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<CurAccelerationBonus>(pos, gameBoard); }, CUR_ACCELERATION_BONUS);