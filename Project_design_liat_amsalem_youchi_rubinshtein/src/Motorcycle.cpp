#include "Motorcycle.h"

//=================================================================================================
//זוהי התחברות לפקטורי שיוצר את המכוניות החכמות
bool Motorcycle::m_registerit = FactorySmartCar::getFactorySmartCar().registerSmartCar(
	[](const Direction_t& dir, sf::Vector2f pos, GameBoard& gameBoard, PlayerCar& playerCar)->std::unique_ptr<SmartCar>
	{return std::make_unique<Motorcycle>(dir, pos, gameBoard, playerCar); });