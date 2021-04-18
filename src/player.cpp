#include "player.h"

Player::Player(PlayerType playerType)
{
    this->m_playerType = playerType;
    this->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
    this->setOrigin(sf::Vector2f(48 / 2, 48 / 2));
    this->m_playerRect = sf::IntRect(0, 0, 48, 48);
    this->setTextureRect(this->m_playerRect);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
    // Set player texture
    this->m_playerTexture.loadFromFile("assets/player/" + this->getDirFromPlayerType() + this->getFileNameFromPlayerType() + this->getFileTypeFromState());
    this->setTexture(this->m_playerTexture);

    // Set player direction
    switch (this->m_currentDirection)
    {
        case PLAYER_DIRECTION_RIGHT:
            this->setScale(sf::Vector2f(1, 1));
            break;

        case PLAYER_DIRECTION_LEFT:
            this->setScale(sf::Vector2f(-1, 1));
            break;
    }

    // Update player texture rect for animations
    if (this->m_clock.getElapsedTime().asSeconds() > 0.2)
    {
        if (this->m_playerRect.left == this->getCurrentEndRect())
        {
            this->m_playerRect.left = 0;
            this->setState(PLAYER_STATE_IDLE);
        }
        else
            this->m_playerRect.left += 48;

        this->setTextureRect(this->m_playerRect);
        this->m_clock.restart();
    }

    // Drawing player sprite
    window.draw(*this);
}

void Player::movePlayer(Direction direction)
{
    this->m_currentDirection = direction;
    switch (this->m_isRunning)
    {
        case true:
            this->setState(PLAYER_STATE_RUN);
            switch (this->m_currentDirection)
            {
            case PLAYER_DIRECTION_RIGHT:
                this->move(PLAYER_SPEED_RUN, 0);
                break;

            case PLAYER_DIRECTION_LEFT:
                this->move(-PLAYER_SPEED_RUN, 0);
                break;
            }
            break;

        case false:
            this->setState(PLAYER_STATE_WALK);
            switch (this->m_currentDirection)
            {
            case PLAYER_DIRECTION_RIGHT:
                this->move(PLAYER_SPEED_WALK, 0);
                break;

            case PLAYER_DIRECTION_LEFT:
                this->move(-PLAYER_SPEED_WALK, 0);
                break;
            }
            break;
    }
}

int Player::getCurrentEndRect()
{
    switch (this->getState())
    {
        case PLAYER_STATE_ATTACK1:
        case PLAYER_STATE_ATTACK2:
        case PLAYER_STATE_ATTACK3:
        case PLAYER_STATE_RUN:
        case PLAYER_STATE_WALK:
            return 240;

        case PLAYER_STATE_IDLE:
            return 144;
        
        default:
            return 240;
    }
}

std::string Player::getDirFromPlayerType()
{
    switch (this->m_playerType)
    {
        case PLAYER_TYPE_GRAVEROBBER:
            return "graverobber/";
        
        case PLAYER_TYPE_STEAMMAN:
            return "steamman/";

        case PLAYER_TYPE_WOODCUTTER:
            return "woodcutter/";

        default:
            return "";
    }
}

std::string Player::getFileNameFromPlayerType()
{
    switch (this->m_playerType)
    {
        case PLAYER_TYPE_GRAVEROBBER:
            return "GraveRobber_";
        
        case PLAYER_TYPE_STEAMMAN:
            return "SteamMan_";

        case PLAYER_TYPE_WOODCUTTER:
            return "Woodcutter_";

        default:
            return "";
    }
}

std::string Player::getFileTypeFromState()
{
    switch (this->m_currentState)
    {
        case PLAYER_STATE_ATTACK1:
            return "attack1.png";

        case PLAYER_STATE_ATTACK2:
            return "attack2.png";

        case PLAYER_STATE_ATTACK3:
            return "attack3.png";

        case PLAYER_STATE_CLIMB:
            return "climb.png";

        case PLAYER_STATE_DEATH:
            return "death.png";

        case PLAYER_STATE_HURT:
            return "hurt.png";

        case PLAYER_STATE_IDLE:
            return "idle.png";

        case PLAYER_STATE_JUMP:
            return "jump.png";

        case PLAYER_STATE_RUN:
            return "run.png";

        case PLAYER_STATE_WALK:
            return "walk.png";

        default:
            return "";
    }
}