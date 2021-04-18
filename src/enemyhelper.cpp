#include "enemyhelper.h"

EnemyHelper::EnemyHelper(EnemyHelper::EnemyType& pt)
{
    this->m_enemyType = pt;
}

bool EnemyHelper::getTexture(sf::Texture* texture)
{
    if (!texture->loadFromFile(this->getDirFromEnemyType() + this->getFileNameFromEnemyType() + this->getFileTypeFromAnimation()))
        return false;
    return true;
}

std::string EnemyHelper::getDirFromEnemyType()
{
    switch (this->m_enemyType)
    {
        case ENEMY_TYPE_DECEASED:
            return "assets/enemies/deceased/";
        
        case ENEMY_TYPE_HYENA:
            return "assets/enemies/hyena/";

        case ENEMY_TYPE_MUMMY:
            return "assets/enemies/mummy/";
        
        case ENEMY_TYPE_SCORPIO:
            return "assets/enemies/scorpio/";

        case ENEMY_TYPE_SNAKE:
            return "assets/enemies/snake/";

        case ENEMY_TYPE_VULTURE:
            return "assets/enemies/vulture/";

        default:
            return "";
    }
}

std::string EnemyHelper::getFileNameFromEnemyType()
{
    switch (this->m_enemyType)
    {
        case ENEMY_TYPE_DECEASED:
            return "Deceased_";
        
        case ENEMY_TYPE_HYENA:
            return "Hyena_";

        case ENEMY_TYPE_MUMMY:
            return "Mummy_";
        
        case ENEMY_TYPE_SCORPIO:
            return "Scorpio_";

        case ENEMY_TYPE_SNAKE:
            return "Snake_";

        case ENEMY_TYPE_VULTURE:
            return "Vulture_";

        default:
            return "";
    }
}

std::string EnemyHelper::getFileTypeFromAnimation()
{
    switch (this->m_currentAnimation)
    {
        case ENEMY_ANIMATION_ATTACK:
            return "attack.png";

        case ENEMY_ANIMATION_DEATH:
            return "death.png";

        case ENEMY_ANIMATION_HURT:
            return "hurt.png";

        case ENEMY_ANIMATION_IDLE:
            return "idle.png";

        case ENEMY_ANIMATION_WALK:
            return "walk.png";

        default:
            return "";
    }
}