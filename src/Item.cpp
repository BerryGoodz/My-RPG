#include "Item.h"

Item::Item()
{
    /*t_item.loadFromFile(img.imgName);

    s_item.setTexture(t_item);

    s_item.setTextureRect(IntRect(sr.x, sr.y, sr.rectX, sr.rectY));*/
}

Item::~Item()
{
    //dtor
}

Sprite Item::getSprite()
{
    return s_item;
}
RectangleShape Item::getRect()
{
    return rect;
}
void Item::drop(const position& p, int monsterID)
{
    ID = monsterID;
    if(monsterID == 1)
    {
    t_item[0].loadFromFile("coin.png");

    s_item.setTexture(t_item[0]);

    s_item.setScale(0.5, 0.5);
    s_item.setTextureRect(IntRect(0,0,32,32));

    rect.setSize(Vector2f(16,16));
    rect.setPosition(p.x1 + 20, p.y1 + 20);
    s_item.setPosition(p.x1 + 20, p.y1 + 20);
    }
    if(monsterID == 2)
    {
    t_item[1].loadFromFile("items.png");

    s_item.setTexture(t_item[1]);

    s_item.setTextureRect(IntRect(0,0,32,32));
    s_item.setScale(0.5, 0.5);

    rect.setSize(Vector2f(16,16));
    rect.setPosition(p.x1 + 20, p.y1 + 20);
    s_item.setPosition(p.x1 + 20, p.y1 + 20);
    }
}
int Item::getID()
{
    return ID;
}
void Item::setPosition(int x, int y)
{
    s_item.setPosition(x, y);
}
int Item::getNumber()
{
    return number;
}
void Item::addNumber(int n)
{
    number += n;
}
