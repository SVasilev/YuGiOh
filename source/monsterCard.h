#ifndef MONSTER_CARD_H
#define MONSTER_CARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class MonsterCard
{
    private:
        static sf::Texture staticOverlay;
        static sf::Texture backside;
        static sf::Image overlayImg; //used for getting specific coordinates withing the card itself
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
        bool flipped;
        static sf::Vector2f NAME_BAR_ORIGIN;
        static sf::Vector2f NAME_BAR_BOUNDS;
        static sf::Vector2f IMAGE_ORIGIN;
        static sf::Vector2f IMAGE_BOUNDS;
        static sf::Vector2f STATS_ORIGIN;
        static sf::Vector2f STATS_BOUNDS;

    public:
        //constructors
        MonsterCard();
        MonsterCard(const sf::Texture& art,const std::string& line);
        //get
        std::string getName() const;
        int getAttack() const;
        int getDefense() const;
        int getManaGive() const;
        int getCostToSummon() const;
        sf::Text& getMonsterNameText();
        sf::Text& getAttackText();
        sf::Text& getDefenseText();
        sf::Text& getManaGiveText();
        sf::Text& getCostToSummonText();
        sf::Sprite getOverlay() const;
        sf::Sprite getImage() const;
        bool isDragging() const;
        bool isFlipped() const;
        sf::Vector2f getCardPosition() const;
        double getCardWidth() const;
        double getCardHeight() const;
        //set
        //initialize the common overlay texture
        //call MonsterCard::setOverlay("path1", "path2") at the start of main()
        static void setOverlay(const std::string &overlayPath, const std::string &backsidePath);
        void setImage(const sf::Texture& art);
        void setName(const std::string &str);
        void setAttack(const int &dmg);
        void setDefense(const int &def);
        void setManaGive(const int &mana);
        void setCostToSummon(const int &cost);
        void setCardPosition(const double &x, const double &y);
        void setCardPosition(const sf::Vector2f &vect);
        void setDragging(const bool &b);
        //other
        void flipCard();
        void rotateCard(const double &angle);
        void displayMonsterCard(sf::RenderWindow * window = NULL, double scale_x = 1, double scale_y = 1);
        bool mouseOverCard(const sf::Sprite &sprite, sf::RenderWindow* aWindow);
        void moveCard(sf::RenderWindow * window);
        //helpers
        std::string int_to_string(const int &num);
        void scaleElements(double scale_x, double scale_y);
        void drawElements(sf::RenderWindow * window);
        void rotateElements(const double &angle);
        static sf::Vector2f findOrigin(float startX, float startY);
        static sf::Vector2f findBounds(const sf::Vector2f &vect);
};
#endif
