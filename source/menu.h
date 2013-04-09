#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>

class Menu
{
private:
    int x, y, arraySize, textSize, width, height; //Padding is the space between every text.
    double padding;
    sf::Text* txtArray;
    sf::Font textFont;
    sf::Color highlightColor, textColor;
public:
    Menu(sf::Text* array = NULL, int arrSize = 0, sf::Font aFont = sf::Font::getDefaultFont(), int xCoor = 0, int yCoor = 0, double pad = 5, int txtSize = 25, sf::Color textCol = sf::Color::White, sf::Color highlightCol = sf::Color::White);//, int w = 0, int h = 0); If you go pro...
    ~Menu();
    //Setters
    void setArr(sf::Text* newArr, int size);
    void setTextFont(sf::Font aFont); //Broken, because of SFML.
    void setPosition(int left, int top);
    void setPadding(int pad);
    void setTextSize(int size);
    void setTextColor(sf::Color aColor);
    void setHighlightColor(sf::Color aColor);
    //Getters
    sf::Text* getTextArray() const;
    sf::Font getTextFont() const;
    int getX() const;
    int getY() const;
    int getTextArraySize() const;
    int getPadding() const;
    int getTextSize() const;
    sf::Color getTextColor() const;
    sf::Color getHighlightColor() const;
    //Help Functions
    void applyTextSize();
    void applyTextFont();
    void applyTextColor();
    void calculateGlobalBounds();
    int getWidth() const;
    int getHeight() const;
    void display(sf::RenderWindow* aWindow);
};

//Help Functions
bool textMouseOver(sf::Text& aText, sf::RenderWindow* aWindow);

#endif // MENU_H_INCLUDED
