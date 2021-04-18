#ifndef __USERINPUT__
#define __USERINPUT__

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// Includes
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
#include <SFML/Graphics.hpp>
#include "player.h"

void RegisterEvent(sf::RenderWindow& window, std::unique_ptr<Player>& player)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        switch (event.type)
        {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Right:
                    case sf::Keyboard::Left:
                        player->setState(PLAYER_STATE_IDLE);
                        break;

                    case sf::Keyboard::LShift:
                        player->setIsRunning(false);
                        break;

                    default:
                        break;
                }
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::LShift:
                        player->setIsRunning(true);
                    default:
                        break;

                    case sf::Keyboard::A:
                        player->setState(PLAYER_STATE_ATTACK1);
                        break;
                    case sf::Keyboard::S:
                        player->setState(PLAYER_STATE_ATTACK2);
                        break;
                    case sf::Keyboard::D:
                        player->setState(PLAYER_STATE_ATTACK3);
                        break;
                }
                break;

            default:
                break;
        }
    }

    // Player actions
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player->movePlayer(PLAYER_DIRECTION_RIGHT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->movePlayer(PLAYER_DIRECTION_LEFT);
}

#endif // !__USERINPUT__