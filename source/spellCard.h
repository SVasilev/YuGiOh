#ifndef SPELL_CARD_H
#define SPELL_CARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class SpellCard
{
    private:
        static sf::Texture staticOverlay;
        static sf::Texture backside;
        sf::Sprite overlay;
        sf::Sprite image;
        sf::Text description;
        std::string spellName;
        sf::Text SpellName;

        int modCount;
        bool monsterMod;
        bool playerMod;
        bool slotMod;
        bool dragging;
        bool flipped;

        int attMod;
        int defMod;
        int manaGiveMod;
        int healthMod;
        int manaMod;
        int remove;

    public:
        //constructors
        SpellCard();
        SpellCard(const sf::Texture &art, const std::string &line);
        SpellCard(const std::string lainovoz);                 //just for testing with other classes
        //set
        void setImage(const sf::Texture &art);
        void setModCount(const int &num);
        void setMonsterMod(const bool &b);
        void setPlayerMod(const bool &b);
        void setSlotMod(const bool &b);
        void setDragging(const bool &b);
        void setAttMod(const int &num);
        void setDefMod(const int &num);
        void setManaGiveMod(const int &num);
        void setHealthMod(const int &num);
        void setManaMod(const int &num);
        void setRemove(const int &num);
        void setPosition(const float &x, const float &y);   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        void setPosition(const sf::Vector2f &vect);         //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        //get
        sf::Sprite getOverlay() const;
        sf::Sprite getImage() const;
        sf::Text& getDescription();
        std::string getSpellName() const;
        sf::Text& getSpellNameTxt();
        int getModCount() const;
        bool getMonsterMod() const;
        bool getPlayerMod() const;
        bool getSlotMod() const;
        bool isDragging() const;
        bool isFlipped() const;
        int getAttMod() const;
        int getDefMod() const;
        int getManaGiveMod() const;
        int getHealthMod() const;
        int getManaMod() const;
        int getRemove() const;
        float getWidth() const;
        float getHeight() const;
        sf::Vector2f getCardPosition() const;
        //others
        //call SpellCard::setSpellOverlay("path1", "path2") at the start of main()
        static void setSpellOverlay(const std::string &overlayPath, const std::string &backsidePath);
        void flipCard();
        void displaySpellCard(sf::RenderWindow * window, double scale_x = 1, double scale_y = 1);   //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        bool mouseOverCard(const sf::Sprite &sprite, sf::RenderWindow * window);
        void moveCard(sf::RenderWindow * window);
        //helpers
        void scaleElements(double scale_x, double scale_y);
        void drawElements(sf::RenderWindow * window);
        void makeDescription();
        void formatDescription();

};
#endif
