#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>

class Menu
{
private:
    int x, y, arraySize, padding, width, height; //Padding is the space between every text.
    sf::Text* txtArray;
public:
    Menu(int xCoor = 0, int yCoor = 0, sf::Text* array = NULL, int arrSize = 0, int pad = 5);//, int w = 0, int h = 0);
    ~Menu();
    void setPosition(int left, int top);
    int getWidth() const;
    int getHeight() const;
    void display(sf::RenderWindow* aWindow) const;
};

#endif // MENU_H_INCLUDED
