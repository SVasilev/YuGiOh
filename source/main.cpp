#include <iostream>
#include <SFML/Graphics.hpp>

const double adjustPixelsConst = 4.0;

bool textMouseOver(sf::Text& aText, sf::RenderWindow* aWindow)
{
    if(sf::Mouse::getPosition(*aWindow).x >= aText.getPosition().x &&
       sf::Mouse::getPosition(*aWindow).x <= aText.getPosition().x + aText.getGlobalBounds().width &&
       sf::Mouse::getPosition(*aWindow).y >= (aText.getPosition().y + adjustPixelsConst) &&
       sf::Mouse::getPosition(*aWindow).y <= aText.getPosition().y + (aText.getGlobalBounds().height + adjustPixelsConst)) return true;
    return false;
}

bool isGameStarted = false;

int main()
{
    sf::RenderWindow MyGame(sf::VideoMode(1440, 900, 32), "MyGame", sf::Style::Fullscreen);

    sf::Text startGame("Start Game");
    startGame.setCharacterSize(25);
    startGame.setPosition((MyGame.getSize().x / 2) - (startGame.getGlobalBounds().width / 2) , MyGame.getSize().y / 1.4);
    startGame.setColor(sf::Color(0, 200, 200));

    sf::Text exitGame("Exit Game");
    exitGame.setCharacterSize(25);
    exitGame.setPosition((MyGame.getSize().x / 2) - (exitGame.getGlobalBounds().width / 2) , MyGame.getSize().y / 1.1);
    exitGame.setColor(sf::Color(0, 200, 200));

    sf::Texture texBackground;
    texBackground.loadFromFile("D:\\Programming\\Git\\YuGiOh\\assets\\egyptian.png");
    sf::Sprite sprBackground;
    sprBackground.setTexture(texBackground);
    //D:\\Programming\\Git\\YuGiOh\\assets\\Table.png

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
                case sf::Event::MouseButtonPressed:
                {
                    if(textMouseOver(startGame, &MyGame))
                    {
                        isGameStarted = true;
                        texBackground.loadFromFile("D:\\Programming\\Git\\YuGiOh\\assets\\Table.png");
                    }
                    if(textMouseOver(exitGame, &MyGame)) MyGame.close();
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {
                            MyGame.close();
                        }
                    }
                }
            }
        }
        MyGame.clear();
        if(textMouseOver(startGame, &MyGame))
        {
            startGame.setColor(sf::Color(0, 100, 200));
        }
        else startGame.setColor(sf::Color(0, 200, 200));
        if(textMouseOver(exitGame, &MyGame))
        {
            exitGame.setColor(sf::Color(0, 100, 200));
        }
        else exitGame.setColor(sf::Color(0, 200, 200));


        MyGame.draw(sprBackground);
        if(!isGameStarted)
        {
            MyGame.draw(startGame);
            MyGame.draw(exitGame);
        }
        MyGame.display();
    }
    return 0;
}
