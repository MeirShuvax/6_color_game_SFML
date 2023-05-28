#include "HexagonalShape.h"
#include <iostream>


HexagonalShape::HexagonalShape(sf::Vector2f location) :
	m_hexagon(RADIUS, 6), m_isBlink(false), m_sign(false)
{
	addColors();
	setHexagondetails(location);

}

HexagonalShape::HexagonalShape(sf::Vector2f location, Sign type, double_t area):
	HexagonalShape(location) 
{
	m_area = area;
	m_type = type;
}

void HexagonalShape::changeSign(bool ToF)
{
	m_sign = ToF;
}

void HexagonalShape::drowShape(sf::RenderWindow* window)
{
	window->draw(m_hexagon);
}

sf::Color HexagonalShape::getColor() const
{
	return m_hexagon.getFillColor();
}

void HexagonalShape::doBlink(bool ToF)
{
	m_isBlink = ToF;
}

sf::Color HexagonalShape::getRandColor() const
{
	return m_colors[std::rand() % m_colors.size()];
}

void HexagonalShape::addColors()
{
	m_colors.push_back(sf::Color::Red);
	m_colors.push_back(sf::Color::Color(217, 131, 26));
	m_colors.push_back(sf::Color::Yellow);
	m_colors.push_back(sf::Color::Green);
	m_colors.push_back(sf::Color::Blue);
	m_colors.push_back(sf::Color::Color(227, 91, 186));
}

void HexagonalShape::setHexagondetails(sf::Vector2f location)
{
	m_hexagon.setOrigin(m_hexagon.getGlobalBounds().width / 2, m_hexagon.getGlobalBounds().height / 4);
	m_hexagon.setPosition(location);
	m_hexagon.setFillColor(getRandColor());
	m_hexagon.setOutlineColor(sf::Color::Black);
	m_hexagon.setOutlineThickness(2.f);
}

void HexagonalShape::editColor(sf::Color color)
{
	m_hexagon.setFillColor(color);
}

double_t HexagonalShape::getArea() const
{
	return m_area;
}

bool HexagonalShape::getSign() const
{
	return m_sign;
}
//===============================================
//set the Hexagon Neighbors 
//===============================================
void HexagonalShape::setNeighbors(std::vector<HexagonalShape>& gameBoard, int index)
{

	if (index != gameBoard.size() - 1 && m_hexagon.getGlobalBounds().intersects
	(gameBoard[index + 1].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index + 1]);

	if (index != 0 && m_hexagon.getGlobalBounds().intersects
	(gameBoard[index - 1].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index - 1]);

	if (index >= SUM_HEXAGONALS && m_hexagon.getGlobalBounds().intersects
	(gameBoard[index - 30].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index - 30]);

	if (index > SUM_HEXAGONALS && m_hexagon.getGlobalBounds().intersects
	(gameBoard[index - 31].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index - 31]);

	if (index < gameBoard.size() - SUM_HEXAGONALS && m_hexagon.getGlobalBounds()
		.intersects(gameBoard[index + 30].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index + 30]);

	if (index < gameBoard.size() - SUM_HEXAGONALS - 1 && m_hexagon.getGlobalBounds().intersects(gameBoard[index + 31].getHexagon().getGlobalBounds()))
		m_neighbors.push_back(&gameBoard[index + 31]);
}

void HexagonalShape::setColor(sf::Color color)
{
	m_hexagon.setFillColor(color);
}

void HexagonalShape::setType(Sign type)
{
	m_type = type;
}

Sign HexagonalShape::getType() const
{
	return m_type;
}

sf::CircleShape& HexagonalShape::getHexagon() 
{
	return m_hexagon;
}

std::vector <HexagonalShape*>& HexagonalShape::getNeighbors()
{
	return m_neighbors;
}
//===============================================
//blink the Hexagon
//===============================================
void HexagonalShape::blink(Sign turn)
{

	if (((turn == COMPUTER && m_type == COMPUTER) || turn == PLAYER && m_type == PLAYER) )
	{
		if (m_hexagon.getFillColor().a == 255)
			m_hexagon.setFillColor(sf::Color::Color(m_hexagon.getFillColor().r,
				m_hexagon.getFillColor().g, m_hexagon.getFillColor().b, 200));
		else
			m_hexagon.setFillColor(sf::Color::Color(m_hexagon.getFillColor().r,
				m_hexagon.getFillColor().g, m_hexagon.getFillColor().b, 255));
	}

}
