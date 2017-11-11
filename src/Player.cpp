#include "Player.h"

Player::Player(const image& img, const setRect& sr, const position& p)
{
    t_player.loadFromFile(img.imgName);

    s_player.setTexture(t_player);

    s_player.setTextureRect(IntRect(sr.x, sr.y, sr.rectX, sr.rectY));

    s_player.setPosition(p.x1,p.y1);

    imgSizeX = sr.rectX;
    imgSizeY = sr.rectY;
}

Player::~Player()
{
    //dtor
}

void Player::frameRun()
{
    tick++;

    s_player.setTextureRect(IntRect(i*imgSizeX, 0, imgSizeX, imgSizeY));
    if(tick>50&&i>2){i = 0; tick = 0;}
    if(tick>50){i++; tick = 0;}
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        s_player.move(-1,0);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        s_player.move(1,0);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        s_player.move(0,-1);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        s_player.move(0,1);
    }

}
void Player::randomPosition()
{

    s_player.setPosition(rand()%700+100,50);
}
float Player::getPositionX()
{
    return s_player.getPosition().x;

}
float Player::getPositionY()
{
    return s_player.getPosition().y;
}
void Player::wallCollide(int dir)
{
    if(dir == 1) s_player.move(1,0);
    if(dir == 2) s_player.move(-1,0);
    if(dir == 3) s_player.move(0,1);
    if(dir == 4) s_player.move(0,-1);
}
