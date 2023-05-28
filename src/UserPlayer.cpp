#include "UserPlayer.h"
#include <iostream>

UserPlayer::UserPlayer() :
	Player(VICTORY)
{
	m_areaText.setPosition(RECTANGEL_SIDE, WINDOW_HEIGHT - INFORMATION_DISPLAY / 2 - PIXEL_SIZE);
}
//===============================================
//make my Turn
//===============================================
//template <typename T>
void UserPlayer::myTurn(Board<HexagonalShape>& board, sf::Color lastColorComputer)
{
	m_isTurn = false;
	sf::Color color;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		auto click = sf::Mouse::getPosition(*board.getWindow());
		if (board.isColorPeressed(color, click) && color != lastColorComputer
			&& color != m_lastColorPlayer)
		{
			handlNeighbors(board.getGameBoardVec(), color, PLAYER);
			updateColor(board.getGameBoardVec(), color, PLAYER);
			m_isTurn = true;
			m_lastColorPlayer = color;
		}
	}
}
//===============================================
bool UserPlayer::getTurnStatus()
{
	return m_isTurn;
}

sf::Color UserPlayer::getLastColor()
{
	return m_lastColorPlayer;
}