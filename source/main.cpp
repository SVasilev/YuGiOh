#include <iostream>
#include <SFML/Graphics.hpp>

const int rectangleWidth = 200;
const int rectangleHeight = 30;
const int circleW_H = 100;

int main()
{
    sf::RenderWindow MyGame(sf::VideoMode(800, 600, 32), "MyGame", sf::Style::Close);
    sf::Clock timer;

    int ballsCatched = 0;

    /*sf::Text ballsText("Balls catched");
    ballsText.setCharacterSize(16);
    ballsText.setPosition(650, 0);
    sf::Text ballsCount("0");
    ballsCount.setCharacterSize(16);
    ballsCount.setPosition(750, 0);*/

    int millisecondsInterval = 3;
    sf::Texture texBall;
    texBall.loadFromFile("ball.png");
    sf::Sprite ball;
    ball.setTexture(texBall);
    ball.setPosition(300, 30);

    sf::Texture texRect;
    texRect.loadFromFile("rect.png");
    sf::Sprite rectangle;
    rectangle.setTexture(texRect);
    rectangle.setPosition(300, 570);
    while(MyGame.isOpen())
    {
        if(ballsCatched >= 15 && ballsCatched < 30 && millisecondsInterval == 3) millisecondsInterval--;
        if(ballsCatched >= 30 && ballsCatched < 45 && millisecondsInterval == 2) millisecondsInterval--;
        sf::Time elapsed = timer.getElapsedTime();
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
                case sf::Event::KeyPressed:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Left:
                        {
                            rectangle.move(-15, 0); break;
                        }
                        case sf::Keyboard::Right:
                        {
                            rectangle.move(15, 0); break;
                        }
                    }
                }
            }
        }
        int microseconds = timer.getElapsedTime().asMicroseconds();
        if(timer.getElapsedTime().asMilliseconds() > millisecondsInterval)
        {
            ball.move(0, 1);
            if(ball.getPosition().y == rectangle.getPosition().y - circleW_H &&
               ball.getPosition().x >= rectangle.getPosition().x - circleW_H &&
               ball.getPosition().x <= rectangle.getPosition().x + rectangleWidth)
            {
                ballsCatched++;
                microseconds = (microseconds % 1000) * 2;
                if(microseconds <= MyGame.getSize().x - circleW_H) ball.setPosition(microseconds, 30);
                else ball.setPosition(0, 30);
            }
            else
            {
                if(ball.getPosition().y >= rectangle.getPosition().y - circleW_H + rectangleHeight) MyGame.close();
            }
            timer.restart();
        }
        MyGame.clear();
        /*MyGame.draw(ballsCount);
        MyGame.draw(ballsText);*/
        MyGame.draw(ball);
        MyGame.draw(rectangle);
        MyGame.display();
    }
    std::cout << "You catched " << ballsCatched;
    if(ballsCatched != 1) std::cout << " balls.\n";
    else std::cout << " ball.\n";
    system("pause");
    return 0;
}
