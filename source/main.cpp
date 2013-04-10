#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

int main()
{

    sf::Texture aTexture;
    aTexture.loadFromFile("assets/ball.png");
    sf::RenderWindow MyGame(sf::VideoMode(800, 600, 32), "MyGame", sf::Style::Close);

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
        MyGame.display();
    }
    return 0;
}
