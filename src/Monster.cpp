#include "Monster.h"

Monster::Monster(const image& img, const setRect& sr, const position& p)
{
    t_monster.loadFromFile(img.imgName);

    s_monster.setTexture(t_monster);

    s_monster.setTextureRect(IntRect(sr.x, sr.y, sr.rectX, sr.rectY));

    s_monster.setPosition(p.x1,p.y1);


    imgSizeX = sr.rectX;
    imgSizeY = sr.rectY;

    rect.setSize(Vector2f(imgSizeX/2,imgSizeY/2));


}

Monster::~Monster()
{
    //dtor
}
Sprite Monster::getSprite()
{
    return s_monster;
}
void Monster::setPosition(float x, float y)
{
    s_monster.setPosition(x,y);
}
float Monster::getPositionX()
{
    return s_monster.getPosition().x;
}
float Monster::getPositionY()
{
    return s_monster.getPosition().y;
}
sf::RectangleShape Monster::getRect()
{
    return rect;
}

void Monster::frameRun()
{
    tick++;

    rect.setPosition(s_monster.getPosition().x+10, s_monster.getPosition().y+10);
    s_monster.setTextureRect(IntRect(0, randomN * imgSizeY, imgSizeX, imgSizeY));
    if(tick>30&&i>1){i = 0; tick = 0;}
    if(tick>30){i++; tick = 0;}
    if(randomN == 1)
    {
        s_monster.move(speed,0);
        s_monster.setTextureRect(IntRect(i * imgSizeX, 2 * imgSizeY, imgSizeX, imgSizeY));
    }
    else if(randomN == 2)
    {
        s_monster.move(-speed,0);
        s_monster.setTextureRect(IntRect(i * imgSizeX, 1 * imgSizeY, imgSizeX, imgSizeY));
    }
    else if(randomN == 3)
    {
        s_monster.move(0,speed);
        s_monster.setTextureRect(IntRect(i * imgSizeX, 0 * imgSizeY, imgSizeX, imgSizeY));
    }
    else if(randomN == 4)
    {
        s_monster.move(0,-speed);
        s_monster.setTextureRect(IntRect(i * imgSizeX, 3 * imgSizeY, imgSizeX, imgSizeY));
    }
    else if(randomN == 5)
    {
        s_monster.setTextureRect(IntRect(1 * imgSizeX, 3 * imgSizeY, imgSizeX, imgSizeY));
    }
    delay++;
    if(delay == 100)
    {randomN = rand()%5+1;delay = 0;}
}
void Monster::wallCollide(int dir)
{
    if(dir == 1) s_monster.move(speed,0);
    if(dir == 2) s_monster.move(-speed,0);
    if(dir == 3) s_monster.move(0,speed);
    if(dir == 4) s_monster.move(0,-speed);
}
void Monster::takeDamage(int damage)
{
    hp -= damage;
}
int Monster::getHp()
{
    return hp;
}
