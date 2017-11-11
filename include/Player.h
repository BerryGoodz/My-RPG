#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>

class Player: public Entity
{
    public:
        Player(const image& img, const setRect& sr, const position& p);

        virtual ~Player();
        virtual Sprite getSprite()
        {
            return s_player;
        }
        void frameRun();
        void randomPosition();
        float getPositionX();
        float getPositionY();
        void wallCollide(int dir);

    private:
        Texture t_player;
        Sprite s_player;


        int imgSizeX;
        int imgSizeY;
        int i = 0;
        int tick = 0;
};

#endif // PLAYER_H
