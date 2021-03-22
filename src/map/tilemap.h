#ifndef __TILEMAP__
#define __TILEMAP__

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

public:
    bool load(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // !__TILEMAP__