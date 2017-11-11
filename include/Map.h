#ifndef MAP_H
#define MAP_H
#include <Player.h>
#include <Entity.h>
class Map: public sf::Drawable, public sf::Transformable
{
    public:
        Map();
        virtual ~Map();
        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
        void resetMap();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void isCollide(Player& p, const entityNames& n);
        bool onPortal();

    private:
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        sf::Vertex* quad;
        float wallX [50];
        float wallY [50];
        float portalX [10];
        float portalY [10];


        bool nextMap = false;
        sf::Sprite s;
};

#endif // MAP_H
