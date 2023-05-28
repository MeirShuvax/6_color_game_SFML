#include "RandomAlgoritem.h"

sf::Color RandomAlgoritem::turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
	, sf::Color  lastColorPlayer, sf::Color lastColorCompute)
{
	sf::Color color;
	while (true)
	{
		color = m_colors[std::rand() % m_colors.size()];
		if (color != lastColorCompute && color != lastColorPlayer)
			break;
	}

	return color;
}
