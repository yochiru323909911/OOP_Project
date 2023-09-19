#include "Car.h"
#include "CollisionHandling.h"
#include "GameBoard.h"

//=================================================================================================
//זוהי פונקציית הבנאי של מכונית. היא גם מסובבת אותה לפי הכיוון שהיא אמורה להיות בו
Car::Car(const int typePic, const int speed, const Direction_t& direct, const sf::Vector2f&  pos, GameBoard& gameBoard, const int sound_place)
	:GameObject(typePic, pos, sf::Vector2f((CAR_WIDTH/2), (CAR_LENGTH / 2))), m_speed(speed), m_direction(direct), 
	 m_gameBoard(gameBoard) ,m_sound(Design::getDesign().getSound(sound_place))
{
	switch (m_direction)
	{
	case LEFT:m_picture.rotate(270); break;
	case RIGHT:m_picture.rotate(90); break;
	case DOWN:m_picture.rotate(180); break;
	default:
		break;
	}
}
//=================================================================================================
//זוהי פונקציית התזוזה של מכונית. הפונקציה מזיזה ואם גילתה התנגשות חוסמת אז מחזירה את המכונית למיקומה הקודם
void Car::move(float deltaTime)
{
	auto originalSpeed = m_speed;
	auto originalPos = m_picture.getPosition();
	sf::Vector2f moveTo = getMoveByDirc();
	m_picture.move({ moveTo.x * (m_speed * deltaTime), moveTo.y * (m_speed * deltaTime) });//

	GameObject* colideObj = m_gameBoard.checkColision(this);
	if (m_picture.getPosition().y >= WIND_SIZE_Y+WIDTH_ROAD/2 || (colideObj != nullptr && !processCollision(*this, *colideObj)))
			m_picture.setPosition(originalPos);
}
//=================================================================================================
//פונקציה זו מחזירה וקטור שמבטא את כיוון התזוזה במספרים ע"י הכיוון שקיבלה
const sf::Vector2f& Car::getMoveByDirc()
{
	switch (m_direction)
	{
	case LEFT: return { -1.f, 0.f };
	case RIGHT: return { 1.f, 0.f };
	case UP: return { 0.f, -1.f };
	case DOWN: return { 0.f, 1.f };
	}
}
//=================================================================================================
//פונקציה זו מממשת פונקציית התנגשות שמתאימה למכוניות
void Car::hitByCar()
{
	m_sound.play();
}
//=================================================================================================
//פונקציה זו מקבלת כיוון ומחזירה את ההפוך לו
Direction_t Car::changeDirection()
{
	switch (m_direction)
	{
	case LEFT: return RIGHT;
	case RIGHT: return LEFT;
	case UP: return DOWN;
	case DOWN: return UP;
	}
}
//=================================================================================================
//פונקציה זו משנה את כיוון המכונית
void Car::changeCar()
{
	m_direction = changeDirection();
	m_picture.rotate(180);
}