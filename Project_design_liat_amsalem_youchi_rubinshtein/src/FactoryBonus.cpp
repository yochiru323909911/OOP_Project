#include "FactoryBonus.h"
#include "Bonus.h"
#include "GameBoard.h"
#include <memory>
#include <functional>
#include "StaticObj.h"

//=================================================================================================
//������� �� ����� ������� �"� ������ �����
std::vector<std::unique_ptr<StaticObj>> FactoryBonus::createBonus(GameBoard& gameBoard)
{
	m_bonuses.clear();
	sf::Vector2f startRange, pos;
	sf::Vector2u endRange, total;
	gameBoard.findRange(startRange, endRange, (BONUS_LENTGH / 2));//2f
	int maxbonus = 1 + rand() % AMOUNT_BONUSES;
	for (int indBonus = 0; indBonus < maxbonus; indBonus++)
	{
		pos = sf::Vector2f(startRange.x + rand() % endRange.x, startRange.y + rand() % endRange.y);
		m_bonuses.emplace_back(m_createFuncs[randTypeBonus()](pos, gameBoard));
	}
	return std::move(m_bonuses);
}
//=================================================================================================
//������� �� ������ ��� ����� �"� �����
BonusType FactoryBonus::randTypeBonus()
{
	int typebonus = rand() % 65;
	if (typebonus >= 0 && typebonus <= 35) //������ ������ �� �� �������� ��� ����� ����� ������
		return CREDIT_BONUS;
	if (typebonus > 35 && typebonus <= 42) 
		return CUR_ACCELERATION_BONUS;
	if (typebonus > 42 && typebonus <= 47)
		return MAX_ACCELRERATION_BONUS;
	if (typebonus > 47 && typebonus <= 62)
		return KILL_BONUS;
	else
		return TIME_BONUS; //������ ����� ��� �� ��� ��� �������� ����� ������
}
//=================================================================================================
//������� �� ����� ����� �������� �������� ������ . �������� ������ �� �������� ������ ���� ����� ��������
bool FactoryBonus::registerBonus(std::function<std::unique_ptr<Bonus>(const sf::Vector2f&, GameBoard&)> func, BonusType index)
{
	m_createFuncs.resize(5);
	m_createFuncs[index] = func;
	return true;
}