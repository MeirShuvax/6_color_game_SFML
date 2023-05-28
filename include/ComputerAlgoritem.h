#pragma once
#include <SFML/Graphics.hpp>
#include "HexagonalShape.h"
#include "Player.h"

//The father of all algorithms, Arhai on common things

class ComputerAlgoritem
{
public:
	ComputerAlgoritem();
	virtual ~ComputerAlgoritem() = default;
	virtual sf::Color turnOnAlgoritem(std::vector<HexagonalShape> gameBoard ,
		sf::Color  lastColorPlayer, sf::Color lastColorComputer) = 0;

protected:
	std::vector<sf::Color> m_colors;
	void addColors();

};
