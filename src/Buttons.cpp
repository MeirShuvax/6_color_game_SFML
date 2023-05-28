#include "Buttons.h"

//An abstract class that assigns to each button
//in the menu
//And the different functions for each button realized by virtual
//===============================================
Buttons::Buttons(const char buttonName[], sf::Vector2f Location) :
	m_text(buttonName, Resources::resources().getFontAriel()), m_pressedNow(false),
	m_defaultColor(sf::Color(255, 255, 255, 255)), m_color(sf::Color(0, 160, 204, 255))
{
	setText(Location);
}					
//===============================================
Buttons::Buttons(const char buttonName[], sf::Vector2f Location,int sizeFont /*sf::Vector2f size*/) :
	m_text(buttonName, Resources::resources().getFontAriel()), m_pressedNow(false),
	m_defaultColor(sf::Color(255, 255, 255, 255)), m_color(sf::Color(0, 160, 204, 255))
{
	m_text.setPosition(Location);
	m_text.setCharacterSize(sizeFont);
	m_text.setFillColor(m_defaultColor);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	setRectangle();
	
}
//===============================================
void Buttons::setText(sf::Vector2f Location)
{
	m_text.setPosition(Location);
	m_text.setCharacterSize(RECTANGEL_HEXAGONALS/8);
	m_text.setFillColor(m_defaultColor);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
}
//===============================================
void Buttons::setRectangle()
{
	m_rectangle.setSize(sf::Vector2f(m_text.getGlobalBounds().width+ PIXEL_SIZE, m_text.getGlobalBounds().height + PIXEL_SIZE*2));
	m_rectangle.setPosition(m_text.getPosition().x, m_text.getPosition().y + m_text.getGlobalBounds().height / 2);
	m_rectangle.setFillColor(sf::Color::Color(163, 70, 70, 200));
	m_rectangle.setOutlineColor(sf::Color(0, 55, 0, 200));
	m_rectangle.setOutlineThickness(2);
	m_rectangle.setOrigin(m_rectangle.getGlobalBounds().width / 2, m_rectangle.getGlobalBounds().height / 2 + 5);

}
//===============================================
void Buttons::drowButton(sf::RenderWindow* menuWindow)
{
	menuWindow->draw(m_rectangle);
	menuWindow->draw(m_text);
}
//===============================================
//A function responsible for highlighting as open the cursor on it
void Buttons::highlightsButton(sf::ConvexShape& m_arrow)
{
	m_arrow.setPosition(m_text.getPosition().x + m_text.getGlobalBounds().width / 2 + 20,
		m_text.getPosition().y + m_text.getGlobalBounds().height / 2 - 20);

	m_pressedNow = true;
	m_text.setFillColor(m_color);

}
//===============================================
void Buttons::highlightsButton()
{
	m_pressedNow = true;
	m_text.setFillColor(m_color);
}
//===============================================
void Buttons::resetHighlightsButton()
{
	m_pressedNow = false;
	m_text.setFillColor(m_defaultColor);

}
//===============================================
bool Buttons::isPressedNow()
{
	return m_pressedNow;
}
//===============================================
bool Buttons::isButtonPressed(sf::Vector2f click)
{
	return (m_text.getGlobalBounds().contains(click));
}