#ifndef __ENEMY__
#define __ENEMY__

#include "enemyhelper.h"

#define ENEMY_DIRECTION_LEFT    Enemy::Direction::Left
#define ENEMY_DIRECTION_RIGHT   Enemy::Direction::Right

#define ENEMY_MOVE_SPEED  0.2

class Enemy : public sf::Sprite
{
public:
    enum Direction
    {
        Left, Right
    };

private:
    std::unique_ptr<EnemyHelper> m_enemyHelper;
    Direction m_currentDirection = ENEMY_DIRECTION_LEFT;
    sf::Clock m_clock;
    sf::IntRect m_enemyRect;
    sf::Texture m_enemyTexture;

private:
    int getCurrentEndRect();

public:
    Enemy(EnemyHelper::EnemyType);
    void drawEnemy(sf::RenderWindow&);

    void moveEnemy(Direction);

    void updateEnemyAnimation(EnemyHelper::Animations ani);
};

#endif // !__ENEMY__