#ifndef CARD_H
#define CARD_H

const int CARD_X = 180;
const int CARD_Y = 240;

class Card
{
    private:
        sf::Sprite overlay;

        std::string name;
        //std::ifstream cardList;
        //int player;

    public:
        Card();

        void setImage(std::string imagePath);
        //void readData(istringstream &cardList);
        void loadOverlay(sf::Image overlay);
        void displayCard(sf::Texture& texture, sf::Texture& art, sf::RenderWindow * window);
        //void moveCard();
};


#endif
