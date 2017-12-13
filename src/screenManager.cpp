#include "screenManager.h"
#include <Item.h>

screenManager::screenManager(const rectSize& rs)
{
    if(!t1.loadFromFile("plusbutton.png"))std::cout<<"could not load image";
    for(int i = 0; i < 5; i ++)
    {
    plusButton[i].setTexture(t1);
    plusButton[i].setPosition(x + 100, y + i * 20 + 3);
    }


    screen.setSize(Vector2f(rs.x, rs.y));
    screen.setPosition(x,y);
    screen.setFillColor(sf::Color(0,0,0,200));

    statButton.setSize(Vector2f(24,24));
    statButton.setPosition(x + 250, y - 40);
    statButton.setFillColor(sf::Color(0,0,0,200));

    invScreen.setSize(Vector2f(rs.x * 1.32, rs.y * 2.5));
    invScreen.setPosition(x - 150,y);
    invScreen.setFillColor(sf::Color(0,0,0,200));

    inventoryButton.setSize(Vector2f(24,24));
    inventoryButton.setPosition(x + 210, y - 40);
    inventoryButton.setFillColor(sf::Color(0,0,0,200));

    for(int i = 0; i < 6; i ++)
    {
        for(int j = 0; j < 5; j ++)
    {
        slots[i][j].setSize(Vector2f(50,50));
        slots[i][j].setPosition(x - 130 + j * 60 , y + i * 60 + 20);
    }
    }
    for(int i = 0; i < 100; i ++)
    {
        itemAllocator.push_back(0);
    }

    if(!font.loadFromFile("word.ttf"))std::cout<<"could not load image";
    str.setFont(font);
    str.setString("Str: ");
    str.setFillColor(Color::White);
    str.setPosition(x + 5, y);
    str.setCharacterSize(15);

    strShow.setFont(font);
    strShow.setFillColor(Color::White);
    strShow.setPosition(x + 40 , y);
    strShow.setCharacterSize(15);

    dex.setFont(font);
    dex.setString("Dex: ");
    dex.setFillColor(Color::White);
    dex.setPosition(x + 5, y + 20);
    dex.setCharacterSize(15);

    dexShow.setFont(font);
    dexShow.setFillColor(Color::White);
    dexShow.setPosition(x + 40 , y + 20);
    dexShow.setCharacterSize(15);

    intel.setFont(font);
    intel.setString("Int: ");
    intel.setFillColor(Color::White);
    intel.setPosition(x + 5, y + 40);
    intel.setCharacterSize(15);

    intelShow.setFont(font);
    intelShow.setFillColor(Color::White);
    intelShow.setPosition(x + 40 , y + 40);
    intelShow.setCharacterSize(15);

    luk.setFont(font);
    luk.setString("Luk: ");
    luk.setFillColor(Color::White);
    luk.setPosition(x + 5, y + 60);
    luk.setCharacterSize(15);

    lukShow.setFont(font);
    lukShow.setFillColor(Color::White);
    lukShow.setPosition(x + 40 , y + 60);
    lukShow.setCharacterSize(15);

    def.setFont(font);
    def.setString("Def: ");
    def.setFillColor(Color::White);
    def.setPosition(x + 5, y + 80);
    def.setCharacterSize(15);

    defShow.setFont(font);
    defShow.setFillColor(Color::White);
    defShow.setPosition(x + 40 , y + 80);
    defShow.setCharacterSize(15);

    statPoint.setFont(font);
    statPoint.setString("Stat point: ");
    statPoint.setFillColor(Color::White);
    statPoint.setPosition(x + 5, y + 100);
    statPoint.setCharacterSize(15);

    statPointShow.setFont(font);
    statPointShow.setFillColor(Color::White);
    statPointShow.setPosition(x + 100 , y + 100);
    statPointShow.setCharacterSize(15);
}


void screenManager::frameRun(Player& player, sf::Vector2i localPosition)
{
    strShow.setString(convertToString(player.getStat("str")));
    dexShow.setString(convertToString(player.getStat("dex")));
    intelShow.setString(convertToString(player.getStat("int")));
    lukShow.setString(convertToString(player.getStat("luk")));
    defShow.setString(convertToString(player.getStat("def")));
    statPointShow.setString(convertToString(player.getStat("statpoint")));
    statPointValue = player.getStat("statpoint");
    if(isDragItem) s_items[whichItemToDrag].setPosition(localPosition.x - 30, localPosition.y - 30);
}
std::string screenManager::convertToString(int number)
{
    int np= number;
    std::string sp;
    std::stringstream ssp;
    ssp << np;
    ssp >> sp;
    return sp;
}

