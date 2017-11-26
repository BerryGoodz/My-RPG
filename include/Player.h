#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include <Projectile.h>
class Player: public Entity
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


    private:
        Texture t_player;
        Sprite s_player;

        int dir = 0;
        int imgSizeX;
        int imgSizeY;
        int i = 0;
        int tick = 0;
        float speed = 0.7;
        int cooldown = 20;

};

#endif // PLAYER_H
