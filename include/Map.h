#ifndef MAP_H
#define MAP_H
#include <Player.h>
#include <Entity.h>
#include <Monster.h>
#include <Levels.h>
#include <Projectile.h>
#include <Monster.h>
#include <Damage.h>
#include <Timer.h>
#include <screenManager.h>
#include <Button.h>
#include <Interface.h>

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
        void monsterRespawn(Monster& m, std::vector<Monster>& ma);
        void monsterDied();

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
        int mobN = 0;
        int totalMobN = 0;
        int spawnRate = 100;// higher the number, less the monster spawns

};

#endif // MAP_H
