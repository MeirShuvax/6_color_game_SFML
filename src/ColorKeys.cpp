#include "ColorKeys.h"
#include "Define.h"
#include "Resources.h"

ColorKeys::ColorKeys(sf::Color color, sf::Vector2f location):
	m_Key(sf::Vector2f(COLOR_KEY_SIZE, COLOR_KEY_SIZE)), m_forbidden(false),
    m_forbiddenText("x", Resources::resources().getFontAriel(), COLOR_KEY_SIZE)
{
    m_Key.setPosition(location);
    m_Key.setFillColor(color);
    m_Key.setOutlineColor(sf::Color::Black);
    m_Key.setOutlineThickness(2.f);


    m_forbiddenText.setFillColor(sf::Color::Black);
    m_forbiddenText.setPosition(location.x  +COLOR_KEY_SIZE /4  , location.y - COLOR_KEY_SIZE/4 );
}

void ColorKeys::drowShape(sf::RenderWindow* window) const
{
    window->draw(m_Key);
    if (m_forbidden)
        window->draw(m_forbiddenText);
}

bool ColorKeys::isPressed(sf::Vector2f click) const
{
    return (m_Key.getGlobalBounds().contains(click));
}

sf::Color ColorKeys::getColor() const
{
    return m_Key.getFillColor();
}

void ColorKeys::forbidden(bool forbidden)
{
    m_forbidden = forbidden;
}
