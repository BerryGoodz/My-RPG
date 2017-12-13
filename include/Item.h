#ifndef ITEM_H
#define ITEM_H

#include <Entity.h>
using namespace sf;

class Item
{
    public:
        Item();
        virtual ~Item();
        Sprite getSprite();
        void drop(const position& p, int monsterID);
        RectangleShape getRect();
        int getID();
        void setPosition(int x, int y);
        int getNumber();
        void addNumber(int n);

    private:
        RectangleShape rect;
        Sprite s_item;
        Texture t_item[10];
        int ID;
        int number = 1;
};

#endif // ITEM_H
