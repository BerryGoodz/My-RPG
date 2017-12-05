#include "Map.h"

Map::Map()
{

}

Map::~Map()
{
    //dtor
}

bool Map::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, Player& player, Monster& m, std::vector<Monster>& ma)
{
    if(!m_tileset.loadFromFile(tileset))
        return false;
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for(unsigned int i = 0; i < width; ++i)
    {
        for(unsigned int j = 0; j < height; ++j)
        {
            int tileNumber = tiles[i + j * width];

            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            quad = &m_vertices[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            if(tileNumber == -1)
            {
                m.setPosition(i * tileSize.x , j * tileSize.y);
                ma.push_back(m);
                mobN ++;
                totalMobN ++;
            }
            if(tileNumber == 2)
            {
                wallX.push_back(i * tileSize.x);
                wallY.push_back(j * tileSize.y);
                wallNumber++;
            }
            if(tileNumber == 48)
            {
                if(prevMap){player.locate(sf::Vector2f(i * tileSize.x - 50, j * tileSize.y - 50)); prevMap = false;}
                portalX.push_back(i * tileSize.x);
                portalY.push_back(j * tileSize.y);
                portalNumber++;
            }
            if(tileNumber == 49)
            {
                if(nextMap){player.locate(sf::Vector2f(i * tileSize.x - 50, j * tileSize.y - 50)); nextMap = false;}
                prevPortalX.push_back(i * tileSize.x);
                prevPortalY.push_back(j * tileSize.y);
                prevPortalNumber++;
            }
        }
    }
        return true;
}

void Map::resetMap(std::vector<Monster>& ma)
{
    m_vertices.clear();
    wallX.clear();
    wallY.clear();
    portalX.clear();
    portalY.clear();
    prevPortalX.clear();
    prevPortalY.clear();
    ma.clear();
    mobN = 0;
    totalMobN = 0;
}
bool Map::isEmpty()
{
    return wallX.empty();
}
void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices,states);
}
void Map::isCollide(Player& p, const entityNames& n)
{
float distToLeft;
float distToRight;
float distToTop;
float distToBottom;


    if(n.name == "wall")
    {
    for(int i = 0; i < wallX.size(); i ++)
    {
    distToLeft = (p.getPositionX()+40) - wallX[i];
    distToRight = (wallX[i]+55) - (p.getPositionX()+30);
    distToTop = (p.getPositionY()+58) - wallY[i];
    distToBottom = (wallY[i]+ 60) - (p.getPositionY()+48);
    if ( distToLeft > 0 && distToRight > 0 && distToTop > 0 && distToBottom > 0 )
    {

        if(distToLeft > distToRight && distToLeft > distToTop && distToLeft > distToBottom){p.wallCollide(1);}//get rid of these long if statements, define them somewhere else
        else if(distToRight > distToLeft && distToRight > distToTop && distToRight > distToBottom){p.wallCollide(2);}
        else if(distToTop > distToLeft && distToTop > distToRight && distToTop > distToBottom){p.wallCollide(3);}
        else if(distToBottom > distToLeft && distToBottom > distToTop && distToBottom > distToRight){p.wallCollide(4);}
    }
    }
    }
    if(n.name == "portal")
    {
     for(int i = 0; i < portalX.size(); i ++)
    {

    distToLeft = (p.getPositionX()+30) - portalX[i];
    distToRight = (portalX[i]+50) - (p.getPositionX()+30);
    distToTop = (p.getPositionY()+48) - portalY[i];
    distToBottom = (portalY[i]+ 50) - (p.getPositionY()+48);

     if ( distToLeft > 0 && distToRight > 0 && distToTop > 0 && distToBottom > 0 )
    {
        nextMap = true;
    }
    }
    }
    if(n.name == "prevportal")
    {
     for(int i = 0; i < prevPortalX.size(); i ++)
    {
    distToLeft = (p.getPositionX()+30) - prevPortalX[i];
    distToRight = (prevPortalX[i]+50) - (p.getPositionX()+30);
    distToTop = (p.getPositionY()+48) - prevPortalY[i];
    distToBottom = (prevPortalY[i]+ 50) - (p.getPositionY()+48);

     if ( distToLeft > 0 && distToRight > 0 && distToTop > 0 && distToBottom > 0 )
    {
        prevMap = true;
    }
    }
    }
}
void Map::monsterCollide(Monster& m)
{
    for(int i = 0; i < wallX.size(); i ++)
    {
    float distToLeft = (m.getPositionX()+40) - wallX[i];
    float distToRight = (wallX[i]+55) - (m.getPositionX()+10);
    float distToTop = (m.getPositionY()+38) - wallY[i];
    float distToBottom = (wallY[i]+ 70) - (m.getPositionY()+48);
    if ( distToLeft > 0 && distToRight > 0 && distToTop > 0 && distToBottom > 0 )
    {
        if(distToLeft > distToRight && distToLeft > distToTop && distToLeft > distToBottom){m.wallCollide(1);}
        else if(distToRight > distToLeft && distToRight > distToTop && distToRight > distToBottom){m.wallCollide(2);}
        else if(distToTop > distToLeft && distToTop > distToRight && distToTop > distToBottom){m.wallCollide(3);}
        else if(distToBottom > distToLeft && distToBottom > distToTop && distToBottom > distToRight){m.wallCollide(4);}
    }
    }
}


bool Map::onPortal()
{
    return nextMap;
}
bool Map::onPrevPortal()
{
    return prevMap;
}
void Map::monsterRespawn(Monster& m, std::vector<Monster>& ma)
{
    int chance = rand()%spawnRate;

    if(mobN < totalMobN && chance == 1)
    {
        int x = rand()%1000;
        int y = rand()%700;
        int totalWallTests =  wallY.size();

        for(int i = 0; i < wallX.size(); i ++)
        {

            if(x < wallX[i] - 20 || x > wallX[i] + 50 || y < wallY[i] - 20 || y > wallY[i] + 50)
                {
                    totalWallTests --;
                }

        }

        if(totalWallTests == 0)
        {
            m.setPosition(x,y);
            ma.push_back(m);
            mobN ++;
        }
    }
}
void Map::monsterDied()
{
    mobN --;
}
