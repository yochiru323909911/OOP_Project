#include "PlayerCar.h"
#include "Design.h"
#include "GameBoard.h"
#include "RandomCar.h"
#include "Car.h"

//=================================================================================================
//זוהי פונקציית הבניה של מחלקת השחקן
PlayerCar::PlayerCar(GameBoard& gameBoard)
    :m_maxSpeed(MAX_SPEED), Car(PLAYER_CAR_PLACE, PLAYER_CAR_SPEED, UP, { (WIND_SIZE_X / 2) + (CAR_WIDTH / 2),WIND_SIZE_Y - (HIGHT_ROAD / 2) }, gameBoard, HIT_SOUND_PLACE)
    , m_MoveFastsound(Design::getDesign().getSound(ACCES_SOUND_PLACE)), m_drownInRiver(false), m_toKill(false)
    , m_animationBoom(Design::getDesign().getPicture(BOOM_ANIMATION_PLACE)), m_calculates()
{
    m_picture.setTextureRect({ 0, 0, CAR_WIDTH, CAR_LENGTH });
}
//=================================================================================================
//פונקציה זו מטפלת בתזוזה מהירה יותר מהסטנדרט
void PlayerCar::handleMoveFast(float deltaTime, Direction_t pressedDirc)
{
    if ((m_speed + ADDSPEED) <= m_maxSpeed)
    {
        m_MoveFastsound.play();
        m_speed += ADDSPEED;
        movePlayer(deltaTime, pressedDirc);
        m_speed -= ADDSPEED;
    }
}
//=================================================================================================
//פונקציה זו משנה את הכיוון של המכונית לפרמטר שהיא קיבלה
void PlayerCar::setDirection(Direction_t newDirc)
{
    m_direction = newDirc;
}
//=================================================================================================
//פונקציה זו מטפלת בתזוזה של השחקן
void PlayerCar::movePlayer(float deltaTime, Direction_t pressedDirc)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pressedDirc == m_direction)
        handleMoveFast(deltaTime, pressedDirc);
    auto originalDir = m_direction;
    if ((pressedDirc == RIGHT && m_direction == LEFT) || (pressedDirc == LEFT && m_direction == RIGHT) ||
        (pressedDirc == DOWN && m_direction == UP) || (pressedDirc == UP && m_direction == DOWN))
    {
        m_direction = pressedDirc;
        move(deltaTime); 
        m_direction = changeDirection();
    }
    else if (pressedDirc == m_direction)
        move(deltaTime);
    else
    {
        if (pressedDirc < 4)
        {
           m_calculates.PressDirection[m_direction][pressedDirc](*this);
            m_direction = pressedDirc;
        }
        else
        {
            m_calculates.PressDirection[pressedDirc][m_direction](*this);
            move(deltaTime);
            m_direction = originalDir;
        }
    }
    m_playerCarPos = m_picture.getPosition();
}
//=================================================================================================
//פונקציה זו מטפלת בהתנגשות מכונית השחקן מול מכונית רנדומלית
void PlayerCar::hitRandomCar(RandomCar& randCar)
{
    if (m_toKill)
    {
        m_index = 0;
        m_animationBoom.setPosition(randCar.getPic().getPosition());
        m_gameBoard.deleteCar(&randCar);
    }
    else
    {
        m_sound.setBuffer(Design::getDesign().getSound(HIT_SOUND_PLACE));
        randCar.changeDirection();
    }
    playSound();
}
//=================================================================================================
//פונקציה זו מפעילה את הסאונד של ההתנגשות באובייקט
void PlayerCar::playSound()
{
    m_sound.play();
}
//=================================================================================================
//פונקציה זו מציירת אנימציה של מכונית השחקן טובעת בנהר
void PlayerCar::drownInRiver()
{
    static int x = 0;
    sf::sleep(sf::seconds(0.1));
    if (m_direction == RIGHT)
    {
        m_picture.move(SPACE / 2, 0);
        m_picture.setRotation(0);
    }
    else
    {
        m_picture.move(-SPACE / 2, 0);
        m_picture.setRotation(180);
    }
    auto rect = sf::Rect{ CAR_WIDTH + (x * CAR_LENGTH), 0, CAR_LENGTH, CAR_WIDTH };
    m_picture.setTextureRect(rect);
    Design::getDesign().getWindow().draw(m_picture);
    x++;
    if (x == ANIMATION_SIZE)
    {
        x = 0;
        m_drownInRiver = false;
    }
}
//=================================================================================================
//פונקציה זו מציירת את מכונית השחקן ואם הוא מפוצץ מכונית רנדומלית אז גם את הפיצוץ הפונקציה מציירת
void PlayerCar::draw()
{
    GameObject::draw();
    if (m_toKill)
    {
        if (m_killRandCarTimer.getElapsedTime().asSeconds() > KILL_BONUS_TIME)
            m_toKill = false;
        else
        {
            if (m_index < (BOOM_ANIMATION_WIDTH * ANIMATION_SIZE))
            {
                m_animationBoom.setTextureRect(sf::Rect{ m_index,0,BOOM_ANIMATION_WIDTH, BOOM_ANIMATION_LEN });
                m_index += BOOM_ANIMATION_WIDTH;
                m_animationBoom.setOrigin(sf::Vector2f(BOOM_ANIMATION_WIDTH / 2, BOOM_ANIMATION_LEN / 2));
                Design::getDesign().getWindow().draw(m_animationBoom);
            }
        }
    }
}
//=================================================================================================
//פונקציה זו מחזירה אמת אם המשתנה הנ"ל אמת ומחזירה שקר אם הוא שקר
bool PlayerCar::getDrown()
{
    return m_drownInRiver;
}
//=================================================================================================
//פונקציה זו מטפלת בהתנגשות של מכונית השחקן
void PlayerCar::hitSmartCar()
{
    sf::Sound specialSound(Design::getDesign().getSound(HITSMARTCAR_PLACE));
    specialSound.play();
    m_gameBoard.minusLife();
    m_direction = changeDirection();
    move(1);
    m_direction = changeDirection();
}