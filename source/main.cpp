#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"
#include "monsterCard.h"
#include "spellCard.h"
#include "player.h"

void loadTextures(std::vector<sf::Texture> &vect1, std::ifstream &data)
{
    std::string str_fill;
    std::string texturePath;
    int int_fill;
    while (!data.eof())
    {
        data >> str_fill >> texturePath >> int_fill >> int_fill >> int_fill >> int_fill;
        sf::Texture texture;
        texture.loadFromFile(texturePath);
        vect1.push_back(texture);
    }

    data.clear();
    data.seekg(0, std::ios::beg);
}

int main()
{
    sf::RenderWindow MyGame(sf::VideoMode(800, 600, 32), "MyGame", sf::Style::Default);
    MonsterCard::setOverlay("assets/borders.png", "assets/backside.png");
    SpellCard::setSpellOverlay("assets/borders.png", "assets/backside.png");

    MyGame.setMouseCursorVisible(false);
    sf::Texture txtCursor;
    txtCursor.loadFromFile("assets/animaatjes_the_legend_of_zelda_icon6.gif");
    sf::Sprite sprCursor(txtCursor);

    std::ifstream cardData;
    cardData.open("monsterData.txt");
    if(cardData.fail())
    {
        std::cout << "FAILED TO LOAD MONSTER DATA " << std::endl;
    }


    std::vector<MonsterCard> monsterVector;
    std::vector<sf::Texture> textureVector;
    loadTextures(textureVector, cardData);
    std::string line;
    int counter = 0;
    while (getline(cardData, line))
    {
        MonsterCard monster2(textureVector[counter], line);
        monsterVector.push_back(monster2);
        counter++;
    }

    monsterVector[0].setCardPosition(350,350);
    monsterVector[1].setCardPosition(150,150);
    monsterVector[2].setCardPosition(300,300);
    monsterVector[0].flipCard();
    monsterVector[2].rotateCard(180);

    SpellCard s1("Diariq");
    SpellCard s2("Determinizym");
    s1.setPosition(50,50);
    s1.flipCard();
    s2.setPosition(10, 10);

    //A simple example of how Menu class works.
    sf::Text* txtArr = new sf::Text[5];
    txtArr[0].setString("Start Game");
    txtArr[1].setString("Load Game");
    txtArr[2].setString("Options");
    txtArr[3].setString("Credits");
    txtArr[4].setString("Exit Game");

    sf::Text* txtArr1 = new sf::Text[3];
    txtArr1[0].setString("Simple Text");
    txtArr1[1].setString("Simple Text");
    txtArr1[2].setString("Simple Text");

    sf::Font sargoePrint;
    sargoePrint.loadFromFile("assets/segoepr.ttf");

    sf::SoundBuffer aBuffer;
    aBuffer.loadFromFile("assets/button-6.wav");
    sf::Sound simpleSound(aBuffer);
    simpleSound.setVolume(0);

    Menu menu1(txtArr1, 3);

    menu1.setArr(txtArr, 5);
    menu1.setPosition(270, 140);
    menu1.setPadding(20);
    menu1.setTextFont(sargoePrint);
    menu1.setTextSize(30);
    menu1.setTextStyle(sf::Text::Italic);
    menu1.setTextColor(sf::Color(200, 100, 300));
    menu1.setHighlightColor(sf::Color(250, 200, 300));
    menu1.setHighlightSound(simpleSound);

    //A simple example of how Player class works.
    Player player1("Asan Baba");
    sf::Texture simpleTexture;
    simpleTexture.loadFromFile("assets/herpaDerpa.png");
    player1.setPortrait(simpleTexture);

    player1.getHealthManaBar().setPosition(600, 550);
    player1.getHealthManaBar().setTextFont(sargoePrint);
    player1.getHealthManaBar().setTextColor(sf::Color::Red, sf::Color::Green, sf::Color::Blue);

    player1.getNameTxt().setFont(sargoePrint);
    player1.getNameTxt().setPosition(30, 550);

    player1.getPortraitSprite().setPosition(40, 400);

    player1.setHealth(1200);
    player1.setMana(800);

    while(MyGame.isOpen())
    {
        sf::Event event;
        while(MyGame.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    MyGame.close();
                    break;
                }
                case sf::Event::MouseButtonReleased:
                {
                    switch(menu1.clickIndex(MyGame))
                    {
                        case -1:
                        {
                            std::cout << "Nothing Clicked\n";
                            break;
                        }
                        case 0:
                        {
                            std::cout << "Start Game Clicked\n";
                            break;
                        }
                        case 1:
                        {
                            std::cout << "Load Game Clicked\n";
                            break;
                        }
                        case 2:
                        {
                            std::cout << "Options Clicked\n";
                            break;
                        }
                        case 3:
                        {
                            std::cout << "Credit Clicked\n";
                            break;
                        }
                        case 4:
                        {
                            std::cout << "Exit Game Clicked\n";
                            break;
                        }
                    }
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    sprCursor.setPosition(event.mouseMove.x - sprCursor.getGlobalBounds().width / 3, event.mouseMove.y - sprCursor.getGlobalBounds().height / 3.3);
                    break;
                }

            }
        }
        MyGame.clear();
        menu1.display(&MyGame);
        player1.display(MyGame);
        monsterVector[1].displayMonsterCard(&MyGame, 0.5, 0.5);
        //monsterVector[2].displayMonsterCard(&MyGame);
        //monsterVector[0].displayMonsterCard(&MyGame);
        s1.displaySpellCard(&MyGame, 0.5, 0.5);
        MyGame.draw(sprCursor);
        MyGame.display();
        //MyGame.close();
    }
    return 0;
}
