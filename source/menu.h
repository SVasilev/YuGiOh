#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu
{
private:
    int x, y, arraySize, textSize, width, height;
    double padding;
    sf::Text* txtArray;
    sf::Font textFont;
    sf::Color highlightColor, textColor;
    sf::Text::Style textStyle;
    sf::Sound highlightSound;
public:
    Menu(sf::Text* array = NULL, int arrSize = 0);
    ~Menu();
    //Setters
    void setArr(sf::Text* newArr, int size);
    void setPosition(int left, int top);
    void setPadding(int pad);
    void setTextFont(sf::Font aFont);
    void setTextSize(int size);
    void setTextStyle(sf::Text::Style aStyle);
    void setTextColor(sf::Color aColor);
    void setHighlightColor(sf::Color aColor);
    void setHighlightSound(sf::Sound aSound);
    //Getters
    sf::Text* getTextArray() const;
    int getX() const;
    int getY() const;
    int getTextArraySize() const;
    int getPadding() const;
    sf::Font getTextFont() const;
    int getTextSize() const;
    sf::Text::Style getTextStyle() const;
    sf::Color getTextColor() const;
    sf::Color getHighlightColor() const;
    sf::Sound getHighlightSound() const;
    //Help Functions
    void applyTextFont();
    void applyTextSize();
    void applyTextStyle();
    void applyTextColor();
    void calculateGlobalBounds();
    void adjustMenu();
    int getWidth() const;
    int getHeight() const;
    void display(sf::RenderWindow* aWindow);
};

//Help Functions
bool textMouseOver(sf::Text& aText, sf::RenderWindow* aWindow);

#endif // MENU_H_INCLUDED
