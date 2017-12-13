#include <Map.h>
#include <Functions.h>


const int W = 1000;
const int H = 700;



using namespace sf;
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(W, H), "Game");


    //////////Initialization(begin)//////////

    Player player(image("pokemontrainer.png"), setRect(0,0,256/4, 256/4), position(W/2,H/2));
    player.locate(sf::Vector2f(540,240));// initial position (position is not set in the first map by the load function)
    Monster m(image("slime.png"), setRect(0, 0, 50, 50), position(50,50), health(10), eva(1), ID(1));
    Monster ys(image("yellowslime.png"), setRect(0, 0, 50, 50), position(50,50), health(15), eva(2), ID(2));

    std::vector<Monster> monsterArray, monsterStorage;
    monsterStorage.push_back(m);
    monsterStorage.push_back(ys);
    Projectile sword(image("sword.png"), setRect(0, 0, 32, 32), position(0, 0));
    std::vector<Projectile> projectileArray;
    std::vector<Item> itemArray;
    Item item;
    Map map, bgmap;

    if (!map.load("tile2.png", sf::Vector2u(50, 50), level1, 20, 14, player, monsterStorage, monsterArray))
        return -1;
    if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel1, 20, 14, player, monsterStorage, monsterArray))
        return -1;
    Damage damage("word.ttf", charSize(30));
    std::vector<Damage> damageArray;
    Timer timer; // used for button delays

    screenManager screen(rectSize(250,200));
    Interface interface;


    item.drop(position(0,0),1);
    for(int i = 0; i <2; i++)screen.addItem(item);


    //////////Initialization(end)//////////

    window.setFramerateLimit(60);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }


    //////////Frameruns(begin)//////////
        Vector2i localPosition = sf::Mouse::getPosition(window);
        interface.frameRun(player);
        screen.frameRun(player, localPosition);
        map.monsterRespawn(monsterStorage, monsterArray, bgmap);
        timer.frameRun();
        player.frameRun();

        for (auto it = monsterArray.begin(); it < monsterArray.end(); it++) {
            it->frameRun();
            if(it -> getHp() <= 0){
                item.drop(position(it -> getPositionX(), it -> getPositionY()), it -> getID());
                itemArray.push_back(item);
                monsterArray.erase(it);
                map.monsterDied();
                player.addValue("exp", 1);
            }
        }

        for (auto it = projectileArray.begin(); it < projectileArray.end(); it++) {
            it->frameRun();
            if (it->getLifeTime() < 1) {
                projectileArray.erase(it);
            }
        }
        for (auto it = damageArray.begin(); it < damageArray.end(); it++) {
            it->frameRun();
            if (it->getLifeTime() < 1) {
                damageArray.erase(it);
            }
        }

        //////////Frameruns(end)//////////

        //////////Buttons(begin)//////////

        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            player.attack(projectileArray, sword);
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            if(timer.getTime() < 0)
            {
                 std::cout<<"yay"<<std::endl;
                 timer.setTimer(60);
            }
        }

        if(event.type == Event::MouseButtonReleased) {
            screen.dragItem(0);
        }
        if(screen.isMouseOnButton("itemslot", localPosition)) {
            if(event.type == Event::MouseButtonPressed) {
                if(timer.getTime() < 0) {
                    screen.dragItem(1);
                    timer.setTimer(60);
                }
            }

        }
        if(screen.isMouseOnButton("statbutton", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left)) {
                if(timer.getTime() < 0) {
                    screen.screenOn("stat");
                    timer.setTimer(60);
                }
            }
        }
        if(screen.isMouseOnButton("inventorybutton", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left)) {
                if(timer.getTime() < 0) {
                    screen.screenOn("inventory");
                    timer.setTimer(60);
                }
            }
        }
        if(screen.isMouseOnButton("str", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left) && player.getStat("statpoint") > 0 && screen.isScreenOn("stat")) {
                if(timer.getTime() < 0) {
                    player.addValue("str", 1);
                    player.addValue("statpoint", -1);
                    timer.setTimer(30);
                }
            }
        }
        if(screen.isMouseOnButton("dex", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left) && player.getStat("statpoint") > 0 && screen.isScreenOn("stat")) {
                if(timer.getTime() < 0) {
                    player.addValue("dex", 1);
                    player.addValue("statpoint", -1);
                    timer.setTimer(30);
                }
            }
        }
        if(screen.isMouseOnButton("int", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left) && player.getStat("statpoint") > 0 && screen.isScreenOn("stat")) {
                if(timer.getTime() < 0) {
                    player.addValue("int", 1);
                    player.addValue("statpoint", -1);
                    timer.setTimer(30);
                }
            }
        }
        if(screen.isMouseOnButton("luk", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left) && player.getStat("statpoint") > 0 && screen.isScreenOn("stat")) {
                if(timer.getTime() < 0) {
                    player.addValue("luk", 1);
                    player.addValue("statpoint", -1);
                    timer.setTimer(30);
                }
            }
        }
        if(screen.isMouseOnButton("def", localPosition)) {
            if(Mouse::isButtonPressed(Mouse::Left) && player.getStat("statpoint") > 0 && screen.isScreenOn("stat")) {
                if(timer.getTime() < 0) {
                    player.addValue("def", 1);
                    player.addValue("statpoint", -1);
                    timer.setTimer(30);
                }
            }
        }
        //////////Buttons(end)//////////

        //////////Collision(begin)//////////

        map.isCollide(player, entityNames("wall"));
        map.isCollide(player, entityNames("portal"));
        map.isCollide(player, entityNames("prevportal"));
        for (auto it = monsterArray.begin(); it < monsterArray.end(); it++) {
            map.monsterCollide(*it);
        }

        for (auto it = monsterArray.begin(); it < monsterArray.end(); it++) {
            for (auto it2 = projectileArray.begin(); it2 < projectileArray.end(); it2++) {
                if (isCollide<Projectile, Monster>(*it2, *it)) {
                    int tempDamage = player.getDamage(1);
                    it->takeDamage(tempDamage);
                    damage.update(tempDamage, position(it -> getPositionX(), it -> getPositionY()));
                    damageArray.push_back(damage);
                    projectileArray.erase(it2);
                }
            }
        }

    if(screen.isNotTooMuchItem()) {
        for (auto it = itemArray.begin(); it < itemArray.end(); it++) {
            if (isCollide<Player, Item>(player, *it)) {
                screen.addItem(*it);
                itemArray.erase(it);
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
            if (!map.load("tile2.png", sf::Vector2u(50, 50), level2, 20, 14, player, monsterStorage, monsterArray))
            return -1;
            if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel2, 20, 14, player, monsterStorage, monsterArray))
            return -1;
            }
        }
        if (map.onPrevPortal()) {
            map.resetMap(monsterArray);
            if (map.isEmpty()) {
                if (!map.load("tile2.png", sf::Vector2u(50, 50), level1, 20, 14, player, monsterStorage, monsterArray))
                    return -1;
                if (!bgmap.load("flowers.png", sf::Vector2u(50, 50), Bglevel1, 20, 14, player, monsterStorage, monsterArray))
                    return -1;
            }
        }

        //////////Portals(end)//////////

        window.clear();

        window.draw(map);
        window.draw(bgmap);

        for (auto it = itemArray.begin(); it < itemArray.end(); it++) {
            window.draw(it->getSprite());
            //window.draw(it->getRect());
        }

        for (auto it = monsterArray.begin(); it < monsterArray.end(); it++) {
            window.draw(it->getSprite());
            //window.draw(it->getRect());
        }

        window.draw(player.getSprite());
        //window.draw(player.getRect());

        for (auto it = projectileArray.begin(); it < projectileArray.end(); it++) {
            window.draw(it->getSprite());
            //window.draw(it->getRect());
        }

        for (auto it = damageArray.begin(); it < damageArray.end(); it++) {
            window.draw(it->getText());
        }

        window.draw(screen);
        window.draw(interface);
        window.display();
    }

    return 0;
}
