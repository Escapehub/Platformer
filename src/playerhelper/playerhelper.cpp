#include "playerhelper.h"

PlayerHelper::PlayerHelper(PlayerHelper::PlayerType& pt)
{
    this->m_playerType = pt;
}

bool PlayerHelper::getTexture(sf::Texture* texture)
{
    if (!texture->loadFromFile(this->getDirFromPlayerType() + this->getFileNameFromPlayerType() + this->getFileTypeFromAnimation()))
        return false;
    return true;
}

std::string PlayerHelper::getDirFromPlayerType()
{
    switch (this->m_playerType)
    {
        case PLAYER_TYPE_GRAVEROBBER:
            return "assets/player/graverobber/";
        
        case PLAYER_TYPE_STEAMMAN:
            return "assets/player/steamman/";

        case PLAYER_TYPE_WOODCUTTER:
            return "assets/player/woodcutter/";

        default:
            return "";
    }
}

std::string PlayerHelper::getFileNameFromPlayerType()
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

std::string PlayerHelper::getFileTypeFromAnimation()
{
    switch (this->m_currentAnimation)
    {
        case PLAYER_ANIMATION_ATTACK1:
            return "attack1.png";

        case PLAYER_ANIMATION_ATTACK2:
            return "attack2.png";

        case PLAYER_ANIMATION_ATTACK3:
            return "attack3.png";

        case PLAYER_ANIMATION_CLIMB:
            return "climb.png";

        case PLAYER_ANIMATION_DEATH:
            return "death.png";

        case PLAYER_ANIMATION_HURT:
            return "hurt.png";

        case PLAYER_ANIMATION_IDLE:
            return "idle.png";

        case PLAYER_ANIMATION_JUMP:
            return "jump.png";

        case PLAYER_ANIMATION_RUN:
            return "run.png";

        case PLAYER_ANIMATION_WALK:
            return "walk.png";

        default:
            return "";
    }
}