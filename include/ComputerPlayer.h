#pragma once
#include "Player.h"
#include "ComputerAlgoritem.h"

//Responsible for the computer player, managing him according to the
//algorithm he chose.

class ComputerPlayer : public Player
{
public:
	ComputerPlayer();
	void myTurn(Board<HexagonalShape>& board , sf::Color lastColorUser);
	void setAlgoritem(Algoritem type);
	sf::Color getLastColor() const;

private:
	std::unique_ptr <ComputerAlgoritem> m_algoritem;
	sf::Color m_lastColorComputer;
};
