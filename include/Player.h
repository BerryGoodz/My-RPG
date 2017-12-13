#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include <Projectile.h>
using namespace sf;

class Player
{
    public:
        Player(const image& img, const setRect& sr, const position& p);

        virtual ~Player();
        virtual Sprite getSprite()
        {
            return s_player;
        }
        void frameRun();
        void randomPosition();
        float getPositionX();
        float getPositionY();
        void locate(sf::Vector2f loc);
        void wallCollide(int dir);
        void attack(std::vector<Projectile>& p, Projectile& pp);
        int getDamage(int skillPower);
        int getStat(std::string s);
        void addValue(std::string s, float e);
        RectangleShape getRect();


    private:
        Texture t_player;
        Sprite s_player;
        RectangleShape rect;
        int dir = 0;
        int imgSizeX;
        int imgSizeY;

        int i = 0;
        int tick = 0;
        float speed = 7; // default speed: 0.7
        int cooldown = 20;
        float critChance = 30;
        float critMultiplier = 2;
        float hp = 50;
        float maxHp = 50;
        float mp = 10;
        float maxMp = 10;
        float experience = 0;
        float maxExp = 10;
        int lvl = 1;
        int strength = 1;
        int dex = 1;
        int intel = 1;
        int luk = 1;
        int def = 1;
        int statPoint = 0;





};

#endif // PLAYER_H
