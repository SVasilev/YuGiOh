#ifndef HEALTHMANA_H_INCLUDED
#define HEALTHMANA_H_INCLUDED

#include <SFML/Graphics.hpp>

class HealthMana
{
private:
    int health, mana;
    sf::Text healthTxt, manaTxt, separatorTxt;
public:
    HealthMana(int h = 0, int m = 0);
    //Setters
    void setHealth(int h);
    void setMana(int m);
    void setPosition(int x, int y);
    void setTextSize(int size);
    void setTextFont(sf::Font& aFont);
    void setTextColor(sf::Color healthColor, sf::Color dashColor, sf::Color manaColor);
    void setTextStyle(sf::Text::Style aStyle);
    //Getters
    int getHealth() const;
    int getMana() const;
    //Help Functions
    void display(sf::RenderWindow& aWindow);
    void boundAttributesToText();
};

//Help Functions
int numberLen(int number);

#endif // HEALTHMANA_H_INCLUDED
