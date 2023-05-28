#pragma once
#include <SFML/Graphics.hpp>
#include "Define.h"

//Responsible for the hexagons, and managing everything related to the hexagon

class HexagonalShape
{
public:
	HexagonalShape(sf::Vector2f location);
	HexagonalShape(sf::Vector2f location, Sign type ,double_t area);
	void changeSign(bool ToF);
	bool getSign() const;
	void setColor(sf::Color color);
	void addColors();
	void editColor(sf::Color color);
	void drowShape(sf::RenderWindow* window) ;
	void blink(Sign turn);
	sf::Color getColor() const;
	void doBlink(bool ToF);
	sf::Color getRandColor() const;
	void setType(Sign type);
	Sign getType() const;
	void setNeighbors(std::vector<HexagonalShape>& gameBoard, int index);
	sf::CircleShape& getHexagon();
	std::vector <HexagonalShape*>& getNeighbors();
	double_t getArea() const;


private:
	
	void setHexagondetails(sf::Vector2f location);
	std::vector <HexagonalShape*> m_neighbors;
	sf::CircleShape m_hexagon;
	double_t m_area;
	bool m_isBlink;
	bool m_sign;
	Sign m_type;
	std::vector<sf::Color> m_colors;
	double_t m_size;
};