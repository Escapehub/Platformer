#ifndef __PLAYERHELPER__
#define __PLAYERHELPER__

#include <SFML/Graphics.hpp>
#include <string>

#define PLAYER_TYPE_WOODCUTTER  PlayerHelper::PlayerType::WoodCutter
#define PLAYER_TYPE_GRAVEROBBER PlayerHelper::PlayerType::GraveRobber
#define PLAYER_TYPE_STEAMMAN    PlayerHelper::PlayerType::SteamMan

#define PLAYER_ANIMATION_ATTACK1 PlayerHelper::Animations::Attack1
#define PLAYER_ANIMATION_ATTACK2 PlayerHelper::Animations::Attack2
#define PLAYER_ANIMATION_ATTACK3 PlayerHelper::Animations::Attack3
#define PLAYER_ANIMATION_CLIMB   PlayerHelper::Animations::Climb
#define PLAYER_ANIMATION_DEATH   PlayerHelper::Animations::Death
#define PLAYER_ANIMATION_HURT    PlayerHelper::Animations::Hurt
#define PLAYER_ANIMATION_IDLE    PlayerHelper::Animations::Idle
#define PLAYER_ANIMATION_JUMP    PlayerHelper::Animations::Jump
#define PLAYER_ANIMATION_RUN     PlayerHelper::Animations::Run
#define PLAYER_ANIMATION_WALK    PlayerHelper::Animations::Walk

class PlayerHelper
{
public:
    enum PlayerType
    {
        WoodCutter,
        GraveRobber,
        SteamMan
    };
    enum Animations
    {
        Attack1,
        Attack2,
        Attack3,
        Climb,
        Death,
        Hurt,
        Idle,
        Jump,
        Run,
        Walk
    };

private:
    PlayerType m_playerType;
    Animations m_currentAnimation = PLAYER_ANIMATION_IDLE;

private:
    std::string getDirFromPlayerType();
    std::string getFileNameFromPlayerType();
    std::string getFileTypeFromAnimation();

public:
    PlayerHelper(PlayerType&);
    bool getTexture(sf::Texture*);
    void setState(Animations ani) { this->m_currentAnimation = ani; }
};

#endif // !__PLAYERHELPER__