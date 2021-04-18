#ifndef __LEVELGEN__
#define __LEVELGEN__

#include <SFML/Graphics.hpp>

class LevelGen : public sf::Drawable, public sf::Transformable
{
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

public:
    bool load(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // !__LEVELGEN__