#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include "player.h"

Player::Player(char* aName)//, Card* cardsArr, cardsNum)
{
    name = NULL;
    //cardsArray = NULL;
    //cardsNumber = cardsNum;
    setName(aName);
    setHealth(0);
    setMana(0);
    shuffleCards();
}

Player::~Player()
{
    delete[] name;
    //delete[] cardsArray;
}

//Setters
void Player::setName(char* aName)
{
    if(name != NULL) delete[] name;
    name = new char[strlen(aName) + 1];
    name[strlen(aName)] = '\0';
    strcpy(name, aName);
}

/*
void Player::setCardsArr(Card* cardsArr, int cardsNum)
{
    if(cardsArray != NULL) delete[] cardsArray;
    cardsArray = new Card[cardsNum];
    for(int i = 0; i < cardsNum; i++)
        cardsArray[i] = cardsArr[i]; // -> Works only if Stoyan wrote a good operator=
    cardsNumber = cardsNum;
}
*/

void Player::setHealth(int hitPoints)
{
    health = hitPoints;
}

void Player::setMana(int manaPoints)
{
    mana = manaPoints;
}

void Player::setPortrait(sf::Texture& portraitPic)
{
    portraitImage.setTexture(portraitPic);
}

//Getters
char* Player::getName() const
{
    return name;
}

int Player::getHealth() const
{
    return health;
}

int Player::getMana() const
{
    return mana;
}

int Player::getCardsNumber() const
{
    return cardsNumber;
}

//Object getters
sf::Text& Player::getNameTxt()
{
    return nameTxt;
}

sf::Sprite& Player::getPortraitSprite()
{
    return portraitImage;
}

HealthMana& Player::getHealthManaBar()
{
    return healthManaBar;
}

//Help Functions
void Player::display(sf::RenderWindow& aWindow)
{
    boundAtributesToText();
    aWindow.draw(portraitImage);
    aWindow.draw(nameTxt);
    healthManaBar.display(aWindow);
}

void Player::boundAtributesToText()
{
    nameTxt.setString(name);
    healthManaBar.setHealth(health);
    healthManaBar.setMana(mana);
}

void Player::shuffleCards()
{
    srand(time(NULL));
    int* arr = new int[40 /*cards number*/];
    for(int i = 0; i < 40 /*cards number*/;i++)
    {
        int temp = rand() % 40 /*cards number*/;
        for(int j = 0; j < i; j++)
        {
            if(temp == arr[j])
            {
                temp = rand() % 40 /*cards number*/;
                j = -1;
            }
        }
        arr[i] = temp;
    }
    for(int i = 0; i < 40 /*cards number*/; i++)
        std::cout << arr[i] << "\n";
}
