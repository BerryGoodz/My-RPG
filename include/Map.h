#ifndef MAP_H
#define MAP_H
#include <Player.h>
#include <Entity.h>
#include <Monster.h>
class Map: public sf::Drawable, public sf::Transformable
{
    public:
        Map();
        virtual ~Map();
        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, Player& player, Monster& m, std::vector<Monster>& ma);
        void resetMap(std::vector<Monster>& ma);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void isCollide(Player& p, const entityNames& n);
        bool onPortal();
        bool onPrevPortal();
        bool isEmpty();
        void monsterCollide(Monster& m);

    private:
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        sf::Vertex* quad;
        std::vector<float> wallX;
        std::vector<float> wallY;
        std::vector<float> portalX;
        std::vector<float> portalY;
        std::vector<float> prevPortalX;
        std::vector<float> prevPortalY;

        int wallNumber = 0;
        int portalNumber = 0;
        int prevPortalNumber = 0;
        bool nextMap = false;
        bool prevMap = false;

};

#endif // MAP_H
