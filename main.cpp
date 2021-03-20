#include "header/player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformer");

    Player player;

    while (window.isOpen())
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
                        case sf::Keyboard::A:
                        case sf::Keyboard::D:
                            player.setAnimation(PLAYER_ANIMATION_IDLE);
                            break;
                    }

                default:
                    break;
            }
        }

        // Player actions
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player.controlPlayer(PLAYER_ACTION_MOVE_LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player.controlPlayer(PLAYER_ACTION_MOVE_RIGHT);

        
        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
