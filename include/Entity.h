#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <structs.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <Functions.h>
#include <Projectile.h>

using namespace sf;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual Sprite getSprite()=0;
        
        
    protected:
    
    getHp();
    getRect();
    private:
    RectangleShape rect;
    int strength;
    int defense;
    float speed;
    int hp;
    

};

#endif // ENTITY_H
