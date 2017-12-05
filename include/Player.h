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


    private:
        Texture t_player;
        Sprite s_player;

        int dir = 0;
        int imgSizeX;
        int imgSizeY;

        int i = 0;
        int tick = 0;
        float speed = 7; // default speed: 0.7
        int cooldown = 20;
        float strength = 30;
        float critChance = 0.3;
        float critMultiplier = 2;




};

#endif // PLAYER_H
