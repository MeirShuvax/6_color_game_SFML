#pragma once
#include "ComputerAlgoritem.h"

//Responsible for the greedy algorithm.

class GreedyAlgoritem : public ComputerAlgoritem
{

public:
	GreedyAlgoritem() = default;
	sf::Color turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
		,sf::Color  lastColorPlayer, sf::Color lastColorComputer) override;
	unsigned int getSumNeighbors(sf::Color color, std::vector<HexagonalShape>& gameBoard) const;
	void getMaxColor(sf::Color color, HexagonalShape* hexagon, unsigned int& counter) const;

private:


};

