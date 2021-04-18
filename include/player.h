/*
    +---------------------------+
    |   Player handler          |
    +---------------------------+
    |   \file player.h          |
    |   \defines __PLAYER__     |
    |   \class Player           |
    |   \parent sf::Sprite      |
    +---------------------------+
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
#define PLAYER_SPEED_RUN  0.3

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player types
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_TYPE_WOODCUTTER  Player::PlayerType::WoodCutter
#define PLAYER_TYPE_GRAVEROBBER Player::PlayerType::GraveRobber
#define PLAYER_TYPE_STEAMMAN    Player::PlayerType::SteamMan

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Player states
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#define PLAYER_STATE_ATTACK1 Player::State::Attack1
#define PLAYER_STATE_ATTACK2 Player::State::Attack2
#define PLAYER_STATE_ATTACK3 Player::State::Attack3
#define PLAYER_STATE_CLIMB   Player::State::Climb
#define PLAYER_STATE_DEATH   Player::State::Death
#define PLAYER_STATE_HURT    Player::State::Hurt
#define PLAYER_STATE_IDLE    Player::State::Idle
#define PLAYER_STATE_JUMP    Player::State::Jump
#define PLAYER_STATE_RUN     Player::State::Run
#define PLAYER_STATE_WALK    Player::State::Walk

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
    enum State
    {
        Attack1, Attack2, Attack3, Climb, Death, Hurt, Idle, Jump, Run, Walk
    };

private:
    State m_currentState = PLAYER_STATE_IDLE;
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
     * Get animation file name from current state
     * 
     * \return std::string
     */
    std::string getFileTypeFromState();

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
     * Set the current state of the sprite
     * 
     * \param State
     */
    void setState(State state) { this->m_currentState = state; }

    /**
     * Get the current state of the sprite
     * 
     * \return State
     */
    State getState() { return this->m_currentState; }
};

#endif // !__PLAYER__