#ifndef INTERFACE_H
#define INTERFACE_H

#include <Entity.h>
using namespace sf;

class Interface: public sf::Drawable
{
    public:
        Interface();
        virtual ~Interface();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void frameRun();
        void addExperience(float e);

    private:
        Sprite spr_expBar, spr_hpBar, spr_mpBar;

        RectangleShape expRect, hpRect, mpRect;
        Texture t, t2, t3;
        float experience = 5;
        float maxExp = 10;

        float hp = 5;
        float maxHp = 10;

        float mp = 5;
        float maxMp = 10;

        Font font;
        Text lvl;
        Text lvlShow;
        int lvlValue = 1;

};

#endif // INTERFACE_H
