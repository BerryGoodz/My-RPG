#ifndef MONSTER_H
#define MONSTER_H

#include <Entity.h>
using namespace sf;
class Monster
{
    public:
        Monster(const image& img, const setRect& sr, const position& p, const health& he, const eva& av, const ID& monsterID);
        virtual ~Monster();
        virtual Sprite getSprite();
        void setPosition(float x, float y);
        void frameRun();
        float getPositionX();
        float getPositionY();
        void wallCollide(int dir);
        void takeDamage(int damage);
        int getHp();
        int getID();
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
        int hp;
        int avoid;
        int m_ID;
};

#endif // MONSTER_H
