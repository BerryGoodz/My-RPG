#include "Map.h"

Map::Map()
{

}

Map::~Map()
{
    //dtor
}
int wallNumber = 0;
int portalNumber = 0;

bool Map::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
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

            if(tileNumber == 2)
            {
                wallX[wallNumber] = i * tileSize.x;
                wallY[wallNumber] = j * tileSize.y;
                wallNumber++;
            }
            if(tileNumber == 3)
            {
                portalX[portalNumber] = i * tileSize.x;
                portalY[portalNumber] = j * tileSize.y;
                portalNumber++;
            }
        }
    }
        return true;

}
void Map::resetMap()
{
    m_vertices.clear();
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
nextMap = false;
    if(n.name == "wall")
    {
    for(int i = 0; i < 50; i ++)
    {
    distToLeft = (p.getPositionX()+30) - wallX[i];
    distToRight = (wallX[i]+50) - (p.getPositionX()+30);
    distToTop = (p.getPositionY()+48) - wallY[i];
    distToBottom = (wallY[i]+ 50) - (p.getPositionY()+48);
    if ( distToLeft > 0 && distToRight > 0 && distToTop > 0 && distToBottom > 0 )
    {
        if(distToLeft > distToRight && distToLeft > distToTop && distToLeft > distToBottom){p.wallCollide(1);}
        else if(distToRight > distToLeft && distToRight > distToTop && distToRight > distToBottom){p.wallCollide(2);}
        else if(distToTop > distToLeft && distToTop > distToRight && distToTop > distToBottom){p.wallCollide(3);}
        else if(distToBottom > distToLeft && distToBottom > distToTop && distToBottom > distToRight){p.wallCollide(4);}

    }
    }
    }

    if(n.name == "portal")
    {
     for(int i = 0; i < 10; i ++)
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
}
bool Map::onPortal()
{
    return nextMap;
}
