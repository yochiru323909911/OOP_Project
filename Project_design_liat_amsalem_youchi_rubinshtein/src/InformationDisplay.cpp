#include "InformationDisplay.h"
#include "Design.h"

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת האינפורמציה
InformationDisplay::InformationDisplay(int numlevel, int& levelTime, int& credits, const int creditsGoal, int& life)
	:m_levelTime(levelTime), m_credits(credits), m_timerSound(Design::getDesign().getSound(TIMER_SOUND_PLACE)), m_creditsGoal("/"+std::to_string(creditsGoal)), m_life(life)
{
	m_icons.resize(NUM_DATA);
	m_texts.resize(NUM_DATA);

	m_icons[CLOCK].setTexture(Design::getDesign().getPicture(CLOCK_PLACE));
	m_icons[CREDITS].setTexture(Design::getDesign().getPicture(CREDITS_PLACE));
	m_icons[NUM_LEVEL].setTexture(Design::getDesign().getPicture(NUM_LEVEL_PLACE));
	m_icons[LIFE].setTexture(Design::getDesign().getPicture(LIFE_PLACE));

	m_texts[CLOCK].setFont(Design::getDesign().getFont());
	m_texts[CREDITS].setFont(Design::getDesign().getFont());
	m_texts[NUM_LEVEL].setFont(Design::getDesign().getFont());
	m_texts[NUM_LEVEL].setString("Level "+std::to_string(numlevel));
	
	for (int index = 0; index < m_texts.size(); index++)
		m_texts[index].setCharacterSize(22);
}
//=================================================================================================
//פונקציה זו מדפיסה את תפריט המידע שבצד לוח המשחק
void InformationDisplay::show()
{
	auto viewPos = Design::getDesign().getWindow().getView().getCenter();
	convertClockToTime(m_levelTime - m_clock.getElapsedTime().asSeconds());
	m_texts[CREDITS].setString(std::to_string(m_credits) + m_creditsGoal);
	for (int ind_icon = 0; ind_icon < m_icons.size() - 1; ind_icon++)
	{
		m_icons[ind_icon].setPosition(viewPos.x - SIZE_VIEW_X / 2 + 20 + ((ICON_SIZE + (SPACE * 7)) * ind_icon), viewPos.y - (SIZE_VIEW_Y / 2) + 20);
		Design::getDesign().getWindow().draw(m_icons[ind_icon]);
		sf::Vector2f posText = { m_icons[ind_icon].getPosition().x + ICON_SIZE + SPACE, m_icons[ind_icon].getPosition().y - (SPACE / 2) };
		m_texts[ind_icon].setPosition(posText);
		Design::getDesign().getWindow().draw(m_texts[ind_icon]);
	}
	for (int lifeIcon = 0; lifeIcon < m_life; lifeIcon++)
	{
		m_icons[LIFE].setPosition(m_texts[NUM_LEVEL].getPosition().x + ((SPACE * 7) + (ICON_SIZE * lifeIcon)), m_icons[NUM_LEVEL].getPosition().y);
		Design::getDesign().getWindow().draw(m_icons[LIFE]);
	}
}
//=================================================================================================
//פונקציה זו ממירה את הזמן שחלף לזמן קונקרטי ומכניסה לדקות ושניות
void InformationDisplay::convertClockToTime(const int time_in_seconds)
{
	int minutes = time_in_seconds / MINUTE;
	std::string time = std::to_string(minutes) += ":";
	if (time_in_seconds == MINUTE / 6)
	{
		m_timerSound.setVolume(500);
		m_timerSound.play();
		m_timerSound.setLoop(true);
	}
	if (time_in_seconds < MINUTE/6)
	{
		m_texts[CLOCK].setString(time + "0" + std::to_string(time_in_seconds - (minutes * MINUTE)));  //אם יש מספר חד ספרתי של שניות
		m_texts[CLOCK].setColor(sf::Color::Red);
	}
	else
		m_texts[CLOCK].setString(time += std::to_string(time_in_seconds - (minutes * MINUTE)));
}
//=================================================================================================
//פונקציה זו מחזירה אמת אם נגמר הזמן ואם לא  אז היא מחזירה שקר
bool InformationDisplay::isTimeOver()
{
	if ((m_levelTime - m_clock.getElapsedTime().asSeconds()) <= 0)
		return true;
	return false;
}