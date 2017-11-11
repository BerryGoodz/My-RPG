#include "Tile.h"
//This header is dead
Tile::Tile(const image& img, const image& img2, const image& img3, int tileNumbers[14][20])
{
    for(int i = 0; i < 3; i++)
    {
    t_tile[i].loadFromFile(img.imgName);
    s_tile[i].setTexture(t_tile[i]);
    }
    s_tile[0].setTextureRect(IntRect(0,0,50,50));
    s_tile[1].setTextureRect(IntRect(50,0,50,50));
    s_tile[2].setTextureRect(IntRect(0,50,50,50));
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            tileID[i][j] = tileNumbers[i][j];
        }
    }

}

Tile::~Tile()
{
    //dtor
}
Sprite Tile::getSprite()
{

}
Sprite Tile::getTile(int whichTile)
{
    return s_tile[whichTile];
}
int Tile::getTileID(int lhs, int rhs)
{
    return tileID[lhs][rhs];
}
void Tile::setTilePosition(int x, int y, int whichTile)
{
    s_tile[whichTile].setPosition(x*50,y*50);
}
void Tile::setMap(int tileNumbers[14][20])
{
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            tileID[i][j] = tileNumbers[i][j];
        }
    }
}
