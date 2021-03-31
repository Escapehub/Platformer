#ifndef __PLAYER__
#define __PLAYER__

#include "../playerhelper/playerhelper.h"

#define PLAYER_DIRECTION_RIGHT Player::Direction::Right
#define PLAYER_DIRECTION_LEFT  Player::Direction::Left

#define PLAYER_SPEED_WALK 0.2
#define PLAYER_SPEED_RUN  0.5

class Player : public sf::Sprite
{
public:
    enum Direction
    {
        Left, Right
    };

private:
    std::unique_ptr<PlayerHelper> m_playerHelper;
    Direction m_currentDirection = PLAYER_DIRECTION_RIGHT;
    bool m_isRunning = false;
    sf::Clock m_clock;
    sf::IntRect m_playerRect;
    sf::Texture m_playerTexture;

public:
    Player(PlayerHelper::PlayerType);
    void drawPlayer(sf::RenderWindow&);

    std::unique_ptr<PlayerHelper>& getPlayerHelper() { return this->m_playerHelper; }

    void movePlayer(Direction);
    void setIsRunning(bool b) { this->m_isRunning = b; }
};

#endif // !__PLAYER__