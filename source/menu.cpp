#include <iostream>
#include "menu.h"

Menu::Menu(int xCoor, int yCoor, sf::Text* array, int arrSize, double pad, sf::Color textCol, sf::Color highlightCol)//, int w, int h)
{
    x = xCoor;
    y = yCoor;
    txtArray = new sf::Text[arrSize];
    for(int i = 0; i < arrSize; i++)
        txtArray[i] = array[i];
    arraySize = arrSize;
    padding = pad;
    calculateGlobalBounds();
    textColor = textCol;
    highlightColor = highlightCol;
    applyTextColor();
}

Menu::~Menu()
{
    delete[] txtArray;
}

void Menu::calculateGlobalBounds()
{
    calculateWidth();
    calculateHeight();
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

void Menu::calculateWidth()
{
    int maxTextW = txtArray[0].getGlobalBounds().width;
    for(int i = 1; i < arraySize; i++)
        if(txtArray[i].getGlobalBounds().width > maxTextW) maxTextW = txtArray[i].getGlobalBounds().width;
    width =  maxTextW;
}

void Menu::calculateHeight()
{
    height = padding;
    for(int i = 0; i < arraySize; i++)
        height += txtArray[i].getGlobalBounds().height + padding;
}

void Menu::setArr(sf::Text* newArr, int size)
{
    delete[] txtArray;
    txtArray = new sf::Text[size];
    for(int i = 0; i < size; i++)
        txtArray[i] = newArr[i];
    arraySize = size;
    calculateGlobalBounds();
}

void Menu::setTextSize(int size)
{
    for(int i = 0; i < arraySize; i++)
        txtArray[i].setCharacterSize(size);
    calculateGlobalBounds();
}

void Menu::display(sf::RenderWindow* aWindow)
{
    txtArray[0].setPosition(x + padding + width / 2 - txtArray[0].getGlobalBounds().width / 2, y);
    (*aWindow).draw(txtArray[0]);
    for(int i = 1; i < arraySize; i++)
    {
        txtArray[i].setPosition(x + padding + width / 2 - txtArray[i].getGlobalBounds().width / 2, txtArray[i - 1].getPosition().y + padding + txtArray[i - 1].getGlobalBounds().height);
        (*aWindow).draw(txtArray[i]);
    }
    //Text Highlight
    for(int i = 0; i < arraySize; i++)
    {
        if(textMouseOver(txtArray[i], aWindow))
        {
            txtArray[i].setColor(highlightColor);
            break;
        }
        else applyTextColor();
    }
}

void Menu::setTextColor(sf::Color aColor)
{
    textColor = aColor;
}

sf::Color Menu::getTextColor() const
{
    return textColor;
}

void Menu::setHighlightColor(sf::Color aColor)
{
    highlightColor = aColor;
}

sf::Color Menu::getHighlightColor() const
{
    return highlightColor;
}

void Menu::applyTextColor()
{
    for(int i = 0; i < arraySize; i++)
        txtArray[i].setColor(textColor);
}

bool textMouseOver(sf::Text& aText, sf::RenderWindow* aWindow)
{
    if(sf::Mouse::getPosition(*aWindow).x >= aText.getPosition().x &&
       sf::Mouse::getPosition(*aWindow).x <= aText.getPosition().x + aText.getGlobalBounds().width &&
       sf::Mouse::getPosition(*aWindow).y >= aText.getPosition().y &&
       sf::Mouse::getPosition(*aWindow).y <= aText.getPosition().y + aText.getGlobalBounds().height) return true;
    return false;
}
