#include "Projectile.h"

Projectile::Projectile(const image& img, const setRect& sr, const position& p)
{
    t_projectile.loadFromFile(img.imgName);

    s_projectile.setTexture(t_projectile);

    s_projectile.setTextureRect(IntRect(sr.x, sr.y, sr.rectX, sr.rectY));

    s_projectile.setPosition(p.x1,p.y1);

    rect.setSize(Vector2f(50,50));
    rect.setPosition(p.x1, p.y1);
}

Projectile::~Projectile()
{
    //dtor
}
Sprite Projectile::getSprite()
{
    return s_projectile;
}
void Projectile::update(float x, float y, float angle, int d)
{
    s_projectile.setPosition(x,y);
    s_projectile.setRotation(angle);
    dir = d;
}
void Projectile::frameRun()
{
    rect.setPosition(s_projectile.getPosition().x, s_projectile.getPosition().y);
    lifeTime--;
    if(dir==0){   s_projectile.move(0,speed);}
    if(dir==1){s_projectile.move(-speed,0);}
    if(dir==2){s_projectile.move(speed,0);}
    if(dir==3){s_projectile.move(0,-speed);}
}
int Projectile::getLifeTime()
{
    return lifeTime;
}
sf::RectangleShape Projectile::getRect()
{
    return rect;
}
