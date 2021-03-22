#include "src/map/tilemap.h"
#include "src/player/player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformer");

    Player player;

    // define the level with an array of tile indices
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("assets/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
       return -1;

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

                        default:
                            break;
                    }
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Space:

                            break;
                            
                        default:
                            break;
                    }
                    break;

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
        window.draw(map);
        window.display();
    }

    return 0;
}
