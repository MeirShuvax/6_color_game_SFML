#pragma once
#include <SFML/Graphics.hpp>

//Responsible for the colors the players choose

class ColorKeys   
{
public:
	ColorKeys (sf::Color color, sf::Vector2f location);
	bool isPressed(sf::Vector2f click) const;
	void drowShape(sf::RenderWindow* window) const;
	sf::Color getColor() const;
	void forbidden(bool forbidden);

private:
	sf::RectangleShape m_Key;
	bool m_forbidden;
	sf::Text m_forbiddenText;

};
