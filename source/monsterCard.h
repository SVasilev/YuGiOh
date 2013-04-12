#ifndef MONSTER_CARD_H
#define MONSTER_CARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

class MonsterCard
{
    private:

        static sf::Texture staticOverlay;
        sf::Sprite overlay;
        sf::Sprite image;

        std::string monsterName;
        sf::Text MonsterName;

        int attack;
        sf::Text Attack;

        int defense;
        sf::Text Defense;

        int manaGive;
        sf::Text ManaGive;

        int costToSummon;
        sf::Text CostToSummon;

        bool dragging;

    public:

        //initialize the common overlay texture
        //call MonsterCard::setOverlay("path") at the start of main()
        static void setOverlay(const std::string &overlayPath)
        {
            if(!staticOverlay.loadFromFile(overlayPath))
            {
                std::cout << "DEBUG_MESSAGE: Failed to load static overlay (" << overlayPath << ")" << std::endl;
            }
        }

        //constructors
        MonsterCard();
        MonsterCard(const sf::Texture& art,const std::string& str_name, int attack, int defense, int manaGive, int costToSummon);

        //get
        std::string getName() const;
        int getAttack() const;
        int getDefense() const;
        int getManaGive() const;
        int getCostToSummon() const;
        sf::Sprite getOverlay() const;
        sf::Sprite getImage() const;
        bool isDragging() const;

        sf::Vector2f getCardPostion() const;

        //set
        void setAttack(const int &dmg);
        void setDefense(const int &def);
        void setManaGive(const int &mana);
        void setCostToSummon(const int &cost);

        //other
        void displayMonsterCard(sf::RenderWindow * window = NULL, double scale_x = 1, double scale_y = 1);
        bool mouseOverCard(const sf::Sprite &sprite, sf::RenderWindow* aWindow);
        void moveCard(sf::RenderWindow * window);


        //helpers
        std::string int_to_string(const int &num);
        void setTextFont(sf::Font& aFont);
        void setTextColor(sf::Color aColor);
        void setTextStyle(sf::Text::Style aStyle);
        void scaleElements(double scale_x, double scale_y);
        void drawElements(sf::RenderWindow * window);

};


#endif
