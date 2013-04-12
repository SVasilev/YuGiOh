#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "healthMana.h"

class Player
{
private:
    char* name;
    //Card* cardsArray - must finish when Card class is ready.
    int health, mana, cardsNumber;
    sf::Sprite portraitImage;
    sf::Text nameTxt;
    HealthMana healthManaBar;

    void boundAtributesToText();
public:
    Player(char* aName);//, Card* cardsArr = NULL, cardsNum = 0);
    ~Player();
    //Setters
    void setName(char* aName);
    //void setCardsArr(Card* cardArr, int cardsNum);
    void setHealth(int hitPoints);
    void setMana(int manaPoints);
    void setPortrait(sf::Texture& portraitPic);
    //Getters
    char* getName() const;
    //Card* getCardsArr() const;
    int getHealth() const;
    int getMana() const;
    int getCardsNumber() const;
    //Object Getters
    sf::Text& getNameTxt();
    sf::Sprite& getPortraitSprite();
    HealthMana& getHealthManaBar();
    //Help Functions
    void display(sf::RenderWindow& aWindow);
    void shuffleCards();
};

//Help Functions


#endif // PLAYER_H_INCLUDED
