#pragma once

#include "HexagonalShape.h"
#include "Define.h"
#include "BoardBase.h"

//Responsible for the board, its management, construction,
//printing, and other things related to the board.

template <typename T>

class Board :public BoardBase
{
public:
	Board();
	~Board();
	void printBoard();
	std::vector<HexagonalShape>& getGameBoardVec();
	void blinkBoard(Sign sign);

private:
	void BuildNeighbors();
	void BuildHexagons();
	std::vector<T> m_gameBoard;

};
//================================================
template <typename T >
Board<T>::Board()
{
	m_gameWindow = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "windowGame");
	BuildUserKeys();
	setBackround();
	BuildHexagons();
	BuildNeighbors();
	updatForbiddenColor(m_gameBoard[m_gameBoard.size() - SUM_HEXAGONALS].getColor(),
		m_gameBoard[SUM_HEXAGONALS - 1].getColor());
}
//================================================
template <typename T >
Board<T>::~Board()
{
	delete(m_gameWindow);
}
//================================================
//Build all the Hexagons and the nabors
//================================================
template <typename T >
void Board<T>::BuildHexagons()
{
	int plus = 0, another = 0;


	for (int i = 0; i < SUM_HEXAGONALS; i++)
	{
		i % 2 != 0 ? plus = 0 : plus = RADIUS * (std::sqrt(3.f) / 2);
		i % 2 != 0 ? another = 1 : another = 0;
		for (int j = 0; j < SUM_HEXAGONALS + another; j++)
		{
			Sign sign = checkSign(i, j);
			double_t area = checkArea(i, j);

			m_gameBoard.emplace_back(sf::Vector2f((j * (RADIUS * (std::sqrt(3.f) / 2) * 2)
				+ plus + RECTANGEL_SIDE),
				(i * (RADIUS * 1.5) + INFORMATION_DISPLAY)), sign, area);
		}
	}
}
//================================================
template <typename T >
void Board<T>::printBoard()
{
	for (auto& i : m_gameBoard)
		i.drowShape(m_gameWindow);

	m_gameWindow->draw(m_backroundSideLeft);
	m_gameWindow->draw(m_backroundSideRight);
	m_gameWindow->draw(m_backroundInformationDown);
	m_gameWindow->draw(m_backroundInformationUp);

	for (auto& i : m_colorKeys)
		i.drowShape(m_gameWindow);

}
//===============================================
template <typename T >
std::vector<HexagonalShape>& Board<T>::getGameBoardVec()
{
	return m_gameBoard;
}
//===============================================
template <typename T >
void Board<T>::BuildNeighbors()
{
	
	for (int i = 0; i < m_gameBoard.size(); ++i)
		m_gameBoard[i].setNeighbors(m_gameBoard, i);

}
//===============================================
template <typename T >
void Board<T>::blinkBoard(Sign sign)
{
	if (sign == COMPUTER)
		m_turnCloke.restart();
	if ((m_turnCloke.getElapsedTime().asSeconds() < 0.6))
		sign = COMPUTER;

	if (m_blinkCloke.getElapsedTime().asSeconds() > 0.4)
	{
		m_blinkCloke.restart();

		for (auto& i : m_gameBoard)
			i.blink(sign);
	}
}