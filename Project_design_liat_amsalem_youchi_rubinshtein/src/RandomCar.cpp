#include "RandomCar.h"
#include "Consts.h"
#include "Design.h"
#include "GameBoard.h"

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת המכונית הרנדומלית
RandomCar::RandomCar(const Direction_t& direct, const sf::Vector2f& pos, GameBoard& gameBoard)
	:Car(RANDOM_CAR_PLACE, (RAND_MIN_SPEED + rand() % RAND_MAX_SPEED), direct, pos, gameBoard, HIT_SOUND_PLACE)
{
	static int numRec = 0;
	m_picture.setTextureRect(sf::IntRect((numRec * CAR_WIDTH), 0, CAR_WIDTH, CAR_LENGTH));
	if (numRec == 3)
		numRec = 0;
	else
		numRec++;
}
//=================================================================================================
//זוהי פונקצייה התנגשות של מכונית במכונית רנדומלית
void RandomCar::hitRandomCar()
{
	static int indTime = 0;
	if (indTime > 4)
	{
		m_gameBoard.deleteCar(this);
		indTime = 0;
		return;
	}
	if (indTime % 2 == 0)
		Design::getDesign().getWindow().draw(m_picture);
	else
		Design::getDesign().getWindow().draw(m_picture);
	indTime++;
}