#include "Calculates.h"
#include "Consts.h"
#include "River.h"
#include "Fence.h"
#include "PlayerCar.h"
#include <iostream>
#include "Road.h"

//=================================================================================================
//זוהי מחלקה שתפקידה לבצע את החישובים הנדרשים למקרים מסויימים בכבישים, בלחיצות וכו'.
//היא מממשת את החישובים באמצעות מטריצות שכל תא בהן מכיל פונקציה שמבצעת את הפקודות שמתאימות לאותו תא שמייצג כיוונים
Calculates::Calculates()
{
	//זוהי מטריצה עבור חיתוך של מכשולים שמסביב לכביש שמוכלים בכביש שאחריהם
	RoadsDirections.resize(SIZE, std::vector<std::function<std::unique_ptr<StaticObj>(const sf::Vector2f&)>>(SIZE));
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			RoadsDirections[i][j] = [](const sf::Vector2f& pos)->std::unique_ptr<StaticObj> {return nullptr; };
	RoadsDirections[UP][LEFT] = [](const sf::Vector2f& pos)->std::unique_ptr<StaticObj> {return std::make_unique<Fence>(sf::Vector2f(sf::Vector2f(pos.x - OBSTACLE_HIGHT + WIDTH_ROAD + (OBSTACLE_WIDTH / 2), pos.y - (WIDTH_ROAD / 2) - OBSTACLE_WIDTH)), HORIZONTAL, (HIGHT_ROAD - WIDTH_ROAD), sf::Vector2f(WIDTH_ROAD, (OBSTACLE_WIDTH / 2))); };
	RoadsDirections[UP][RIGHT] = [](const sf::Vector2f& pos)->std::unique_ptr<StaticObj> {return std::make_unique<Fence>(sf::Vector2f(pos.x - HIGHT_ROAD + (OBSTACLE_WIDTH / 2), pos.y - (OBSTACLE_HIGHT / 2) - (OBSTACLE_WIDTH / 2)), HORIZONTAL, (HIGHT_ROAD - WIDTH_ROAD), sf::Vector2f(OBSTACLE_HIGHT - WIDTH_ROAD, (OBSTACLE_WIDTH / 2))); };
	RoadsDirections[LEFT][UP] = [](const sf::Vector2f& pos)->std::unique_ptr<StaticObj> {return std::make_unique<Fence>(sf::Vector2f(pos.x, pos.y - (WIDTH_ROAD / 2)), VERTICAL, HIGHT_ROAD - OBSTACLE_WIDTH, sf::Vector2f{ OBSTACLE_HIGHT - OBSTACLE_WIDTH, (OBSTACLE_WIDTH / 2) }); };
	RoadsDirections[RIGHT][UP] = [](const sf::Vector2f& pos)->std::unique_ptr<StaticObj> {return std::make_unique<Fence>(sf::Vector2f(pos.x + WIDTH_ROAD + (OBSTACLE_WIDTH / 2) + WIDTH_ROAD, pos.y - HIGHT_ROAD +WIDTH_ROAD+(OBSTACLE_WIDTH/2)), VERTICAL, HIGHT_ROAD - OBSTACLE_WIDTH, sf::Vector2f{ OBSTACLE_HIGHT - OBSTACLE_WIDTH,(OBSTACLE_WIDTH / 2) }); };

	//זוהי מטריצה עבור לחיצות של השחקן בשביל הזזת המכונית שלו
	PressDirection.resize(SIZE_PRESS_VEC, std::vector<std::function<void(PlayerCar&)>>(SIZE_PRESS_VEC / 2));
	for (int i = 0; i < SIZE_PRESS_VEC; i++)
		for (int j = 0; j < (SIZE_PRESS_VEC / 2); j++)
			PressDirection[i][j] = [](PlayerCar& player)->void {};
	PressDirection[DOWNRIGHT][RIGHT] = [](PlayerCar& player)->void {player.setDirection(DOWN); };
	PressDirection[DOWNRIGHT][DOWN] = [](PlayerCar& player)->void {player.setDirection(RIGHT); };
	PressDirection[DOWNRIGHT][UP] = [](PlayerCar& player)->void {player.setDirection(RIGHT); };
	PressDirection[UPRIGHT][UP] = [](PlayerCar& player)->void {player.setDirection(RIGHT); };
	PressDirection[UPRIGHT][RIGHT] = [](PlayerCar& player)->void {player.setDirection(UP); };
	PressDirection[DOWNLEFT][LEFT] = [](PlayerCar& player)->void {player.setDirection(DOWN); };
	PressDirection[DOWNLEFT][DOWN] = [](PlayerCar& player)->void {player.setDirection(LEFT); };
	PressDirection[DOWNLEFT][UP] = [](PlayerCar& player)->void {player.setDirection(LEFT); };
	PressDirection[UPLEFT][UP] = [](PlayerCar& player)->void {player.setDirection(LEFT); };
	PressDirection[UPLEFT][LEFT] = [](PlayerCar& player)->void {player.setDirection(UP); };
	PressDirection[UP][LEFT] = [](PlayerCar& player)->void {player.getPic().rotate(270); };
	PressDirection[UP][RIGHT] = [](PlayerCar& player)->void {player.getPic().rotate(90); };
	PressDirection[LEFT][UP] = [](PlayerCar& player)->void {player.getPic().rotate(90); };
	PressDirection[LEFT][DOWN] = [](PlayerCar& player)->void {player.getPic().rotate(270); };
	PressDirection[RIGHT][UP] = [](PlayerCar& player)->void {player.getPic().rotate(270); };
	PressDirection[RIGHT][DOWN] = [](PlayerCar& player)->void {player.getPic().rotate(90); };
	PressDirection[DOWN][RIGHT] = [](PlayerCar& player)->void {player.getPic().rotate(270); };
	PressDirection[DOWN][LEFT] = [](PlayerCar& player)->void {player.getPic().rotate(90); };

	//זוהי מטריצה עבור חישוב מיקום כביש חדש בהתאם לכיוון הכביש הקודם
	NewRoadPosition.resize(SIZE, std::vector<std::function<sf::Vector2f(Road&)>>(SIZE));
	NewRoadPosition[UP][RIGHT] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x - (WIDTH_ROAD / 2), prevRoad.getPos().y - (WIDTH_ROAD / 2) - HIGHT_ROAD }; };
	NewRoadPosition[UP][LEFT] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x + (WIDTH_ROAD / 2), prevRoad.getPos().y - (WIDTH_ROAD / 2) - HIGHT_ROAD }; };
	NewRoadPosition[UP][UP] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x, prevRoad.getPos().y - HIGHT_ROAD }; };
	NewRoadPosition[RIGHT][RIGHT] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x + HIGHT_ROAD, prevRoad.getPos().y }; };
	NewRoadPosition[RIGHT][UP] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x + HIGHT_ROAD - (WIDTH_ROAD / 2), prevRoad.getPos().y - (WIDTH_ROAD / 2) }; };
	NewRoadPosition[LEFT][LEFT] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x - HIGHT_ROAD, prevRoad.getPos().y }; };
	NewRoadPosition[LEFT][UP] = [](Road& prevRoad)->sf::Vector2f {return { prevRoad.getPos().x+ (WIDTH_ROAD / 2) - HIGHT_ROAD, prevRoad.getPos().y - (WIDTH_ROAD / 2) }; };

	//חישוב מיקום של מכונית חכמה ע"י כיוון הכביש
	matPos.resize(SIZE);
	matPos[LEFT] = [](sf::Vector2f& pos, const int i)->Direction_t {pos = { pos.x - WIDTH_ROAD - SPACE - i, pos.y }; return UP; };
	matPos[RIGHT] = [](sf::Vector2f& pos, const int i)->Direction_t {pos = { pos.x + WIDTH_ROAD + SPACE + i, pos.y }; return UP; };
	matPos[UP] = [](sf::Vector2f& pos, const int i)->Direction_t {pos = { pos.x, pos.y - HIGHT_ROAD + SPACE + i }; return LEFT; };


}
