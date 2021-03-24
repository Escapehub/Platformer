#include "src/levelgen/levelgen.h"
#include "src/player/player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Platformer");

    std::unique_ptr<Player> player = std::make_unique<Player>();

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
                        case sf::Keyboard::A:
                        case sf::Keyboard::D:
                            //player->setAnimation(PLAYER_ANIMATION_IDLE);
                            player->controlPlayer(PLAYER_ACTION_IDLE);
                            break;

                        default:
                            break;
                    }
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Space:
                            player->controlPlayer(PLAYER_ACTION_JUMP);
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
            player->controlPlayer(PLAYER_ACTION_MOVE_LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player->controlPlayer(PLAYER_ACTION_MOVE_RIGHT);
        
        window.clear();
        window.draw(map);
        player->draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
