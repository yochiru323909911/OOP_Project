#include "SmartCar.h"
#include "CollisionHandling.h"

//=================================================================================================
//זוהי פונקציית הבניה של מכונית חכמה
SmartCar::SmartCar(const int typeCar, const int speedCar, const Direction_t& direct,
	                const sf::Vector2f& pos, GameBoard& gameBoard, int sound_place, PlayerCar& playerCar)
	: Car(typeCar, speedCar, direct, pos, gameBoard, sound_place), m_playerCar(playerCar)
{
	m_timerLife.restart();
	m_lifeTime = TIMELIFE + rand() % TIMELIFE;
	m_sound.setVolume(30);
	m_sound.play();
	m_sound.setLoop(true);
}
//=================================================================================================
//זוהי פונקציית התזוזה של מכונית חכמה
void SmartCar::move(float deltaTime)
{
	if (m_timerLife.getElapsedTime().asSeconds() >= m_lifeTime)
		 m_gameBoard.deleteCar(this);
	else
	{
		switch (m_direction)
		{
		case LEFT:
		{
			if (m_playerCar.getPos().x == m_picture.getPosition().x)
				return;
			if (m_playerCar.getPos().x > m_picture.getPosition().x)
				m_direction = RIGHT;
			break;
		}
		case RIGHT:
		{
			if (m_playerCar.getPos().x == m_picture.getPosition().x)
				return;
			if (m_playerCar.getPos().x < m_picture.getPosition().x)
				m_direction = LEFT;
			break;
		}
		case UP:
		{
			if (m_playerCar.getPos().y == m_picture.getPosition().y)
				return;
			if (m_playerCar.getPos().y > m_picture.getPosition().y)
				m_direction = DOWN;
			break;
		}
		case DOWN:
		{
			if (m_playerCar.getPos().y == m_picture.getPosition().y)
				return;
			if (m_playerCar.getPos().y < m_picture.getPosition().y)
				m_direction = UP;
			break;
		}
		}
		Car::move(deltaTime);
	}
}