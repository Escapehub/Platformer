#include "src/levelgen/levelgen.h"
#include "src/player/player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformer");

    std::unique_ptr<Player> player = std::make_unique<Player>(PLAYER_TYPE_WOODCUTTER);

    // define the level with an array of tile indices
    const int level[] =
    {
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
        3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5,
    };

    // create the tilemap from the level definition
    LevelGen map;
    if (!map.load("assets/level/tileset.png", sf::Vector2u(128, 128), level, 16, 8))
        return EXIT_FAILURE;

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
                        case sf::Keyboard::Right:
                        case sf::Keyboard::Left:
                            player->updatePlayerAnimation(PLAYER_ANIMATION_IDLE);
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
        
        window.clear();
        window.draw(map);
        player->drawPlayer(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
