#ifndef __ENEMYHELPER__
#define __ENEMYHELPER__

#include <SFML/Graphics.hpp>

#define ENEMY_TYPE_SNAKE    EnemyHelper::EnemyType::Snake
#define ENEMY_TYPE_HYENA    EnemyHelper::EnemyType::Hyena
#define ENEMY_TYPE_SCORPIO  EnemyHelper::EnemyType::Scorpio
#define ENEMY_TYPE_VULTURE  EnemyHelper::EnemyType::Vulture
#define ENEMY_TYPE_MUMMY    EnemyHelper::EnemyType::Mummy
#define ENEMY_TYPE_DECEASED EnemyHelper::EnemyType::Deceased

#define ENEMY_ANIMATION_ATTACK  EnemyHelper::Animations::Attack
#define ENEMY_ANIMATION_DEATH   EnemyHelper::Animations::Death
#define ENEMY_ANIMATION_HURT    EnemyHelper::Animations::Hurt
#define ENEMY_ANIMATION_IDLE    EnemyHelper::Animations::Idle
#define ENEMY_ANIMATION_WALK    EnemyHelper::Animations::Walk

class EnemyHelper
{
public:
    enum EnemyType
    {
        Snake,
        Hyena,
        Scorpio,
        Vulture,
        Mummy,
        Deceased
    };
    enum Animations
    {
        Attack,
        Death,
        Hurt,
        Idle,
        Walk
    };

private:
    EnemyType m_enemyType;
    Animations m_currentAnimation;

private:
    std::string getDirFromEnemyType();
    std::string getFileNameFromEnemyType();
    std::string getFileTypeFromAnimation();

public:
    EnemyHelper(EnemyType&);
    bool getTexture(sf::Texture*);
    void setState(Animations ani) { this->m_currentAnimation = ani; }
    Animations getState() { return this->m_currentAnimation; }
};

#endif