#include "ComputerAlgoritem.h"

ComputerAlgoritem::ComputerAlgoritem()
{
	addColors();
}

void ComputerAlgoritem::addColors()
{
	m_colors.push_back(sf::Color::Red);
	m_colors.push_back(sf::Color::Color(217, 131, 26));
	m_colors.push_back(sf::Color::Yellow);
	m_colors.push_back(sf::Color::Green);
	m_colors.push_back(sf::Color::Blue);
	m_colors.push_back(sf::Color::Color(227, 91, 186));
}