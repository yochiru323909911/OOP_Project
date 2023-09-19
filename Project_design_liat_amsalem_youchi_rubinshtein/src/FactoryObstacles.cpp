#include "FactoryObstacles.h"
#include  "Fence.h"
#include "River.h"
//=================================================================================================
//פונקציה זו מחשבת את המכשולים שמקיפים כביש אחד בהתאם לכביש הקודם
std::vector<std::unique_ptr<StaticObj>> FactoryObstacles::createObstacles(const sf::Vector2f& curRoadPos, const Direction_t& direct, const Direction_t& prevRoadDirect, const bool isRiver )
{
	m_fences.clear();
	switch (direct)
	{
	case UP:
	{
		if (isRiver==false)
		{
			if (prevRoadDirect == UP)
			{
				m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + (WIDTH_ROAD / 2) + (OBSTACLE_WIDTH / 2), curRoadPos.y }, VERTICAL));
				m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x - (WIDTH_ROAD / 2) - (OBSTACLE_WIDTH / 2), curRoadPos.y }, VERTICAL));
			}
			else
			{
				m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + (WIDTH_ROAD / 2) + (OBSTACLE_WIDTH / 2), curRoadPos.y - WIDTH_ROAD }, VERTICAL, OBSTACLE_HIGHT - OBSTACLE_WIDTH, sf::Vector2f{ (OBSTACLE_WIDTH / 2),HIGHT_ROAD - WIDTH_ROAD }));
				m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x - (WIDTH_ROAD / 2) - (OBSTACLE_WIDTH / 2), curRoadPos.y - WIDTH_ROAD }, VERTICAL, OBSTACLE_HIGHT - OBSTACLE_WIDTH, sf::Vector2f{ (OBSTACLE_WIDTH / 2), HIGHT_ROAD - WIDTH_ROAD }));
			}
		}
		else
		{
			if (prevRoadDirect == UP)
			{
				m_fences.emplace_back(std::make_unique<River>(sf::Vector2f{ curRoadPos.x + (WIDTH_ROAD / 2) + (RIVER_WIDTH / 2), curRoadPos.y }, VERTICAL,  RIGHT));
				m_fences.emplace_back(std::make_unique<River>(sf::Vector2f{ curRoadPos.x - (WIDTH_ROAD / 2) - (RIVER_WIDTH / 2), curRoadPos.y }, VERTICAL, LEFT));
			}
			else
			{
				m_fences.emplace_back(std::make_unique<River>(sf::Vector2f{ curRoadPos.x + (WIDTH_ROAD / 2) + (RIVER_WIDTH / 2), curRoadPos.y - WIDTH_ROAD }, VERTICAL, RIVER_HIGHT - OBSTACLE_WIDTH, sf::Vector2f{ (RIVER_WIDTH / 2),HIGHT_ROAD - WIDTH_ROAD }, RIGHT));
				m_fences.emplace_back(std::make_unique<River>(sf::Vector2f{ curRoadPos.x - (WIDTH_ROAD / 2) - (RIVER_WIDTH / 2), curRoadPos.y - WIDTH_ROAD }, VERTICAL, RIVER_HIGHT - OBSTACLE_WIDTH, sf::Vector2f{ (RIVER_WIDTH / 2), HIGHT_ROAD - WIDTH_ROAD }, LEFT));
			}
		}
		break;
	}

	case RIGHT:
	{
		m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + HIGHT_ROAD, curRoadPos.y - (WIDTH_ROAD / 2) - (OBSTACLE_WIDTH / 2) }, HORIZONTAL));
		m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + HIGHT_ROAD + (OBSTACLE_WIDTH / 2), curRoadPos.y + (WIDTH_ROAD / 2) + OBSTACLE_WIDTH }, VERTICAL, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)), sf::Vector2f(OBSTACLE_WIDTH / 2, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)))));
		if (prevRoadDirect == UP)
		{
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x - (OBSTACLE_WIDTH / 2), curRoadPos.y + (WIDTH_ROAD / 2) + OBSTACLE_WIDTH }, VERTICAL, WIDTH_ROAD + (2 * OBSTACLE_WIDTH), sf::Vector2f(OBSTACLE_WIDTH / 2, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)))));
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x+WIDTH_ROAD+(OBSTACLE_WIDTH/2), curRoadPos.y-(WIDTH_ROAD/2)-(OBSTACLE_WIDTH) },HORIZONTAL, HIGHT_ROAD - WIDTH_ROAD, sf::Vector2f{ HIGHT_ROAD-WIDTH_ROAD,(OBSTACLE_WIDTH / 2) }));
		}
		if (prevRoadDirect == RIGHT)
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + HIGHT_ROAD, curRoadPos.y + (WIDTH_ROAD / 2) + (OBSTACLE_WIDTH / 2) }, HORIZONTAL));
		break;
	}
	case LEFT:
	{
		m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x - HIGHT_ROAD - (OBSTACLE_WIDTH / 2), curRoadPos.y + (WIDTH_ROAD / 2) + OBSTACLE_WIDTH }, VERTICAL, WIDTH_ROAD + (2 * OBSTACLE_WIDTH), sf::Vector2f(OBSTACLE_WIDTH / 2, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)))));
		m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x, curRoadPos.y - (OBSTACLE_WIDTH / 2) - (WIDTH_ROAD / 2) }, HORIZONTAL));
		if (prevRoadDirect == UP)
		{
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x + (OBSTACLE_WIDTH / 2) , curRoadPos.y + (WIDTH_ROAD / 2) + OBSTACLE_WIDTH }, VERTICAL, WIDTH_ROAD + (2 * OBSTACLE_WIDTH), sf::Vector2f(OBSTACLE_WIDTH / 2, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)))));//
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x-HIGHT_ROAD+(OBSTACLE_WIDTH/2), curRoadPos.y-WIDTH_ROAD+ (OBSTACLE_WIDTH / 2) }, HORIZONTAL, HIGHT_ROAD - WIDTH_ROAD, sf::Vector2f{ OBSTACLE_HIGHT - WIDTH_ROAD, (OBSTACLE_WIDTH / 2) }));
		}
		if (prevRoadDirect == LEFT)
		{
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x - HIGHT_ROAD - (OBSTACLE_WIDTH / 2), curRoadPos.y + (WIDTH_ROAD / 2) + OBSTACLE_WIDTH }, VERTICAL, WIDTH_ROAD + (2 * OBSTACLE_WIDTH), sf::Vector2f(OBSTACLE_WIDTH / 2, (WIDTH_ROAD + (2 * OBSTACLE_WIDTH)))));
			m_fences.emplace_back(std::make_unique<Fence>(sf::Vector2f{ curRoadPos.x, curRoadPos.y+(WIDTH_ROAD/2)+(OBSTACLE_WIDTH/2)}, HORIZONTAL));
		}
			break;
	}
	}
	return std::move(m_fences);
}
