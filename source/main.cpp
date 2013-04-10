#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"

int main()
{
    sf::RenderWindow MyGame(sf::VideoMode(800, 600, 32), "MyGame", sf::Style::Default);

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
            }
        }
        MyGame.clear();
        menu1.display(&MyGame);
        MyGame.display();
    }
    return 0;
}