void screenManager::screenOn(std::string s)
{
    if(s == "stat" && statOn)statOn = false;
    else if(s == "stat" && !statOn)statOn = true;

    if(s == "inventory" && invOn)invOn = false;
    else if(s == "inventory" && !invOn)invOn = true;
}
bool screenManager::isScreenOn(std::string s)
{
    if(s == "stat") return statOn;
    if(s == "inventory") return invOn;
}

bool screenManager::isMouseOn(int xPos, int yPos, int buttonLength, sf::Vector2i localPosition)
{
    if(localPosition.x > xPos && localPosition.x < xPos + buttonLength && localPosition.y > yPos && localPosition.y < yPos + buttonLength)
    {
        return true;
    }
    return false;
}
void screenManager::dragItem(bool on)
{
    if(on)isDragItem = true;
    if(!on)isDragItem = false;
}
bool screenManager::isMouseOnButton(std::string s, sf::Vector2i localPosition)
{
    if(s == "itemslot")
    {
        for(int i = 0; i < 6; i ++)
            for(int j = 0; j < 5; j ++)
        {
            if(isMouseOn(slots[i][j].getPosition().x, slots[i][j].getPosition().y, 50, localPosition))
            {
                if(itemAllocator[i * j + j] == 1)
                {
                    whichItemToDrag = i * j + j;
                    return true;
                }

            }
        }
    }
    if(s == "statbutton" && isMouseOn(statButton.getPosition().x, statButton.getPosition().y, 24, localPosition))
    {
        return true;
    }
    if(s == "inventorybutton" && isMouseOn(inventoryButton.getPosition().x, inventoryButton.getPosition().y, 24, localPosition))
    {
        return true;
    }
    if(s == "str" && isMouseOn(plusButton[0].getPosition().x, plusButton[0].getPosition().y, 15, localPosition))
    {
        return true;
    }
    if(s == "dex" && isMouseOn(plusButton[1].getPosition().x, plusButton[1].getPosition().y, 15, localPosition))
    {
        return true;
    }
    if(s == "int" && isMouseOn(plusButton[2].getPosition().x, plusButton[2].getPosition().y, 15, localPosition))
    {
        return true;
    }
    if(s == "luk" && isMouseOn(plusButton[3].getPosition().x, plusButton[3].getPosition().y, 15, localPosition))
    {
        return true;
    }
    if(s == "def" && isMouseOn(plusButton[4].getPosition().x, plusButton[4].getPosition().y, 15, localPosition))
    {
        return true;
    }
    return false;
}
void screenManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(statButton, states);
    target.draw(inventoryButton, states);
    if(statOn)
    {
        target.draw(screen, states);
        target.draw(str, states);
        target.draw(strShow, states);
        target.draw(dex, states);
        target.draw(dexShow, states);
        target.draw(intel, states);
        target.draw(intelShow, states);
        target.draw(luk, states);
        target.draw(lukShow, states);
        target.draw(def, states);
        target.draw(defShow, states);
        target.draw(statPoint, states);
        target.draw(statPointShow, states);
        if(statPointValue > 0)for(int i = 0; i < 5; i ++) target.draw(plusButton[i], states);
    }
    if(invOn)
    {
        target.draw(invScreen, states);
        for(int i = 0; i < 6; i ++)
        {
            for(int j = 0; j < 5; j ++)
        {
            target.draw(slots[i][j], states);
        }
        }
        for(int i = 0; i < s_items.size(); i ++)
        {
            target.draw(s_items[i], states);
        }
        for(int i = 0; i < t_items.size(); i ++)
        {
            target.draw(t_items[i], states);

        }
    }
}
bool screenManager::isNotTooMuchItem()
{
    return maxItems > items.size();
}
void screenManager::addItem(Item& i)
{
    Sprite tempSprite; RectangleShape tempRect;
    tempSprite = i.getSprite();
    tempSprite.setScale(1.3,1.3);
    bool permission = true;
    Text itemN;
    itemN.setFont(font);
    itemN.setFillColor(Color::Blue);
    itemN.setPosition(x + 100 , y + 100);
    itemN.setCharacterSize(15);
    itemN.setString(convertToString(1));

    for(int a = 0; a < items.size(); a ++)
    {
        if(items[a].getID() == i.getID())
        {
            items[a].addNumber(1);
            t_items[a].setString(convertToString(items[a].getNumber()));
            permission = false;
            break;
        }
    }
        if(permission)
        {
            int addX = 0; int addY = 0;//used later in if(permission) statement
            items.push_back(i);
            for(int c = 0; c < 100; c ++)
            {
                if(itemAllocator[c] == 0)
                {
                    addX = c % 5;
                    addY = c / 5;
                    tempSprite.setPosition(x - 127 + addX * 60, y + 23 + addY * 60);
                    itemN.setPosition(x - 130 + addX * 60, y + 53 + addY * 60);
                    itemAllocator[c] = 1;
                    break;
                }

            }
            s_items.push_back(tempSprite);
            t_items.push_back(itemN);
        }
}
