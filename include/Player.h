#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "HexagonalShape.h"
#include "Board.h"

//The father of both players - responsible for things related to both.

class Player
{
public:
	Player(std::string WoL);
	void handlNeighbors(std::vector<HexagonalShape>& gameBoard, sf::Color color , Sign type);
	void updateColor(std::vector<HexagonalShape>& gameBoard ,sf::Color color, Sign type);
	void printPrecent(sf::RenderWindow* window);
	double_t countArea(int sizeArea, double_t obgectArea) const;
	void CleansFootsteps(std::vector<HexagonalShape>& gameBoard);
	bool checkVictory() const;
	void printVictory(sf::RenderWindow* window) const;

protected:
	double_t m_areaSize;
	sf::Text m_areaText;
	void travelByBFS(sf::Color color, Sign type, HexagonalShape* hexagon);


private:
	double_t countAllArea(std::vector<HexagonalShape>& gameBoard) const;
	sf::Text m_victoryText;
	sf::RectangleShape m_victoryRect;


};
