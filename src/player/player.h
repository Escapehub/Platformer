#ifndef __PLAYER__
#define __PLAYER__

#include <SFML/Graphics.hpp>

#define PLAYER_ANIMATION_ATTACK 0
#define PLAYER_ANIMATION_CLIMB 1
#define PLAYER_ANIMATION_DEAD 2
#define PLAYER_ANIMATION_GLIDE 3
#define PLAYER_ANIMATION_IDLE 4
#define PLAYER_ANIMATION_JUMP 5
#define PLAYER_ANIMATION_JUMP_ATTACK 6
#define PLAYER_ANIMATION_JUMP_THROW 7
#define PLAYER_ANIMATION_RUN 8
#define PLAYER_ANIMATION_SLIDE 9
#define PLAYER_ANIMATION_THROW 10

#define PLAYER_MAX_FRAME 10
#define PLAYER_MOVE_SPEED 0.5
#define PLAYER_SCALE 0.15f

#define PLAYER_ACTION_MOVE_RIGHT Player::Action::MoveRight
#define PLAYER_ACTION_MOVE_LEFT Player::Action::MoveLeft
#define PLAYER_ACTION_JUMP Player::Action::Jump
#define PLAYER_ACTION_GLIDE Player::Action::Glide
#define PLAYER_ACTION_SLIDE Player::Action::Slide
#define PLAYER_ACTION_THROW Player::Action::Throw
#define PLAYER_ACTION_JUMP_ATTACK Player::Action::JumpAttack
#define PLAYER_ACTION_JUMP_THROW Player::Action::JumpThrow

#define PLAYER_DIRECTION_LEFT 0
#define PLAYER_DIRECTION_RIGHT 1

class Player : public sf::Sprite
{
public:
    enum Action 
    { 
        MoveRight = 0, 
        MoveLeft = 1, 
        Jump = 2,
        Glide = 3,
        Slide = 4,
        Throw = 5,
        JumpAttack = 6,
        JumpThrow = 7
    };

private:
    const std::string m_animationNames[11] = // 536 x 495
    {
        "Attack__00", 
        "Climb_00", 
        "Dead__00", 
        "Glide_00", 
        "Idle__00", 
        "Jump__00", 
        "Jump_Attack__00", 
        "Jump_Throw__00", 
        "Run__00", 
        "Slide__00", 
        "Throw__00"
    };

    int m_currentDirection = PLAYER_DIRECTION_RIGHT;
    int m_currentAnimation = PLAYER_ANIMATION_IDLE;
    int m_currentFrame = 0;
    sf::Clock m_clock;
    sf::Texture m_playerTexture;

public:
    Player();
    void controlPlayer(Action);
    void draw(sf::RenderWindow&);
    void setAnimation(int ani) { this->m_currentAnimation = ani; }

private:
    void setDirection(int direction) { this->m_currentDirection = direction;}
};

#endif // !__PLAYER__