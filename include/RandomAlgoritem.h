#pragma once
#include "ComputerAlgoritem.h"

//Responsible for the random algorithm.

class RandomAlgoritem : public ComputerAlgoritem
{
public:
	RandomAlgoritem() = default;
	sf::Color turnOnAlgoritem(std::vector<HexagonalShape> gameBoard
		, sf::Color  lastColorPlayer, sf::Color lastColorCompute) override;

private:
	
};

