#include <Map.h>

const int W = 1000;
const int H = 700;

/* Notes

easy: damage, drops, healthbar, start screen

difficult: inventory idea: use vector, make item class deriving from entity. make array of inventory slots and make the mouse position
identify them. If the mouse was holding the item and released in a slot, the item position is set according to the slot.

Inventory screen, stat screen, and all other screens should not be all initialized in the main function, but make a class for it and use 
vector in main function.

what I did last time: fixed monster random movement

                                                */

using namespace sf;
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(W, H), "Game");
    //////////Initialization(begin)//////////
    Player player(image("pokemontrainer.png"), setRect(0,0,256/4, 256/4), position(W/2,H/2));
    player.locate(sf::Vector2f(540,240));// initial position (position is not set in the first map by the load function)
    Monster m(image("slime.png"), setRect(0, 0, 50, 50), position(50,50));
    std::vector<Monster> monsterArray;
    Projectile sword(image("sword.png"), setRect(0, 0, 32, 32), position(0,0));
    std::vector<Projectile> projectileArray;
    Map map, bgmap;
    /*if (!map.load("tile2.png", sf::Vector2u(50, 50), level1, 20, 14, player, m, monsterArray))
        return -1;
    if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel1, 20, 14, player, m, monsterArray))
        return -1;*/
    Sprite titleScreen;
    //titleScreen.loadFromFile...
   
    Font font;
    //font.loadFromFile...
    Text damage("0", font, 20);
    std::vector<Text> textArray;
    int mapNumber = 0;
    //////////Initialization(end)//////////
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        //////////Frameruns(begin)//////////
        player.frameRun();
        for(auto it = monsterArray.begin(); it < monsterArray.end(); it++)
        {
        it -> frameRun();
        }
        for(auto it = projectileArray.begin(); it < projectileArray.end(); it++)
        {
        it -> frameRun();
        if(it->getLifeTime()<1)
        {
            projectileArray.erase(it);
        }
        }
        //////////Frameruns(end)//////////
        //////////Buttons(begin)//////////
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            player.attack(projectileArray, sword);
        }
        if(event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Q)
            {
            //add delays using mouse event members
            std::cout<<"X: "<<player.getPositionX()<<std::endl;
            std::cout<<"Y: "<<player.getPositionY()<<std::endl;
            }
        }
        if (event.type == sf::Event::MouseButtonReleased && mapNumber == 0)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
        std::cout << "the right button was pressed" << std::endl;
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
        }
        //////////Buttons(end)//////////
        //////////Collision(begin)//////////
        map.isCollide(player, entityNames("wall"));
        map.isCollide(player, entityNames("portal"));
        map.isCollide(player, entityNames("prevportal"));
        for(auto it = monsterArray.begin(); it < monsterArray.end(); it++)
        {
        map.monsterCollide(*it);
        }
        for(auto it = monsterArray.begin(); it < monsterArray.end(); it++)
        {
        for(auto it2 = projectileArray.begin(); it2 < projectileArray.end(); it2++)
        {

            if(isCollide(*it2, *it))
               {
                    monsterArray.erase(it);
               }
        }
        }
        //////////Collision(end)//////////
        //////////Portals(begin)//////////
        if(map.onPortal())
        {
            map.resetMap(monsterArray);
            if(map.isEmpty())
            {
            if (!map.load("tile2.png", sf::Vector2u(50, 50), level2, 20, 14, player, m, monsterArray))
            return -1;
            if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel2, 20, 14, player, m, monsterArray))
            return -1;
              mapNumber++;
            }
        }
        if(map.onPrevPortal())
        {
            map.resetMap(monsterArray);
            if(map.isEmpty())
            {
            if (!map.load("tile2.png", sf::Vector2u(50, 50), level1, 20, 14, player, m, monsterArray))
            return -1;
            if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel1, 20, 14, player, m, monsterArray))
            return -1;
              mapNumber--;
            }
            
        }
        //////////Portals(end)//////////
        window.clear();

        window.draw(map);
        window.draw(bgmap);
      
        for(auto it = monsterArray.begin(); it < monsterArray.end(); it++)
        {
        window.draw(it->getSprite());
        window.draw(it->getRect());
        }
      
        window.draw(player.getSprite());
      
        for(auto it = projectileArray.begin(); it < projectileArray.end(); it++)
        {
        window.draw(it->getSprite());
        window.draw(it->getRect());
        }
        window.draw(titleScreen);

        window.display();
    }

    return 0;
}
