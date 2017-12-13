#include "Player.h"

Player::Player(const image& img, const setRect& sr, const position& p)
{
    t_player.loadFromFile(img.imgName);

    s_player.setTexture(t_player);

    s_player.setTextureRect(IntRect(sr.x, sr.y, sr.rectX, sr.rectY));

    s_player.setPosition(p.x1,p.y1);

    imgSizeX = sr.rectX;
    imgSizeY = sr.rectY;

    rect.setSize(Vector2f(imgSizeX/4, imgSizeY/4));
}

Player::~Player()
{
    //dtor
}

void Player::frameRun()
{
    tick++;
    rect.setPosition(getPositionX() + imgSizeX/3, getPositionY() + imgSizeY/2);
    s_player.setTextureRect(IntRect(0, dir * imgSizeY, imgSizeX, imgSizeY));
    if(tick>30&&i>2){i = 0; tick = 0;}
    if(tick>30){i++; tick = 0;}
    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        s_player.move(-speed,0);
        dir = 1;
        s_player.setTextureRect(IntRect(i * imgSizeX, dir * imgSizeY, imgSizeX, imgSizeY));
    }
    else if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        s_player.move(speed,0);
        dir = 2;
        s_player.setTextureRect(IntRect(i * imgSizeX, dir * imgSizeY, imgSizeX, imgSizeY));

    }
    else if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        s_player.move(0,-speed);
        dir = 3;
        s_player.setTextureRect(IntRect(i * imgSizeX, dir * imgSizeY, imgSizeX, imgSizeY));

    }
    else if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        s_player.move(0,speed);
        dir = 0;
        s_player.setTextureRect(IntRect(i * imgSizeX, dir * imgSizeY, imgSizeX, imgSizeY));
    }
    cooldown --;

    if(experience >= maxExp)//Level up
    {
        experience = 0;
        maxExp += lvl * 3;
        lvl += 1;
        maxHp += lvl;
        maxMp += 1;
        hp = maxHp;
        mp = maxMp;
        statPoint += 4;
    }
}
void Player::attack(std::vector<Projectile>& p, Projectile& pp)
{
    if(dir==0){   pp.update(s_player.getPosition().x+15, s_player.getPosition().y+35, 0, 0);}//down
    if(dir==1){   pp.update(s_player.getPosition().x+30, s_player.getPosition().y+20, 90, 1);}//left
    if(dir==2){   pp.update(s_player.getPosition().x+30, s_player.getPosition().y+55, 270, 2);}//right
    if(dir==3){   pp.update(s_player.getPosition().x+47, s_player.getPosition().y+35, 180, 3);}//up
    if(cooldown<1){p.push_back(pp); cooldown = 20;}
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
    if(dir == 1) s_player.move(speed,0);
    if(dir == 2) s_player.move(-speed,0);
    if(dir == 3) s_player.move(0,speed);
    if(dir == 4) s_player.move(0,-speed);
}
void Player::locate(sf::Vector2f loc)
{
    s_player.setPosition(loc);
}
int Player::getDamage(int skillPower)
{
    int damage;
    damage = rand() % (lvl * 2) + strength;
    if(rand() % 100 < critChance) damage *= critMultiplier;
    return damage;
}
int Player::getStat(std::string s)
{
    if(s == "str") return strength;
    if(s == "hp") return hp;
    if(s == "maxHp") return maxHp;
    if(s == "mp") return mp;
    if(s == "maxMp") return maxMp;
    if(s == "exp") return experience;
    if(s == "maxExp") return maxExp;
    if(s == "level") return lvl;
    if(s == "dex") return dex;
    if(s == "int") return intel;
    if(s == "luk") return luk;
    if(s == "def") return def;
    if(s == "statpoint") return statPoint;
}
void Player::addValue(std::string s, float e)
{
    if(s == "str") strength += e;
    if(s == "hp") hp += e;
    if(s == "maxHp") maxHp += e;
    if(s == "mp") mp += e;
    if(s == "maxMp") maxMp += e;
    if(s == "exp") experience += e;
    if(s == "maxExp") maxExp += e;
    if(s == "level") lvl += e;
    if(s == "dex") dex += e;
    if(s == "int") intel += e;
    if(s == "luk") luk += e;
    if(s == "def") def += e;
    if(s == "statpoint") statPoint += e;
}
RectangleShape Player::getRect()
{
    return rect;
}
