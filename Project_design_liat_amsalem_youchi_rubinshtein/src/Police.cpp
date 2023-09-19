#include "Police.h"

//=================================================================================================
//זוהי התחברות לפקטורי שיוצר מכוניות חכמות
bool Police::m_registerit = FactorySmartCar::getFactorySmartCar().registerSmartCar(
	[](const Direction_t& dir, sf::Vector2f pos, GameBoard& gameBoard, PlayerCar& playerCar)->std::unique_ptr<SmartCar>
	{return std::make_unique<Police>(dir, pos, gameBoard, playerCar); });
