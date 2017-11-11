#ifndef TILE_H
#define TILE_H

#include <Entity.h>
//This class is dead
class Tile: public Entity
{
    public:
        Tile(const image& img, const image& img2, const image& img3, int tileNumbers[14][20]);
        virtual ~Tile();
        virtual Sprite getSprite();
        Sprite getTile(int whichTile);
        int getTileID(int lhs, int rhs);
        void setTilePosition(int x, int y, int whichTile);
        void setMap(int tileNumbers[14][20]);

    private:
        int tileID[14][20];
        Sprite s_tile[3];
        Texture t_tile[3];
};

#endif // TILE_H
