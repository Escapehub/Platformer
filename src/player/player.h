/*
    +---------------------------------------+
    |   Player handler                      |
    +---------------------------------------+
    |   \file player.h                      |
    |   \defines __PLAYER__                 |
    |   \class Player extends sf::Sprite    |
    +---------------------------------------+
*/

#ifndef __PLAYER__
#define __PLAYER__

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Includes
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <SFML/Graphics.hpp>
#include <string>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player directions
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_DIRECTION_RIGHT Player::Direction::Right
#define PLAYER_DIRECTION_LEFT  Player::Direction::Left

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player speed options
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_SPEED_WALK 0.2
#define PLAYER_SPEED_RUN  0.5

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player types
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_TYPE_WOODCUTTER  Player::PlayerType::WoodCutter
#define PLAYER_TYPE_GRAVEROBBER Player::PlayerType::GraveRobber
#define PLAYER_TYPE_STEAMMAN    Player::PlayerType::SteamMan

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player animations
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_ANIMATION_ATTACK1 Player::Animations::Attack1
#define PLAYER_ANIMATION_ATTACK2 Player::Animations::Attack2
#define PLAYER_ANIMATION_ATTACK3 Player::Animations::Attack3
#define PLAYER_ANIMATION_CLIMB   Player::Animations::Climb
#define PLAYER_ANIMATION_DEATH   Player::Animations::Death
#define PLAYER_ANIMATION_HURT    Player::Animations::Hurt
#define PLAYER_ANIMATION_IDLE    Player::Animations::Idle
#define PLAYER_ANIMATION_JUMP    Player::Animations::Jump
#define PLAYER_ANIMATION_RUN     Player::Animations::Run
#define PLAYER_ANIMATION_WALK    Player::Animations::Walk

class Player : public sf::Sprite
{
public:
    enum Direction
    {
        Left, Right
    };
    enum PlayerType
    {
        WoodCutter, GraveRobber, SteamMan
    };
    enum Animations
    {
        Attack1, Attack2, Attack3, Climb, Death, Hurt, Idle, Jump, Run, Walk
    };

private:
    Animations m_currentAnimation = PLAYER_ANIMATION_IDLE;
    Direction m_currentDirection = PLAYER_DIRECTION_RIGHT;
    PlayerType m_playerType;
    bool m_isRunning = false;
    sf::Clock m_clock;
    sf::IntRect m_playerRect;
    sf::Texture m_playerTexture;
    bool m_isIdle = true;

private:
    /**
     * Get the left end pos of the current sprite sheet
     * 
     * \return int
     */
    int getCurrentEndRect();

    /**
     * Get the sprite directory from the current player type
     * 
     * \return std::string
     */
    std::string getDirFromPlayerType();

    /**
     * Get file name from the player current player type
     * 
     * \return std::string
     */
    std::string getFileNameFromPlayerType();

    /**
     * Get animation file name from current animation
     * 
     * \return std::string
     */
    std::string getFileTypeFromAnimation();

public:
    /**
     * Create player object
     * 
     * \param PlayerType
     */
    Player(PlayerType);

    /**
     * Draw the player to screen
     * 
     * \param sf::RenderWindow&
     */
    void drawPlayer(sf::RenderWindow&);

    /**
     * Move player accross the screen
     * 
     * \param Direction
     */
    void movePlayer(Direction);

    /**
     * Update if the player is currently running
     * 
     * \param bool
     */
    void setIsRunning(bool b) { this->m_isRunning = b; }

    /**
     * Update player animation
     * 
     * \param Animations
     */
    void updatePlayerAnimation(Animations ani);

    /**
     * Get texture for current state
     * 
     * \param sf::Texture*
     * \return bool
     */
    bool getTexture(sf::Texture*);

    /**
     * Set the current state of the sprite
     * 
     * \param Animations
     */
    void setState(Animations ani) { this->m_currentAnimation = ani; }

    /**
     * Get the current state of the sprite
     * 
     * \return Animations
     */
    Animations getState() { return this->m_currentAnimation; }
};

#endif // !__PLAYER__