#pragma once
#include <string>

const std::string BACKGROUND="background.jpg";
const std::string ROAD_PIC = "road.jpg";
const std::string RANDOM_CAR_PIC = "randCar.png";
const std::string PLAYER_CAR_PIC = "playerCar.png";
const std::string POLICE_PIC = "police.png";
const std::string BONUS_PIC = "bonus.png";
const std::string TIME_BONUS_PIC = "timebonuspic.png";
const std::string CUR_SPEED_BONUS_PIC = "curspeed.png";
const std::string MAX_SPEED_BONUS_PIC = "maxspeed.png";
const std::string PLAY_PIC = "play.png";
const std::string EXIT_PIC = "exit.png";
const std::string HELP_PIC = "help.png";
const std::string OPENSCREEN = "openscreen.jpg";
const std::string INSTUCTIONS = "instructions.png";
const std::string FENCE = "fence.png";
const std::string CLOCK_PIC= "clock.png";
const std::string CREDITS_PIC = "credits.png";
const std::string NUM_LEVEL_PIC = "levelIcon.png";
const std::string TRUCK_PIC="truck.png";
const std::string MOTORCYCLE_PIC="motorcycle.png";
const std::string KILL_BONUS_PIC="killbonus.png";
const std::string BOOM_PIC="boom.png";
const std::string TRUCK_SOUND = "truckSound.ogg";
const std::string MOTORCYCLE_SOUND = "motorSound.ogg";
const std::string TIMER_SOUND = "timer.ogg";
const std::string LEVEL_SOUND = "play.ogg";
const std::string ACCES_SOUND = "acces.ogg";
const std::string HIT_SOUND = "hit.ogg";
const std::string POLICE_SOUND = "police.wav";
const std::string BONUS_SOUND = "bonus.ogg";
const std::string WINMSG_PIC= "winmsg.png";
const std::string FAILMSG_PIC = "failmsg.png";
const std::string RIVER_PIC = "river.png";
const std::string BRIDGE_PIC = "bridge.png";
const std::string WIN_SOUND = "win.ogg";
const std::string FAIL_SOUND = "fail.ogg";
const std::string EXIT_INSTRUCTIONS = "exitinstructions.png";
const std::string LIFE_PIC = "life.png";


const int AMOUNT_PICS = 29;
const int SIZE_PRESS_VEC = 8;
const int BACKGROUND_PLACE = 0;
const int RANDOM_CAR_PLACE = 1;
const int PLAYER_CAR_PLACE = 2;
const int BONUS_PLACE = 3;
const int ROAD_PLACE = 4;
const int PLAY_PLACE = 5;
const int EXIT_PLACE = 6;
const int HELP_PLACE = 7;
const int OPENSCREEN_PLACE = 8;
const int FENCE_PLACE = 10;
const int TIME_BONUS_PLACE = 11;
const int CREDITS_PLACE = 12;
const int CLOCK_PLACE = 13;
const int NUM_LEVEL_PLACE = 14;
const int CUR_SPEED_BONUS_PLACE = 15;
const int MAX_SPEED_BONUS_PLACE = 16;
const int POLICE_PLACE = 17;
const int INSTUCTIONS_PLACE = 18;
const int FAILED_PIC_PLACE = 19;
const int WIN_PIC_PLACE = 20;
const int MOTORCYCLE_PLACE = 21;
const int TRUCK_PLACE = 22;
const int RIVER_PLACE = 23;
const int BRIDGE_PLACE = 24;
const int BOOM_ANIMATION_PLACE = 25;
const int KILL_BONUS_PLACE=26;
const int EXIT_INSTRUCTIONS_PLACE = 27;
const int KILL_BONUS_TIME = 15;
const int BOOM_ANIMATION_LEN = 100;
const int BOOM_ANIMATION_WIDTH = 100;
const int TIMER_SOUND_PLACE = 0;
const int LEVEL_SOUND_PLACE = 1;
const int ACCES_SOUND_PLACE = 2;
const int HIT_SOUND_PLACE = 3;
const int POLICE_SOUND_PLACE = 4;
const int BONUS_SOUND_PLACE = 5;
const int MOTORCYCLE_SOUND_PLACE = 6;
const int TRUCK_SOUND_PLACE = 7;
const int WIN_SOUND_PLACE = 8;
const int FAIL_SOUND_PLACE = 9;
const int ANIMATION_SIZE = 12;
const int RIVER_HIGHT = 400;
const int RIVER_WIDTH = 200;
const int MIN_RAND = 2;//
const int MAX_RAND = 4;//
const int AMOUNT_RAND_CARS = 6;
const int SPACE = 10;
const int CAR_WIDTH = 30;
const int CAR_LENGTH = 50;
const int SIZE_SQUARE_IN_MAP = 100;
const int AMOUNT_BONUSES = 4;//to 
const int PLAYER_CAR = 0;
const int RAND_MIN_SPEED = 100;
const int RAND_MAX_SPEED = 160;
const int PLAYER_CAR_SPEED = 2000;
const int POLICE_SPEED = 400;
const int WIND_SIZE_X = 1500;
const int WIND_SIZE_Y = 900;
const int BONUS_WIDTH = 10;
const int BONUS_LENTGH = 30;
const int BG_AMOUNT = 11;
const int MIN_AMOUNT_ROAD = 15;
const int MAX_AMOUNT_ROAD = 20;
const int HIGHT_ROAD = 400;
const int WIDTH_ROAD = 150;
const int SIZE_VIEW_X = 1000;
const int SIZE_VIEW_Y = 600;
const int TIME = 180;
const int MINUTE = 60;
const int ADDSPEED = 400;
const int CREDIT = 2;
const int OBSTACLE_WIDTH = 50;
const int OBSTACLE_HIGHT = 400;
const int MAX_LEVELS = 3;
const int CLOCK = 0;
const int CREDITS = 1;
const int NUM_LEVEL = 2;
const int LIFE = 3;
const int LIFE_PLACE = 28;
const int NUM_DATA = 4;
const int ICON_SIZE = 20;
const int MAX_SPEED = 3500;
const int TIMELIFE = 7;
const int SIZE = 3;
const int MOTORFYCLE_SPEED = 200;
const int TRUCK_SPEED = 300;
const int HITSMARTCAR_PLACE = 10;
const int SIZE_EXCEPTION = 200;


enum BonusType
{
	MAX_ACCELRERATION_BONUS,
	TIME_BONUS,
	CUR_ACCELERATION_BONUS,
	CREDIT_BONUS,
	KILL_BONUS
};

enum Direction_t
{
 RIGHT, LEFT, UP, DOWN, UPRIGHT, UPLEFT, DOWNRIGHT, DOWNLEFT, SPACEUP
};

enum StateObstacle_t
{
	HORIZONTAL, VERTICAL
};

enum SmartCar_t
{
	POLICE, TRUCK, MOTORFYCLE
};