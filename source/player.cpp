#include "../header/player.h"

Player::Player()
{
    this->setOrigin(sf::Vector2f(536 / 2, 495 / 2));
    this->setTextureRect(sf::IntRect(0, 0, 536, 495));
    this->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
}

void Player::controlPlayer(Action action)
{
    switch (action)
    {
        case PLAYER_ACTION_MOVE_RIGHT:
            this->setDirection(PLAYER_DIRECTION_RIGHT);
            this->setAnimation(PLAYER_ANIMATION_RUN);
            this->move(PLAYER_MOVE_SPEED, 0);
            break;

        case PLAYER_ACTION_MOVE_LEFT:
            this->setDirection(PLAYER_DIRECTION_LEFT);
            this->setAnimation(PLAYER_ANIMATION_RUN);
            this->move(-PLAYER_MOVE_SPEED, 0);
            break;

        case PLAYER_ACTION_JUMP:
            this->setAnimation(PLAYER_ANIMATION_JUMP);
            break;
        
        case PLAYER_ACTION_GLIDE:
            this->setAnimation(PLAYER_ANIMATION_GLIDE);
            break;

        case PLAYER_ACTION_SLIDE:
            this->setAnimation(PLAYER_ANIMATION_SLIDE);
            break;

        case PLAYER_ACTION_THROW:
            this->setAnimation(PLAYER_ANIMATION_THROW);
            break;

        case PLAYER_ACTION_JUMP_ATTACK:
            this->setAnimation(PLAYER_ANIMATION_JUMP_ATTACK);
            break;

        case PLAYER_ACTION_JUMP_THROW:
            this->setAnimation(PLAYER_ANIMATION_JUMP_THROW);
            break;
    }
}

void Player::draw(sf::RenderWindow& window)
{
    // Flipping the player direction
    if (this->m_currentDirection == PLAYER_DIRECTION_RIGHT)
        this->setScale(sf::Vector2f(PLAYER_SCALE, PLAYER_SCALE));
    else
        this->setScale(sf::Vector2f(-PLAYER_SCALE, PLAYER_SCALE));

    // Setting the sprite depending on action
    this->m_playerTexture.loadFromFile("sprites/player/" + this->m_animationNames[this->m_currentAnimation] + std::to_string(this->m_currentFrame) + ".png");
    this->setTexture(this->m_playerTexture);

    // Animating sprite
    if (this->m_clock.getElapsedTime().asSeconds() > 0.1)
    {
        this->m_currentFrame = (this->m_currentFrame + 1) % PLAYER_MAX_FRAME;

        this->m_clock.restart();
    }

    window.draw(*this);
}