#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <Entity.h>
#include <Player.h>
#include <Item.h>
#include <vector>

using namespace sf;

class screenManager: public sf::Drawable
{
    public:
        screenManager(const rectSize& rs);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void screenOn(std::string s);
        bool isScreenOn(std::string s);
        void frameRun(Player& player, sf::Vector2i localPosition);
        bool isMouseOnButton(std::string s, sf::Vector2i localPosition);
        void addItem(Item& i);
        bool isNotTooMuchItem();
        void dragItem(bool on);

    private:
        std::string convertToString(int number);
        bool isMouseOn(int x, int y, int buttonLength, sf::Vector2i localPosition);

        RectangleShape screen, statButton, inventoryButton, invScreen, slots[6][5];
        Text str, strShow, dex, dexShow, intel, intelShow, luk, lukShow, def, defShow, statPoint, statPointShow;
        Font font;
        bool statOn = false;
        bool invOn = false;
        Sprite plusButton[5];
        Texture t1;
        int statPointValue;
        const int x = 700;
        const int y = 70;
        std::vector<Item> items;
        std::vector<int> itemAllocator;
        std::vector<Sprite> s_items;
        std::vector<Text> t_items;
        int maxItems = 30;
        int whichItemToDrag = 0;
        bool isDragItem = false;

};

#endif // SCREENMANAGER_H
