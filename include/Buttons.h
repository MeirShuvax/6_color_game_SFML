#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Resources.h"
#include "Define.h"

//An abstract class that assigns to each button
//in the menu
//And the different functions for each button realized by virtual

class Buttons
{
public:
    Buttons(const char buttonName[], sf::Vector2f Location);
    Buttons(const char buttonName[], sf::Vector2f Location, int sizeFont);
    virtual ~Buttons() = default;
    virtual Algoritem turnOnButton() = 0;

    //A function responsible for highlighting as open the cursor on it
    void highlightsButton(sf::ConvexShape& m_arrow);
    void highlightsButton();
    void resetHighlightsButton();
    void drowButton(sf::RenderWindow* menuWindow);
    bool isButtonPressed(sf::Vector2f click);
    bool isPressedNow();

private:
    sf::Text m_text;
    sf::Color m_color;
    sf::Color m_defaultColor;
    sf::RectangleShape m_rectangle;
    bool m_pressedNow;

    void setText(sf::Vector2f Location);
    void setRectangle();

  
};