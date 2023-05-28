#include "GreedyAlgoritem.h"
#include <iostream>

sf::Color GreedyAlgoritem::turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
	,sf::Color  lastColorPlayer, sf::Color lastColorComputer)
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
// check who is the best color
//===============================================
unsigned int GreedyAlgoritem::getSumNeighbors(sf::Color color, std::vector<HexagonalShape>& gameBoard) const
{
	unsigned int counter = 0;

	for (auto& i : gameBoard)
	{
		if (i.getType() == COMPUTER)
		{
			getMaxColor(color, &i, counter);
		}
	}

	return counter;

}
//===============================================
// check who is the best color
//===============================================
void GreedyAlgoritem::getMaxColor(sf::Color color, HexagonalShape* hexagon, unsigned int& counter) const
{

	for (int j = 0; j < hexagon->getNeighbors().size(); ++j)
	{
		if (hexagon->getNeighbors()[j]->getHexagon().getFillColor() == color && !hexagon->getNeighbors()[j]->getSign())
		{
			hexagon->getNeighbors()[j]->changeSign(true);
			counter++;
		}
	}
}