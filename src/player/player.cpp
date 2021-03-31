#include "player.h"

Player::Player(PlayerHelper::PlayerType playerType)
{
    this->m_playerHelper = std::make_unique<PlayerHelper>(playerType);
    this->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
    this->setOrigin(sf::Vector2f(48 / 2, 48 / 2));
    this->m_playerRect = sf::IntRect(0, 0, 48, 48);
    this->setTextureRect(this->m_playerRect);
    this->updatePlayerAnimation(PLAYER_ANIMATION_IDLE);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
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
            this->m_playerRect.left = 0;
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
            this->updatePlayerAnimation(PLAYER_ANIMATION_RUN);
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
            this->updatePlayerAnimation(PLAYER_ANIMATION_WALK);
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

void Player::updatePlayerAnimation(PlayerHelper::Animations ani)
{
    this->m_playerHelper->setState(ani);
    // Set player texture
    this->m_playerHelper->getTexture(&this->m_playerTexture);
    this->setTexture(this->m_playerTexture);
}

int Player::getCurrentEndRect()
{
    switch (this->m_playerHelper->getState())
    {
        case PLAYER_ANIMATION_ATTACK1:
        case PLAYER_ANIMATION_ATTACK2:
        case PLAYER_ANIMATION_ATTACK3:
        case PLAYER_ANIMATION_RUN:
        case PLAYER_ANIMATION_WALK:
            return 240;

        case PLAYER_ANIMATION_IDLE:
            return 144;
        
        default:
            return 240;
    }
}