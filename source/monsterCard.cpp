#include "monsterCard.h"

sf::Texture MonsterCard::staticOverlay;

MonsterCard::MonsterCard()
{
    overlay.setTexture(staticOverlay);
    MonsterName.setString("<empty>");
    MonsterName.setColor(sf::Color::Black);
    MonsterName.setCharacterSize(20);              //create size global variable
    attack = 0;
    Attack.setString("0");
    manaGive = 0;
    ManaGive.setString("0");
    defense = 0;
    Defense.setString("0");
    costToSummon = 0;
    CostToSummon.setString("0");

    dragging = false;
}

MonsterCard::MonsterCard(const sf::Texture& art,const std::string& line)
{
    std::istringstream strm;
    strm.str(line);
    std::string str_name;
    std::string fill;
    int att = -1;
    int def = -1;
    int mana = -1;
    int cost = -1;

    strm >> str_name >> fill >> att >> def >> mana >> cost;

    overlay.setTexture(staticOverlay);
    image.setTexture(art);

    monsterName = str_name;
    MonsterName.setString(monsterName);
    MonsterName.setColor(sf::Color::Black);
    MonsterName.setCharacterSize(20);           //create SIZE global variable


    attack = att;
    Attack.setString(int_to_string(attack));
    Attack.setColor(sf::Color::Black);

    defense = def;
    Defense.setString(int_to_string(defense));
    Defense.setColor(sf::Color::Black);

    manaGive = mana;
    ManaGive.setString(int_to_string(manaGive));
    ManaGive.setColor(sf::Color::Black);

    costToSummon = cost;
    CostToSummon.setString(int_to_string(costToSummon));
    CostToSummon.setColor(sf::Color::Black);

    dragging = false;
}

std::string MonsterCard::getName() const
{
    return monsterName;
}

int MonsterCard::getAttack() const
{
    return attack;
}

int MonsterCard::getDefense() const
{
    return defense;
}

int MonsterCard::getManaGive() const
{
    return manaGive;
}

int MonsterCard::getCostToSummon() const
{
    return costToSummon;
}

sf::Text& MonsterCard::getMonsterNameText()
{
    return MonsterName;
}

sf::Text& MonsterCard::getAttackText()
{
    return Attack;
}

sf::Text& MonsterCard::getManaGiveText()
{
    return ManaGive;
}

sf::Text& MonsterCard::getDefenseText()
{
    return Defense;
}

sf::Text& MonsterCard::getCostToSummonText()
{
    return CostToSummon;
}

sf::Sprite MonsterCard::getOverlay() const
{
    return overlay;
}

sf::Sprite MonsterCard::getImage() const
{
    return image;
}

bool MonsterCard::isDragging() const
{
    return dragging;
}

sf::Vector2f MonsterCard::getCardPostion() const
{
    sf::Vector2f position(overlay.getPosition().x, overlay.getPosition().y);
    return position;
}

void MonsterCard::setImage(const sf::Texture &art)
{
    image.setTexture(art);
}

void MonsterCard::setAttack(const int &dmg)
{
    attack = dmg;
    Attack.setString(int_to_string(attack));
}

void MonsterCard::setDefense(const int &def)
{
    defense = def;
    Defense.setString(int_to_string(defense));
}

void MonsterCard::setManaGive(const int &mana)
{
    manaGive = mana;
    ManaGive.setString(int_to_string(manaGive));
}

void MonsterCard::setCostToSummon(const int &cost)
{
    costToSummon = cost;
    CostToSummon.setString(int_to_string(costToSummon));
}

void MonsterCard::setCardPosition(const int &x, const int &y)
{
    overlay.setPosition(x, y);
    float card_x = overlay.getPosition().x;
    float card_y = overlay.getPosition().y;

    MonsterName.setPosition(card_x + 10, card_y + 5);
    image.setPosition(card_x + 5, card_y + 37);
    Attack.setPosition(card_x + 15 , card_y + 180);
    ManaGive.setPosition(card_x + 80, card_y + 180);
    Defense.setPosition(card_x + 150, card_y + 180);
    CostToSummon.setPosition(card_x + 150, card_y + 1);

}

void MonsterCard::displayMonsterCard(sf::RenderWindow * window, double scale_x, double scale_y)
{
    //must decide on actuall card size and come up for placing algorithms
    //maybe use a constant sized border between the elements for the formula
    float card_x = overlay.getPosition().x;
    float card_y = overlay.getPosition().y;

    MonsterName.setPosition(card_x + 10, card_y + 5);
    image.setPosition(card_x + 5, card_y + 37);
    Attack.setPosition(card_x + 15 , card_y + 180);
    ManaGive.setPosition(card_x + 80, card_y + 180);
    Defense.setPosition(card_x + 150, card_y + 180);
    CostToSummon.setPosition(card_x + 150, card_y + 1);

    scaleElements(scale_x, scale_y);

    drawElements(window);
}

bool MonsterCard::mouseOverCard(const sf::Sprite &sprite, sf::RenderWindow* aWindow)
{
    if(sf::Mouse::getPosition(*aWindow).x >= sprite.getPosition().x &&
       sf::Mouse::getPosition(*aWindow).x <= sprite.getPosition().x + sprite.getGlobalBounds().width &&
       sf::Mouse::getPosition(*aWindow).y >= sprite.getPosition().y &&
       sf::Mouse::getPosition(*aWindow).y <= sprite.getPosition().y + sprite.getGlobalBounds().height) return dragging = true;
    return dragging = false;
}



//NOT WORKING PROPERLY
void MonsterCard::moveCard(sf::RenderWindow * window)
{
    sf::Vector2f startPos = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f pos = sf::Vector2f((float)sf::Mouse::getPosition(*window).x, (float)sf::Mouse::getPosition(*window).y);
    if(!dragging)
    {
        startPos = pos;
    }


    if(dragging)
    {
        overlay.setPosition(pos.x - startPos.x, pos.y - startPos.y);
        MonsterName.setPosition(overlay.getPosition().x + 10, overlay.getPosition().y + 5);
        image.setPosition(overlay.getPosition().x + 5, overlay.getPosition().y + 37);
        Attack.setPosition(overlay.getPosition().x + 15 , overlay.getPosition().y + 180);
        ManaGive.setPosition(overlay.getPosition().x + 80, overlay.getPosition().y + 180);
        Defense.setPosition(overlay.getPosition().x + 150, overlay.getPosition().y + 180);
        CostToSummon.setPosition(overlay.getPosition().x + 150, overlay.getPosition().y + 1);

    }

}

//maybe not worth it to include the whole <sstream> just for this?
std::string MonsterCard::int_to_string(const int &num)
{
    std::ostringstream strm;
    strm << num;
    std::string result = strm.str();
    return result;
}

void MonsterCard::scaleElements(double scale_x, double scale_y)
{
    overlay.setScale(scale_x, scale_y);
    MonsterName.setScale(scale_x, scale_y);
    image.setScale(scale_x, scale_y);
    Attack.setScale(scale_x, scale_y);
    ManaGive.setScale(scale_x, scale_y);
    Defense.setScale(scale_x, scale_y);
    CostToSummon.setScale(scale_x, scale_y);
}

void MonsterCard::drawElements(sf::RenderWindow * window)
{
    (*window).draw(overlay);
    (*window).draw(MonsterName);
    (*window).draw(CostToSummon);
    (*window).draw(image);
    (*window).draw(Attack);
    (*window).draw(Defense);
    (*window).draw(ManaGive);
}







