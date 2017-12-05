#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include <structs.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <sstream>

using namespace sf;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual Sprite getSprite()=0;
    protected:

    private:

};

#endif // ENTITY_H
