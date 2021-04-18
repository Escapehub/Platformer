#include "enemy.h"

Enemy::Enemy(EnemyHelper::EnemyType et)
{
    this->m_enemyHelper = std::make_unique<EnemyHelper>(et);
    this->setOrigin(sf::Vector2f(48 / 2, 48 / 2));
    this->m_enemyRect = sf::IntRect(0, 0, 48, 48);
    this->setTextureRect(this->m_enemyRect);
    this->updateEnemyAnimation(ENEMY_ANIMATION_IDLE);
}

void Enemy::drawEnemy(sf::RenderWindow& window)
{
    // Set player direction
    switch (this->m_currentDirection)
    {
        case ENEMY_DIRECTION_RIGHT:
            this->setScale(sf::Vector2f(1, 1));
            break;

        case ENEMY_DIRECTION_LEFT:
            this->setScale(sf::Vector2f(-1, 1));
            break;
    }

    // Update player texture rect for animations
    if (this->m_clock.getElapsedTime().asSeconds() > 0.2)
    {
        if (this->m_enemyRect.left == 240)
            this->m_enemyRect.left = 0;
        else
            this->m_enemyRect.left += 48;

        this->setTextureRect(this->m_enemyRect);
        this->m_clock.restart();
    }

    // Drawing player sprite
    window.draw(*this);
}

void Enemy::moveEnemy(Direction direction)
{
    this->m_currentDirection = direction;
    
    this->updateEnemyAnimation(ENEMY_ANIMATION_WALK);
    switch (this->m_currentDirection)
    {
    case ENEMY_DIRECTION_RIGHT:
        this->move(ENEMY_MOVE_SPEED, 0);
        break;

    case ENEMY_DIRECTION_LEFT:
        this->move(-ENEMY_MOVE_SPEED, 0);
        break;
    }
}

void Enemy::updateEnemyAnimation(EnemyHelper::Animations ani)
{
    this->m_enemyHelper->setState(ani);
    // Set player texture
    this->m_enemyHelper->getTexture(&this->m_enemyTexture);
    this->setTexture(this->m_enemyTexture);
}