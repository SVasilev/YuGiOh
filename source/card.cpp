#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "card.h"

Card::Card()
{
    name = "<empty>";
}

void Card::displayCard(sf::Texture& overlay, sf::Texture& art, sf::RenderWindow * window)
{
    sprite.setTexture(texture);
    (*window).draw(overlay);
}


