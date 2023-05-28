#pragma once
#include "ComputerAlgoritem.h"

//Responsible for the smart algorithm

class SmartAlgoritem : public ComputerAlgoritem
{
public:
	SmartAlgoritem() = default;

	sf::Color turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
		, sf::Color  lastColorPlayer, sf::Color lastColorComputer)  override;

private:
	unsigned int getSumNeighbors(sf::Color color, std::vector<HexagonalShape>& gameBoard) const;
	void travelByBFS(sf::Color color, HexagonalShape* hexagon, unsigned int& counter) const;


};

