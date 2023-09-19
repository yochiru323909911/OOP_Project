#include "Design.h"
#include "Consts.h"
#include "FileExceptions.h"
//=================================================================================================
//זוהי פונקציית הבנאי של המחלקה
Design::Design()
	:m_window(sf::RenderWindow(sf::VideoMode(WIND_SIZE_X, WIND_SIZE_Y), "CarCrash"/*, sf::Style::Fullscreen*/))
{
	loadPictures();
	loadSounds();
	loadFont();
}
//=================================================================================================
//פונקציה זו דואגת לטעינת התמונות
void Design::loadPictures()
{
	m_pictures.resize(AMOUNT_PICS);
	safeLoadPic(BACKGROUND_PLACE, BACKGROUND);
	safeLoadPic(BACKGROUND_PLACE,BACKGROUND);
	safeLoadPic(RANDOM_CAR_PLACE,RANDOM_CAR_PIC);
	safeLoadPic(PLAYER_CAR_PLACE,PLAYER_CAR_PIC);
	safeLoadPic(BONUS_PLACE,BONUS_PIC);
	safeLoadPic(ROAD_PLACE,ROAD_PIC);
	safeLoadPic(PLAY_PLACE,PLAY_PIC);
	safeLoadPic(EXIT_PLACE,EXIT_PIC);
	safeLoadPic(HELP_PLACE,HELP_PIC);
	safeLoadPic(OPENSCREEN_PLACE,OPENSCREEN);
	safeLoadPic(FENCE_PLACE,FENCE);
	safeLoadPic(TIME_BONUS_PLACE,TIME_BONUS_PIC);
	safeLoadPic(CREDITS_PLACE,CREDITS_PIC);
	safeLoadPic(CLOCK_PLACE,CLOCK_PIC);
	safeLoadPic(NUM_LEVEL_PLACE,NUM_LEVEL_PIC);
	safeLoadPic(CUR_SPEED_BONUS_PLACE,CUR_SPEED_BONUS_PIC);
	safeLoadPic(MAX_SPEED_BONUS_PLACE,MAX_SPEED_BONUS_PIC);
	safeLoadPic(POLICE_PLACE,POLICE_PIC);
	safeLoadPic(INSTUCTIONS_PLACE,INSTUCTIONS);
	safeLoadPic(MOTORCYCLE_PLACE,MOTORCYCLE_PIC);
	safeLoadPic(WIN_PIC_PLACE,WINMSG_PIC);
	safeLoadPic(FAILED_PIC_PLACE,FAILMSG_PIC);
	safeLoadPic(TRUCK_PLACE,TRUCK_PIC);
	safeLoadPic(RIVER_PLACE,RIVER_PIC);
	safeLoadPic(BRIDGE_PLACE,BRIDGE_PIC);
	safeLoadPic(BOOM_ANIMATION_PLACE,BOOM_PIC);
	safeLoadPic(KILL_BONUS_PLACE,KILL_BONUS_PIC);
	safeLoadPic(EXIT_INSTRUCTIONS_PLACE,EXIT_INSTRUCTIONS);
	safeLoadPic(LIFE_PLACE, LIFE_PIC);
}
//=================================================================================================
//פונקציה זו דואגת לטעינת הסאונד
void Design::loadSounds()
{
	m_sounds.resize(HITSMARTCAR_PLACE + 1);
	m_sounds[TIMER_SOUND_PLACE].loadFromFile(TIMER_SOUND);
	m_sounds[LEVEL_SOUND_PLACE].loadFromFile(LEVEL_SOUND);
	m_sounds[ACCES_SOUND_PLACE].loadFromFile(ACCES_SOUND);
	m_sounds[HIT_SOUND_PLACE].loadFromFile(HIT_SOUND);
	m_sounds[POLICE_SOUND_PLACE].loadFromFile(POLICE_SOUND);
	m_sounds[BONUS_SOUND_PLACE].loadFromFile(BONUS_SOUND);
	m_sounds[MOTORCYCLE_SOUND_PLACE].loadFromFile(MOTORCYCLE_SOUND);
	m_sounds[TRUCK_SOUND_PLACE].loadFromFile(TRUCK_SOUND);
	m_sounds[WIN_SOUND_PLACE].loadFromFile(WIN_SOUND);
	m_sounds[FAIL_SOUND_PLACE].loadFromFile(FAIL_SOUND);
}
//=================================================================================================
//פונקציה זו טוענת גופן
void Design::loadFont()
{
	m_font.loadFromFile("C:/Windows/Fonts/Forte.ttf");
}
//=================================================================================================
//פונקציה זו מקבלת מיקום בוקטור ומחזירה את התמונה שנמצאת במיקום זה בוקטור התמונות
sf::Texture& Design::getPicture(const int pic_place)
{
	return m_pictures[pic_place];
}
//=================================================================================================
//פונקציה זו מביאה את החלון
sf::RenderWindow& Design::getWindow()
{
	return m_window;
}
//=================================================================================================
//פונקציה זו מחזירה את הגופן שטענה
sf::Font& Design::getFont()
{
	return m_font;
}
//=================================================================================================
//פונקציה זו מקבלת מיקום בוקטור ומחזירה את חוצץ הסאונד שנמצא במיקום זה בוקטור החוצצים לסאונד
sf::SoundBuffer& Design::getSound(const int sound_place)
{
	return m_sounds[sound_place];
}
//=================================================================================================
//פונקציה זו טוענת תמונה ואם הטעינה לא הצליחה היא מוציאה הודעת שגיאה על המסך
void Design::safeLoadPic(const int index, const std::string& pic)
{
	if (!m_pictures[index].loadFromFile(pic))
		throw FileExceptions("Can't load picture "+pic);
}