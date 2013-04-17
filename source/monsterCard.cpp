#include "monsterCard.h"

//Must fix constants to be according to the card resolution<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
const unsigned int NAME_SIZE = 20;
const unsigned int COST_SIZE = 27;
const unsigned int STAT_SIZE = 50;

sf::Texture MonsterCard::staticOverlay;
sf::Texture MonsterCard::backside;
sf::Image MonsterCard::overlayImg;
sf::Vector2f MonsterCard::NAME_BAR_ORIGIN;
sf::Vector2f MonsterCard::NAME_BAR_BOUNDS;
sf::Vector2f MonsterCard::IMAGE_ORIGIN;
sf::Vector2f MonsterCard::IMAGE_BOUNDS;
sf::Vector2f MonsterCard::STATS_ORIGIN;
sf::Vector2f MonsterCard::STATS_BOUNDS;

void MonsterCard::setOverlay(const std::string &overlayPath, const std::string &backsidePath)
{
    if(!staticOverlay.loadFromFile(overlayPath))
    {
        std::cout << "DEBUG_MESSAGE: Failed to load static overlay texture (" << overlayPath << ")" << std::endl;
    }
    if(!overlayImg.loadFromFile(overlayPath))
    {
        std::cout << "DEBUG_MESSAGE: Failed to load static overlay image (" << overlayPath << ")" << std::endl;
    }
    if(!backside.loadFromFile(backsidePath))
    {
        std::cout << "DEBUG_MESSAGE: Failed to load backside texture (" << backsidePath << ")" << std::endl;
    }

    NAME_BAR_ORIGIN = findOrigin(0, 0);
    NAME_BAR_BOUNDS = findBounds(NAME_BAR_ORIGIN);
    IMAGE_ORIGIN = findOrigin(0, NAME_BAR_ORIGIN.y + NAME_BAR_BOUNDS.y);
    IMAGE_BOUNDS = findBounds(IMAGE_ORIGIN);
    STATS_ORIGIN = findOrigin(0, IMAGE_ORIGIN.y + IMAGE_BOUNDS.y);
    STATS_BOUNDS = findBounds(STATS_ORIGIN);

    std::cout << "NAME BAR: " << NAME_BAR_ORIGIN.x << " " << NAME_BAR_ORIGIN.y << std::endl;
    std::cout << "IMG BAR: " << IMAGE_ORIGIN.x << " " << IMAGE_ORIGIN.y << std::endl;
    std::cout << "STAT BAR: " << STATS_ORIGIN.x << " " << STATS_ORIGIN.y << std::endl;
    std::cout << "NAME BOUNDS: " << NAME_BAR_BOUNDS.x << " " << NAME_BAR_BOUNDS.y << std::endl;
    std::cout << "IMG BOUNDS: " << IMAGE_BOUNDS.x << " " << IMAGE_BOUNDS.y << std::endl;
    std::cout << "STAT BOUNDS: " << STATS_BOUNDS.x << " " << STATS_BOUNDS.y << std::endl;
}

