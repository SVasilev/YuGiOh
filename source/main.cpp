#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

<<<<<<< HEAD
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
=======
const int rectangleWidth = 200;
const int rectangleHeight = 30;
const int circleW_H = 160;

int rand_x(sf::RenderWindow &MyGame)
{
    int result = rand() % (MyGame.getSize().x - circleW_H + 1);
    return result;
}

int main()
{
    srand(time(0));
    sf::RenderWindow MyGame(sf::VideoMode(800, 600, 32), "MyGame", sf::Style::Close);
    sf::Clock timer;
>>>>>>> 3be5a4e44f96ddf6541369388a86e6577906d97d

    sf::Text startGame("Start Game");
    startGame.setCharacterSize(25);
    startGame.setPosition((MyGame.getSize().x / 2) - (startGame.getGlobalBounds().width / 2) , MyGame.getSize().y / 1.4);
    startGame.setColor(sf::Color(0, 200, 200));

    sf::Text exitGame("Exit Game");
    exitGame.setCharacterSize(25);
    exitGame.setPosition((MyGame.getSize().x / 2) - (exitGame.getGlobalBounds().width / 2) , MyGame.getSize().y / 1.1);
    exitGame.setColor(sf::Color(0, 200, 200));

<<<<<<< HEAD
    sf::Texture texBackground;
    texBackground.loadFromFile("D:\\Programming\\Git\\YuGiOh\\assets\\egyptian.png");
    sf::Sprite sprBackground;
    sprBackground.setTexture(texBackground);
    //D:\\Programming\\Git\\YuGiOh\\assets\\Table.png

=======
    int millisecondsInterval = 3;
    sf::Texture texBall;
    texBall.loadFromFile("D:\\Cpp\\Git\\YuGiOh\\assets\\dedovina.png");
    sf::Sprite ball;
    ball.setTexture(texBall);
    ball.setPosition(300, 30);

    sf::Texture texRect;
    texRect.loadFromFile("D:\\Cpp\\Git\\YuGiOh\\assets\\rect.png");
    sf::Sprite rectangle;
    rectangle.setTexture(texRect);
    rectangle.setPosition(300, 570);
>>>>>>> 3be5a4e44f96ddf6541369388a86e6577906d97d
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
<<<<<<< HEAD
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
=======
            ball.move(0, 1);
            if(ball.getPosition().y == rectangle.getPosition().y - circleW_H &&
               ball.getPosition().x >= rectangle.getPosition().x - circleW_H &&
               ball.getPosition().x <= rectangle.getPosition().x + rectangleWidth)
            {
                ballsCatched++;
                microseconds = rand_x(MyGame);
                if(microseconds <= MyGame.getSize().x - circleW_H) ball.setPosition(microseconds, 30);
                else ball.setPosition(0, 30);
            }
            else
            {
                if(ball.getPosition().y >= rectangle.getPosition().y - circleW_H + rectangleHeight) MyGame.close();
            }
            timer.restart();
>>>>>>> 3be5a4e44f96ddf6541369388a86e6577906d97d
        }
        MyGame.display();
    }
    return 0;
}
