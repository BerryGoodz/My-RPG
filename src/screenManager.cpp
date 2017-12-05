#include "screenManager.h"

screenManager::screenManager(const rectSize& rs, std::vector<RectangleShape>& rectArray)
{
    screen.setSize(Vector2f(rs.x, rs.y));
    screen.setPosition(100,100);
    screen.setFillColor(sf::Color(0,0,0,200));
    //dragger.setSize(Vector2f(rs.x, 25));
    //dragger.setPosition(100,100);
    //dragger.setFillColor(sf::Color(50,0,150,200));
    closeButton.setSize(Vector2f(20,20));
    closeButton.setPosition(100 + rs.x - 25, 100 + 5);
    closeButton.setFillColor(sf::Color(200,0,0,200));
    rectArray.push_back(screen);
    //rectArray.push_back(dragger);
    rectArray.push_back(closeButton);

    draggerLength = rs.x;
}

screenManager::~screenManager()
{
    //dtor
}

/*bool screenManager::isDragging()
{
    if(sf::Mouse::getPosition().x > dragger.getPosition().x && sf::Mouse::getPosition().x < dragger.getPosition().x + draggerLength && sf::Mouse::getPosition().y > dragger.getPosition().y && sf::Mouse::getPosition().y < dragger.getPosition().y + 25)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            dragging = true;
            return true;
        }
    }
    return false;
}*/
