#ifndef BUTTON_H
#define BUTTON_H

#include <Entity.h>
using namespace sf;

class Button
{
    public:
        Button();
        virtual ~Button();
        bool isMouseOn(int x, int y, int buttonSize);
    private:
        //RectangleShape rect;
        //Text text;
        //Font font;
};

#endif // BUTTON_H
