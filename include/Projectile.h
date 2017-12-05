#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <Entity.h>
class Projectile
{
    public:
        Projectile(const image& img, const setRect& sr, const position& p);
        virtual ~Projectile();
        sf::Sprite getSprite();
        void update(float x, float y, float angle, int d);
        void frameRun();
        int getLifeTime();
        sf::RectangleShape getRect();


    private:
        float speed = 2;
        sf::Sprite s_projectile;
        sf::Texture t_projectile;
        int lifeTime = 40;
        int dir = 0;
        sf::RectangleShape rect;
};

#endif // PROJECTILE_H
