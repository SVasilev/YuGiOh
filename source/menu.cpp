#include <iostream>
#include "menu.h"

Menu::Menu(sf::Text* array, int arrSize, sf::Font aFont, int xCoor, int yCoor, double pad, int txtSize, sf::Color textCol, sf::Color highlightCol)//, int w, int h)
{
    txtArray = new sf::Text[arrSize];
    for(int i = 0; i < arrSize; i++)
        txtArray[i] = array[i];
    arraySize = arrSize;
    x = xCoor;
    y = yCoor;
    padding = pad;
    textSize = txtSize;
    applyTextSize();
    textColor = textCol;
    highlightColor = highlightCol;
    applyTextColor();
    textFont = aFont;
    applyTextFont();
    calculateGlobalBounds();
}

Menu::~Menu()
{
    delete[] txtArray;
}

//Setters
void Menu::setArr(sf::Text* newArr, int size)
{
    delete[] txtArray;
    txtArray = new sf::Text[size];
    for(int i = 0; i < size; i++)
        txtArray[i] = newArr[i];
    arraySize = size;
    applyTextFont();
    applyTextColor();
    applyTextSize();
}

void Menu::setTextFont(sf::Font aFont)
{
    textFont = aFont;
    applyTextFont();
}

void Menu::setPosition(int left, int top)
{
    x = left;
    y = top;
}

void Menu::setPadding(int pad)
{
    padding = pad;
}

void Menu::setTextSize(int size)
{
    textSize = size;
    applyTextSize();
}

void Menu::setTextColor(sf::Color aColor)
{
    textColor = aColor;
    applyTextColor();
}

void Menu::setHighlightColor(sf::Color aColor)
{
    highlightColor = aColor;
}

//Getters
sf::Text* Menu::getTextArray() const
{
    return txtArray;
}

int Menu::getTextArraySize() const
{
    return arraySize;
}

sf::Font Menu::getTextFont() const
{
    return textFont;
}

int Menu::getX() const
{
    return x;
}

int Menu::getY() const
{
    return y;
}

int Menu::getPadding() const
{
    return padding;
}

int Menu::getTextSize() const
{
    return textSize;
}

sf::Color Menu::getTextColor() const
{
    return textColor;
}

sf::Color Menu::getHighlightColor() const
{
    return highlightColor;
}

//Help Functions

void Menu::applyTextSize()
{
    for(int i = 0; i < arraySize; i++)
        txtArray[i].setCharacterSize(textSize);
    calculateGlobalBounds();
}

void Menu::applyTextFont()
{
    for(int i = 0; i < arraySize; i++)
        txtArray[i].setFont(textFont);
    calculateGlobalBounds();
}

void Menu::applyTextColor()
{
    for(int i = 0; i < arraySize; i++)
        txtArray[i].setColor(textColor);
}

void Menu::calculateGlobalBounds()
{
    int maxTextW = txtArray[0].getGlobalBounds().width;
    for(int i = 1; i < arraySize; i++)
        if(txtArray[i].getGlobalBounds().width > maxTextW) maxTextW = txtArray[i].getGlobalBounds().width;
    width =  maxTextW + 2*padding;
    height = padding;
    for(int i = 0; i < arraySize; i++)
        height += txtArray[i].getGlobalBounds().height + padding;
}

int Menu::getWidth() const
{
    return width;
}

int Menu::getHeight() const
{
    return height;
}

void Menu::display(sf::RenderWindow* aWindow)
{
    txtArray[0].setPosition(padding + x + width / 2 - txtArray[0].getGlobalBounds().width / 2, y + padding);
    (*aWindow).draw(txtArray[0]);
    for(int i = 1; i < arraySize; i++)
    {
        txtArray[i].setPosition(padding + x + width / 2 - txtArray[i].getGlobalBounds().width / 2, txtArray[i - 1].getPosition().y + padding + txtArray[i - 1].getGlobalBounds().height);
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

bool textMouseOver(sf::Text& aText, sf::RenderWindow* aWindow)
{
    if(sf::Mouse::getPosition(*aWindow).x >= aText.getPosition().x &&
       sf::Mouse::getPosition(*aWindow).x <= aText.getPosition().x + aText.getGlobalBounds().width &&
       sf::Mouse::getPosition(*aWindow).y >= aText.getPosition().y &&
       sf::Mouse::getPosition(*aWindow).y <= aText.getPosition().y + aText.getGlobalBounds().height) return true;
    return false;
}
