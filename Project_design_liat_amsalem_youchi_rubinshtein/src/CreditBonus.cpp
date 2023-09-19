#include "CreditBonus.h"
#include "FactoryBonus.h"
//=================================================================================================
//זוהי פונקציית הבנאי של מחלקת בונוס של נקודות
CreditBonus::CreditBonus(const sf::Vector2f& pos, GameBoard& gameBoard)
	:Bonus(BONUS_PLACE, pos, gameBoard)
{}
//=================================================================================================
//זוהי פונקציה שמטפלת במקרה ששחקן אכל בונוס של נקודות
void CreditBonus::hitBonus()
{
	if (!m_taken)
	{
		m_gameBoard.setCredits(CREDIT); 
		hit();
	}
}
//=================================================================================================
//זוהי התחברות לפקטורי שיוצר את הבונוסים
bool CreditBonus::m_registerit = FactoryBonus::getFactoryBonus().registerBonus(
	[](sf::Vector2f pos, GameBoard& gameBoard)->std::unique_ptr<Bonus>
	{return std::make_unique<CreditBonus>(pos, gameBoard); }, CREDIT_BONUS);