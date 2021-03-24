#include "player.h"

Player::Player()
{
    this->setOrigin(sf::Vector2f(536 / 2, 495 / 2));
    this->setTextureRect(sf::IntRect(0, 0, 536, 495));
    this->setPosition(sf::Vector2f(500, 500));
}

void Player::controlPlayer(Action action)
{
    switch (action)
    {
        case PLAYER_ACTION_MOVE_RIGHT:
            this->setDirection(PLAYER_DIRECTION_RIGHT);
            this->setAnimation(PLAYER_ANIMATION_RUN);
            //this->move(PLAYER_MOVE_SPEED, 0);
            this->m_velocityX = 2;
            break;

        case PLAYER_ACTION_MOVE_LEFT:
            this->setDirection(PLAYER_DIRECTION_LEFT);
            this->setAnimation(PLAYER_ANIMATION_RUN);
            //this->move(-PLAYER_MOVE_SPEED, 0);
            this->m_velocityX = -2;
            break;

        case PLAYER_ACTION_JUMP:
            this->m_velocityY = -4;
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

        case PLAYER_ACTION_IDLE:
            this->setAnimation(PLAYER_ANIMATION_IDLE);
            this->m_velocityY = 0;
            this->m_velocityX = 0;
            break;
    }
}

void Player::draw(sf::RenderWindow& window)
{
    // Setting player direction
    switch (this->m_currentDirection)
    {
        case PLAYER_DIRECTION_RIGHT:
            this->setScale(sf::Vector2f(PLAYER_SCALE, PLAYER_SCALE));
            break;

        case PLAYER_DIRECTION_LEFT:
            this->setScale(sf::Vector2f(-PLAYER_SCALE, PLAYER_SCALE));
            break;
    }

    // Setting if player is currently jumping
    if (this->getPosition().y > this->m_playerLevelDefaultElevation)
        this->m_isJumping = true;
    else 
        this->m_isJumping = false;

    // Setting the sprite depending on action
    this->m_playerTexture.loadFromFile("assets/player/" + this->m_animationNames[this->m_currentAnimation] + std::to_string(this->m_currentFrame) + ".png");
    this->setTexture(this->m_playerTexture);

    // Animating sprite
    if (this->m_clock.getElapsedTime().asSeconds() > 0.1)
    {
        this->m_currentFrame = (this->m_currentFrame + 1) % PLAYER_MAX_FRAME;

        this->m_clock.restart();
    }

    this->updateMovement();
    this->setPosition(this->m_positionX, this->m_positionY);

    window.clear();
    window.draw(*this);
}

void Player::updateMovement() {

    if(m_positionY < 500)                  // If you are above ground
        m_positionY += m_gravity;          // Add gravity
    else if(m_positionY > 500)             // If you are below ground
        m_positionY = 500;                 // That's not supposed to happen, put him back up

    m_velocityX += m_accelerationX;
    m_velocityY += m_accelerationY;

    m_positionX += m_velocityX;
    m_positionY += m_velocityY;
}