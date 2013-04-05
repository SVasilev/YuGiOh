#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>

class Menu
{
private:
    int x, y, arraySize, width, height; //Padding is the space between every text.
    double padding;
    sf::Text* txtArray;
public:
    Menu(int xCoor = 0, int yCoor = 0, sf::Text* array = NULL, int arrSize = 0, double pad = 5);//, int w = 0, int h = 0);
    ~Menu();
    void setPosition(int left, int top);
    void setArr(sf::Text* newArr, int size);
    void calculateWidth();
    void calculateHeight();
    void calculateGlobalBounds();
    void setTextSize(int size);
    int getWidth() const;
    int getHeight() const;
    void display(sf::RenderWindow* aWindow) const;
};

#endif // MENU_H_INCLUDED
