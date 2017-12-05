#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <Entity.h>

using namespace sf;

class screenManager
{
    public:
        screenManager(const rectSize& rs, std::vector<RectangleShape>& rectArray);
        virtual ~screenManager();
        bool isDragging();

    private:
        RectangleShape screen, dragger, closeButton;
        RectangleShape upgradeButton[10];
        Text text;
        float draggerLength;
        //std::vector<Text> textArray;
        //std::vector<RectangleShape> rectArray;
        bool dragging;

};

#endif // SCREENMANAGER_H
