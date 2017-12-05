#ifndef DAMAGE_H
#define DAMAGE_H

#include <Entity.h>
using namespace sf;

class Damage
{
    public:
        Damage(String s, const charSize& c);
        virtual ~Damage();
        void update(int d, const position& p);
        Text getText();
        void frameRun();
        int getLifeTime();
    private:
        Text number;
        Font font;
        int lifeTime = 15;
        float speed = 1.5;
};

#endif // DAMAGE_H
