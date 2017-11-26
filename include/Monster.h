#ifndef MONSTER_H
#define MONSTER_H

#include <Entity.h>

class Monster
{
    public:
        Monster(const image& img, const setRect& sr, const position& p);
        virtual ~Monster();
        virtual Sprite getSprite();
        void setPosition(float x, float y);
        void frameRun();
        float getPositionX();
        float getPositionY();
        void wallCollide(int dir);
        RectangleShape getRect();
    private:
        Sprite s_monster;
        Texture t_monster;
        int imgSizeX;
        int imgSizeY;
        float speed = 0.5;
        int delay = 0;
        int randomN = 0;
        int tick = 0;
        int i = 0;
        sf::RectangleShape rect;
};

#endif // MONSTER_H
