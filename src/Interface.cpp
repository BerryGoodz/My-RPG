#include "Interface.h"

Interface::Interface()
{
    if(!t.loadFromFile("expbar.png"))std::cout<<"could not load image";

    spr_expBar.setTexture(t);
    spr_expBar.setPosition(15,15 + 80);
    spr_expBar.setTextureRect(sf::IntRect(0,0,200,16));
    expRect.setSize(sf::Vector2f(200,16));
    expRect.setFillColor(sf::Color::White);
    expRect.setPosition(15,15 + 80);

    if(!t2.loadFromFile("health.png"))std::cout<<"could not load image";

    spr_hpBar.setTexture(t2);
    spr_hpBar.setPosition(15,45);
    spr_hpBar.setTextureRect(sf::IntRect(0,0,200,16));
    hpRect.setSize(sf::Vector2f(200,16));
    hpRect.setFillColor(sf::Color::White);
    hpRect.setPosition(15,45);

    if(!t3.loadFromFile("mana.png"))std::cout<<"could not load image";

    spr_mpBar.setTexture(t3);
    spr_mpBar.setPosition(15,15 + 55);
    spr_mpBar.setTextureRect(sf::IntRect(0,0,200,16));
    mpRect.setSize(sf::Vector2f(200,16));
    mpRect.setFillColor(sf::Color::White);
    mpRect.setPosition(15,15 + 55);

    if(!font.loadFromFile("word.ttf"))std::cout<<"could not load image";
    lvl.setFont(font);
    lvl.setString("Lvl: ");
    lvl.setFillColor(Color::Black);
    lvl.setPosition(15, 5);

    lvlShow.setFont(font);
    lvlShow.setFillColor(Color::Black);
    lvlShow.setPosition(80,5);
}

Interface::~Interface()
{
    //dtor
}
void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(expRect, states);
    target.draw(spr_expBar, states);
    target.draw(hpRect, states);
    target.draw(spr_hpBar, states);
    target.draw(mpRect, states);
    target.draw(spr_mpBar, states);
    target.draw(lvl, states);
    target.draw(lvlShow, states);
}
void Interface::frameRun()
{
    spr_expBar.setScale(static_cast<float>(experience) / maxExp, 1);
    spr_hpBar.setScale(static_cast<float>(hp) / maxHp, 1);
    spr_mpBar.setScale(static_cast<float>(mp) / maxMp, 1);

    int np= lvlValue;
    std::string sp;
    std::stringstream ssp;
    ssp << np;
    ssp >> sp;
    lvlShow.setString(sp);

    if(experience >= maxExp)
    {
        experience = 0;
        maxExp += lvlValue * 3;
        lvlValue += 1;
        maxHp += lvlValue;
        maxMp += 1;
        hp = maxHp;
        mp = maxMp;
    }
}
void Interface::addExperience(float e)
{
    experience += e;
}
