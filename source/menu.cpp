#include <iostream>
#include "menu.h"

Menu::Menu(int xCoor, int yCoor, sf::Text* array, int arrSize, int pad)//, int w, int h)
{
    x = xCoor;
    y = yCoor;
    txtArray = new sf::Text[arrSize];
    for(int i = 0; i < arrSize; i++)
        txtArray[i] = array[i];
    arraySize = arrSize;
    int maxTextW = txtArray[0].getGlobalBounds().width;
    for(int i = 1; i < arraySize; i++)
        if(txtArray[i].getGlobalBounds().width > maxTextW) maxTextW = txtArray[i].getGlobalBounds().width;
    width = maxTextW;
    padding = pad;
    height = padding;
    for(int i = 0; i < arraySize; i++)
        height += txtArray[i].getGlobalBounds().height + pad;
}

Menu::~Menu()
{
    delete[] txtArray;
}

int Menu::getWidth() const
{
    return width;
}

int Menu::getHeight() const
{
    return height;
}

void Menu::setPosition(int left, int top)
{
    x = left;
    y = top;
}

void Menu::display(sf::RenderWindow* aWindow) const
{
    txtArray[0].setPosition(x + padding + width / 2 - txtArray[0].getGlobalBounds().width / 2, y);
    (*aWindow).draw(txtArray[0]);
    for(int i = 1; i < arraySize; i++)
    {
        txtArray[i].setPosition(x + padding + width / 2 - txtArray[i].getGlobalBounds().width / 2, txtArray[i - 1].getPosition().y + padding + txtArray[i - 1].getGlobalBounds().height);
        (*aWindow).draw(txtArray[i]);
    }
}
