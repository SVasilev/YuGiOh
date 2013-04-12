#include <iostream>
#include <cstring>

#include "healthMana.h"

HealthMana::HealthMana(int h, int m)
{
    setHealth(h);
    setMana(m);
}

//Setters
void HealthMana::setPosition(int x, int y)
{
    healthTxt.setPosition(x, y);
}

void HealthMana::setHealth(int h)
{
    health = h;
}

void HealthMana::setMana(int m)
{
    mana = m;
}

void HealthMana::setTextSize(int size)
{
    separatorTxt.setCharacterSize(size);
    healthTxt.setCharacterSize(size);
    manaTxt.setCharacterSize(size);
}

void HealthMana::setTextFont(sf::Font& aFont)
{
    separatorTxt.setFont(aFont);
    healthTxt.setFont(aFont);
    manaTxt.setFont(aFont);
}

void HealthMana::setTextColor(sf::Color healthColor, sf::Color dashColor, sf::Color manaColor)
{
    separatorTxt.setColor(dashColor);
    healthTxt.setColor(healthColor);
    manaTxt.setColor(manaColor);
}

void HealthMana::setTextStyle(sf::Text::Style aStyle)
{
    separatorTxt.setStyle(aStyle);
    healthTxt.setStyle(aStyle);
    manaTxt.setStyle(aStyle);
}

//Getters
int HealthMana::getHealth() const
{
    return health;
}

int HealthMana::getMana() const
{
    return mana;
}

//Help Functions
void HealthMana::display(sf::RenderWindow& aWindow)
{
    boundAttributesToText();
    aWindow.draw(healthTxt);
    separatorTxt.setPosition(healthTxt.getPosition().x + healthTxt.getGlobalBounds().width * 1.1, healthTxt.getPosition().y);
    manaTxt.setPosition(separatorTxt.getPosition().x + separatorTxt.getGlobalBounds().width, separatorTxt.getPosition().y);
    aWindow.draw(separatorTxt);
    aWindow.draw(manaTxt);
}

//Help Functions
void HealthMana::boundAttributesToText()
{
    char* temp = new char[numberLen(health) + 1];
    itoa(health, temp, 10);
    healthTxt.setString(temp);
    delete[] temp;
    temp = new char[numberLen(mana) + 1];
    itoa(mana, temp, 10);
    manaTxt.setString(temp);
    separatorTxt.setString("/");
}

int numberLen(int number)
{
    if(number == 0) return 0;
    return 1 + numberLen(number / 10);
}
