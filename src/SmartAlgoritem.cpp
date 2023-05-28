#include "SmartAlgoritem.h"
#include <iostream>


sf::Color SmartAlgoritem::turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
, sf::Color  lastColorPlayer, sf::Color lastColorComputer)
{
	unsigned int max = 0;
	sf::Color color = lastColorComputer;

	for (int i = 0; i < m_colors.size(); ++i)
	{
		if (m_colors[i] != lastColorComputer && m_colors[i] != lastColorPlayer)
		{
			for (auto& i : gameBoard)
				i.changeSign(false);

			unsigned int sum = getSumNeighbors(m_colors[i], gameBoard);
			if (sum > max)
			{
				max = sum;
				color = m_colors[i];
			}
		}
	}

	return color;
}
//===============================================
unsigned int SmartAlgoritem::getSumNeighbors(sf::Color color, std::vector<HexagonalShape>& gameBoard) const
{
	unsigned int counter = 0;

	for (int i = 0; i < gameBoard.size(); ++i)
	{
		if (gameBoard[i].getType() == COMPUTER)
		{
			travelByBFS(color, &gameBoard[i], counter);
		}
	}
	
	return counter;
}
//===============================================
// check who is the best color
//===============================================
void SmartAlgoritem::travelByBFS(sf::Color color, HexagonalShape* hexagon , unsigned int& counter) const
{
	if (hexagon->getSign())
		return;

	hexagon->changeSign(true);
	for (int j = 0; j < hexagon->getNeighbors().size(); ++j)
	{
		if (hexagon->getNeighbors()[j]->getHexagon().getFillColor() == color && !hexagon->getNeighbors()[j]->getSign())
		{
			travelByBFS(color, hexagon->getNeighbors()[j] , ++counter);
		}
	}
}