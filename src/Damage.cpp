#include "Damage.h"

Damage::Damage(String s, const charSize& c)
{
    font.loadFromFile(s);
    number.setFont(font);
    number.setCharacterSize(c.s);
    number.setFillColor(Color::Red);
}

Damage::~Damage()
{
    //dtor
}
void Damage::update(int d, const position& p)
{
    number.setPosition(p.x1 + 15, p.y1);
    int np= d;
    std::string sp;
    std::stringstream ssp;
    ssp << np;
    ssp >> sp;
    number.setString(sp);
}
Text Damage::getText()
{
    return number;
}
void Damage::frameRun()
{
    number.move(0,-speed);
    lifeTime --;
}
int Damage::getLifeTime()
{
    return lifeTime;
}
