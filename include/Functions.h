#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Player.h>
#include <Projectile.h>
#include <Monster.h>

bool isCollide(Projectile p, Monster m)
{
    if(p.getRect().getGlobalBounds().intersects(m.getRect().getGlobalBounds()))
    {
        return true;
    }
    return false;
}

#endif //FUNCTIONS_H