//constructors
MonsterCard::MonsterCard()
{
    overlay.setTexture(staticOverlay);
    monsterName = "<empty>";
    MonsterName.setString(monsterName);
    MonsterName.setColor(sf::Color::Black);
    MonsterName.setCharacterSize(NAME_SIZE);
    Attack.setCharacterSize(STAT_SIZE);
    ManaGive.setCharacterSize(STAT_SIZE);
    Defense.setCharacterSize(STAT_SIZE);
    CostToSummon.setCharacterSize(COST_SIZE);
    attack = 0;
    Attack.setString("0");
    manaGive = 0;
    ManaGive.setString("0");
    defense = 0;
    Defense.setString("0");
    costToSummon = 0;
    CostToSummon.setString("0");

    dragging = false;
    flipped = false;
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

    //Must fix to work with multiword names <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    strm >> str_name >> fill >> att >> def >> mana >> cost;

    overlay.setTexture(staticOverlay);
    image.setTexture(art);

    MonsterName.setCharacterSize(NAME_SIZE);
    Attack.setCharacterSize(STAT_SIZE);
    ManaGive.setCharacterSize(STAT_SIZE);
    Defense.setCharacterSize(STAT_SIZE);
    CostToSummon.setCharacterSize(COST_SIZE);

    monsterName = str_name;
    MonsterName.setString(monsterName);
    MonsterName.setColor(sf::Color::Black);

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

    std::cout << str_name << " " << fill << " " << att << " " << def << " " << mana << " " << cost << std::endl;

    dragging = false;
    flipped = false;
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

bool MonsterCard::isFlipped() const
{
    return flipped;
}

sf::Vector2f MonsterCard::getCardPosition() const
{
    sf::Vector2f position(overlay.getPosition().x, overlay.getPosition().y);
    return position;
}

double MonsterCard::getCardWidth() const
{
    return overlay.getGlobalBounds().width;
}

double MonsterCard::getCardHeight() const
{
    return overlay.getGlobalBounds().height;
}

void MonsterCard::setImage(const sf::Texture &art)
{
    image.setTexture(art);
}

void MonsterCard::setName(const std::string &str)
{
    monsterName = str;
    MonsterName.setString(monsterName);
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

void MonsterCard::setCardPosition(const double &x, const double &y)
{
    overlay.setPosition(x, y);
}

void MonsterCard::setCardPosition(const sf::Vector2f &vect)
{
    overlay.setPosition(vect);
}

void MonsterCard::setDragging(const bool &b)
{
    dragging = b;
}

void MonsterCard::flipCard()
{
    flipped = !(flipped);
}

void MonsterCard::flipCard(const bool &b)
{
    flipped = b;
}
void MonsterCard::rotateCard(const double &angle)
{
    rotateElements(angle);
}

void MonsterCard::displayMonsterCard(sf::RenderWindow * window, double scale_x, double scale_y)
{
    if(isFlipped())
    {
        overlay.setTexture(backside);
        overlay.scale(scale_x, scale_y);
        (*window).draw(overlay);
    }
    else
    {

        overlay.setTexture(staticOverlay);
        float card_x = overlay.getPosition().x;
        float card_y = overlay.getPosition().y;
        scaleElements(scale_x, scale_y);
        //Must add dynamic scaling to MonsterName, according to the length and size of the name<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        //Must also set appropriate colors and fonts to different texts
        MonsterName.setColor(sf::Color::Cyan);
        Attack.setColor(sf::Color::Cyan);
        ManaGive.setColor(sf::Color::Cyan);
        Defense.setColor(sf::Color::Cyan);
        CostToSummon.setColor(sf::Color::Cyan);
        MonsterName.setPosition((NAME_BAR_ORIGIN.x * scale_x + card_x), (NAME_BAR_ORIGIN.y * scale_y + card_y));
        image.setPosition((IMAGE_ORIGIN.x * scale_x + card_x), (IMAGE_ORIGIN.y * scale_y + card_y));
        Attack.setPosition((STATS_ORIGIN.x * scale_x * 1.65 + card_x), (STATS_ORIGIN.y * scale_y + card_y));
        ManaGive.setPosition((STATS_BOUNDS.x * scale_x * 0.5 + card_x), (STATS_ORIGIN.y * scale_y + card_y));
        Defense.setPosition((STATS_BOUNDS.x * scale_x - Defense.getGlobalBounds().width + card_x), (STATS_ORIGIN.y * scale_y + card_y));
        CostToSummon.setPosition((NAME_BAR_BOUNDS.x * scale_x - CostToSummon.getGlobalBounds().width + card_x), (NAME_BAR_BOUNDS.y * scale_y - CostToSummon.getGlobalBounds().height + card_y));
        drawElements(window);
    }
}

bool MonsterCard::mouseOverCard(const sf::Sprite &sprite, sf::RenderWindow* aWindow)
{
    //must be used inside an if (Left Mouse Button clicked)
    if(sf::Mouse::getPosition(*aWindow).x >= sprite.getPosition().x &&
       sf::Mouse::getPosition(*aWindow).x <= sprite.getPosition().x + sprite.getGlobalBounds().width &&
       sf::Mouse::getPosition(*aWindow).y >= sprite.getPosition().y &&
       sf::Mouse::getPosition(*aWindow).y <= sprite.getPosition().y + sprite.getGlobalBounds().height) return dragging = true;
    return dragging = false;
}



//NOT WORKING PROPERLY(especially now)<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

//NOT WORKING PROPERLY, must find a way to set center of rotation, and also fix how the elements will be displayed<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void MonsterCard::rotateElements(const double &angle)
{
    overlay.rotate(angle);
    MonsterName.rotate(angle);
    image.rotate(angle);
    Attack.rotate(angle);
    ManaGive.rotate(angle);
    Defense.rotate(angle);
    CostToSummon.rotate(angle);
}

sf::Vector2f MonsterCard::findOrigin(float startX, float startY)
{
    sf::Color borderColor;
    borderColor = overlayImg.getPixel(startX, startY);
    float overlay_width, overlay_height;
    //Must figure out a way to avoid these contants, since you can't access private members from static func<<<<<<<<<<<<<<<<<<<<<<
    overlay_width = 240; //overlay.getGlobalBounds().width;
    overlay_height = 340; //overlay.getGlobalBounds().height;
    std::cout << "overlay width: " << overlay_width << " / overlay_height: " << overlay_height << std::endl;

    for (int y = startY; y < overlay_height; y++)
    {
        for (int x = startX; x < overlay_width; x++)
        {
            if (overlayImg.getPixel(x, y) != borderColor)
            {
                sf::Vector2f result(x, y);
                return result;
            }
        }
    }
    std::cout << "Error: origin of specific card area not found. " << std::endl;
    sf::Vector2f error(-1, -1);
    return error;
}

sf::Vector2f MonsterCard::findBounds(const sf::Vector2f &vect)
{
    int xBound = 0;
    int yBound = 0;
    sf::Color areaColor;
    areaColor = overlayImg.getPixel(vect.x, vect.y);
    for (int x = vect.x; overlayImg.getPixel(x, vect.y) == areaColor; x++)
    {
        xBound++;
    }
    for (int y = vect.y; overlayImg.getPixel(vect.x, y) == areaColor; y++)
    {
        yBound++;
    }
    sf::Vector2f result(xBound, yBound);
    return result;
}

