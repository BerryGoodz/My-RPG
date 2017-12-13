#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Player.h>
#include <Projectile.h>
#include <Monster.h>
template <class A, class B>
bool isCollide(A p, B m)
{
    if(p.getRect().getGlobalBounds().intersects(m.getRect().getGlobalBounds()))
    {
        return true;
    }
    return false;
}


#endif //FUNCTIONS_H
