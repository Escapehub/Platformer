#include "src/player/player.h"
#include "src/helpers/helpers.hpp"
#include "src/levelgen/levelgen.h"

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
        RegisterEvent(window, player);
        
        window.clear();
        window.draw(map);
        player->drawPlayer(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
