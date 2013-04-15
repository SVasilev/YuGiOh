#include "spellCard.h"

sf::Texture SpellCard::staticOverlay;
//constructors
SpellCard::SpellCard()
{
    overlay.setTexture(staticOverlay);
    spellName = "<empty>";
    SpellName.setString(spellName);
    description.setString("No description");
    modCount = 0;
    monsterMod = false;
    playerMod = false;
    slotMod = false;
    dragging = false;

    attMod = 0;
    defMod = 0;
    manaGiveMod = 0;
    healthMod = 0;
    manaMod = 0;
    remove = 0;
}

SpellCard::SpellCard(const sf::Texture &art, const std::string &line)
{
    overlay.setTexture(staticOverlay);
    image.setTexture(art);
    std::istringstream strm;
    strm.str(line);
    std::string fill;
    strm >> spellName >> fill >> modCount;
    int * temp = new int[modCount];
    //fix order in which elements are assigned to correspond to text file.
    for (int k = 0; k < modCount; k++)
    {
        strm >> temp[k];
        switch (temp[k])
        {
            case 0:
                monsterMod = true;
                strm >> attMod >> defMod >> manaGiveMod;
                break;
            case 1:
                playerMod = true;
                strm >> healthMod >> manaMod;
                break;
            case 2:
                slotMod = true;
                strm >> remove;
                break;
        }
    }
    delete[] temp;

    //must set the unspecified values in the .txt to zero
    //FINISH FUNCTION FOR CREATING DESCRIPTION>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //FUNCTION FOR FORMATTING DESCRIPTION>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

SpellCard::SpellCard(const std::string lainovoz)
{
    overlay.setTexture(staticOverlay);
    spellName = lainovoz;
    SpellName.setString(spellName);
}


//set
void SpellCard::setImage(const sf::Texture &art)
{
    image.setTexture(art);
}

void SpellCard::setModCount(const int &num)
{
    modCount = num;
}

void SpellCard::setMonsterMod(const bool &b)
{
    monsterMod = b;
}

void SpellCard::setPlayerMod(const bool &b)
{
    playerMod = b;
}

void SpellCard::setSlotMod(const bool &b)
{
    slotMod = b;
}

void SpellCard::setDragging(const bool &b)
{
    dragging = b;
}

void SpellCard::setAttMod(const int &num)
{
    attMod = num;
}

void SpellCard::setDefMod(const int &num)
{
    defMod = num;
}

void SpellCard::setManaGiveMod(const int &num)
{
    manaGiveMod = num;
}

void SpellCard::setHealthMod(const int &num)
{
    healthMod = num;
}

void SpellCard::setManaMod(const int &num)
{
    manaMod = num;
}

void SpellCard::setRemove(const int &num)
{
    remove = num;
}

void SpellCard::setPosition(const float &x, const float &y)
{
    overlay.setPosition(x, y);
    float card_x = overlay.getPosition().x;
    float card_y = overlay.getPosition().y;
    SpellName.setPosition(card_x + 10, card_y + 5);
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}

//get
sf::Sprite SpellCard::getOverlay() const
{
    return overlay;
}

sf::Sprite SpellCard::getImage() const
{
    return image;
}

sf::Text& SpellCard::getDescription()
{
    return description;
}

std::string SpellCard::getSpellName() const
{
    return spellName;
}

sf::Text& SpellCard::getSpellNameTxt()
{
    return SpellName;
}

int SpellCard::getModCount() const
{
    return modCount;
}

bool SpellCard::getMonsterMod() const
{
    return monsterMod;
}

bool SpellCard::getPlayerMod() const
{
    return playerMod;
}

bool SpellCard::getSlotMod() const
{
    return slotMod;
}

bool SpellCard::isDragging() const
{
    return dragging;
}

int SpellCard::getAttMod() const
{
    return attMod;
}

int SpellCard::getDefMod() const
{
    return defMod;
}

int SpellCard::getManaGiveMod() const
{
    return manaGiveMod;
}

int SpellCard::getHealthMod() const
{
    return healthMod;
}

int SpellCard::getManaMod() const
{
    return manaMod;
}

int SpellCard::getRemove() const
{
    return remove;
}

float SpellCard::getWidth() const
{
    return overlay.getGlobalBounds().width;
}

float SpellCard::getHeight() const
{
    return overlay.getGlobalBounds().height;
}
//others
void SpellCard::displaySpellCard(sf::RenderWindow * window, double scale_x, double scale_y)
{
    float card_x = overlay.getPosition().x;
    float card_y = overlay.getPosition().y;
    SpellName.setPosition(card_x + 10, card_y + 5);
    SpellName.setColor(sf::Color::Black);
    SpellName.setCharacterSize(25);
    (*window).draw(overlay);
    (*window).draw(SpellName);
}


//helpers






