#include <iostream>
#include "menu.h"

int rememberI = -1;

Menu::Menu(sf::Text* array, int arrSize, int xCoor, int yCoor, double pad, sf::Font aFont, int txtSize, sf::Text::Style aStyle, sf::Color textCol, sf::Color highlightCol)//, sf::Sound highLSound)//, int w, int h)
{
    txtArray = NULL;
    setArr(array, arrSize);
    setPosition(xCoor, yCoor);
    setPadding(pad);
    setTextFont(aFont);
    setTextSize(txtSize);
    setTextStyle(aStyle);
    setTextColor(textCol);
    setHighlightColor(highlightCol);
}

Menu::~Menu()
{
    delete[] txtArray;
}

//Setters
void Menu::setArr(sf::Text* newArr, int size)
{
    if(size != 0)
    {
        if(txtArray != NULL) delete[] txtArray;
        txtArray = new sf::Text[size];
        for(int i = 0; i < size; i++)
            txtArray[i] = newArr[i];
        arraySize = size;
    }
    else
    {
        if(txtArray != NULL) std::cout << "Warning: No text is set to menu!\n";
        txtArray = NULL;
    }
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

void Menu::setTextFont(sf::Font aFont)
{
    textFont = aFont;
}

void Menu::setTextSize(int size)
{
    textSize = size;
}

void Menu::setTextStyle(sf::Text::Style aStyle)
{
    textStyle = aStyle;
}

void Menu::setTextColor(sf::Color aColor)
{
    textColor = aColor;
}

void Menu::setHighlightColor(sf::Color aColor)
{
    highlightColor = aColor;
}

void Menu::setHighlightSound(sf::Sound aSound)
{
    highlightSound = aSound;
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

sf::Font Menu::getTextFont() const
{
    return textFont;
}

int Menu::getTextSize() const
{
    return textSize;
}

sf::Text::Style Menu::getTextStyle() const
{
    return textStyle;
}

sf::Color Menu::getTextColor() const
{
    return textColor;
}

sf::Color Menu::getHighlightColor() const
{
    return highlightColor;
}

sf::Sound Menu::getHighlightSound() const
{
    return highlightSound;
}

//Help Functions
void Menu::applyTextFont()
{
    if(txtArray != NULL)
    {
        for(int i = 0; i < arraySize; i++)
        {
            txtArray[i].setFont(sf::Font::getDefaultFont());
            txtArray[i].setFont(textFont);
        }
    }
}

void Menu::applyTextSize()
{
    if(txtArray != NULL)
    {
        for(int i = 0; i < arraySize; i++)
            txtArray[i].setCharacterSize(textSize);
    }
}

void Menu::applyTextStyle()
{
    if(txtArray != NULL)
    {
        for(int i = 0; i < arraySize; i++)
            txtArray[i].setStyle(textStyle);
    }
}

void Menu::applyTextColor()
{
    if(txtArray != NULL)
    {
        for(int i = 0; i < arraySize; i++)
            txtArray[i].setColor(textColor);
    }
}

void Menu::calculateGlobalBounds()
{
    if(txtArray != NULL)
    {
        int maxTextW = txtArray[0].getGlobalBounds().width;
        for(int i = 1; i < arraySize; i++)
            if(txtArray[i].getGlobalBounds().width > maxTextW) maxTextW = txtArray[i].getGlobalBounds().width;
        width =  maxTextW + 2*padding;
        height = padding;
        for(int i = 0; i < arraySize; i++)
            height += txtArray[i].getGlobalBounds().height + padding;
    }
}

void Menu::adjustMenu()
{
    applyTextFont();
    applyTextColor();
    applyTextSize();
    applyTextStyle();
    calculateGlobalBounds();
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
    if(txtArray != NULL)
    {
        txtArray[0].setPosition(padding + x + width / 2 - txtArray[0].getGlobalBounds().width / 2, y + padding);
        (*aWindow).draw(txtArray[0]);
        for(int i = 1; i < arraySize; i++)
        {
            txtArray[i].setPosition(padding + x + width / 2 - txtArray[i].getGlobalBounds().width / 2, txtArray[i - 1].getPosition().y + padding + txtArray[i - 1].getGlobalBounds().height);
            (*aWindow).draw(txtArray[i]);
        }
        //Text Highlight and Sound Play
        for(int i = 0; i < arraySize; i++)
        {
            if(textMouseOver(txtArray[i], aWindow))
            {
                txtArray[i].setColor(highlightColor);
                if(highlightSound.getStatus() != sf::Sound::Playing && i != rememberI)
                {
                    highlightSound.play();
                    rememberI = i;
                }
                break;
            }
            else
            {
                adjustMenu();
                if(i == rememberI)
                {
                    rememberI = -1;
                    //highlightSound.stop(); Add it for instant stop of the sound if mouse goes away from text.
                }
            }

        }
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
