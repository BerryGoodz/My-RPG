#ifndef INTERFACE_H
#define INTERFACE_H

#include <Entity.h>
#include <Player.h>
using namespace sf;

class Interface: public sf::Drawable
{
    public:
        Interface();
        virtual ~Interface();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void frameRun(Player& p);

    private:
        Sprite spr_expBar, spr_hpBar, spr_mpBar;

        RectangleShape expRect, hpRect, mpRect;
        Texture t, t2, t3;
        float experience, maxExp, hp, maxHp, mp, maxMp;

        Font font;
        Text lvl;
        Text lvlShow;
        int lvlValue;

};

#endif // INTERFACE_H
