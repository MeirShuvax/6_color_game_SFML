#include "ComputerPlayer.h"
#include "RandomAlgoritem.h"
#include "SmartAlgoritem.h"
#include "GreedyAlgoritem.h"

ComputerPlayer::ComputerPlayer():
    Player(LOST)
{
	m_areaText.setPosition(WINDOW_WIDTH / 3 + (COLOR_KEY_SIZE + WINDOW_WIDTH / 60) * 7,
		WINDOW_HEIGHT - INFORMATION_DISPLAY / 2 - PIXEL_SIZE);
}
//===============================================
void ComputerPlayer::setAlgoritem(Algoritem type)
{
	switch (type)
	{
	case RANDOM:
		m_algoritem = std::make_unique<RandomAlgoritem>();
		break;
	case GREEDY:
		m_algoritem = std::make_unique<GreedyAlgoritem>();
		break;
	case SMART:
		m_algoritem = std::make_unique<SmartAlgoritem>();
		break;
	default:
		break;
	}
}
//===============================================
//template <typename T>
void ComputerPlayer::myTurn(Board<HexagonalShape>& board , sf::Color lastColorUser)
{

	sf::Color color = m_algoritem->turnOnAlgoritem(board.getGameBoardVec() , lastColorUser,m_lastColorComputer);
	CleansFootsteps(board.getGameBoardVec());

	handlNeighbors(board.getGameBoardVec(), color, COMPUTER);
	updateColor(board.getGameBoardVec(), color, COMPUTER);
	m_lastColorComputer = color;
}

sf::Color ComputerPlayer::getLastColor() const
{
	return m_lastColorComputer;
}


