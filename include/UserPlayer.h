#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "HexagonalShape.h"
#include "Player.h"

//Responsible for the player, his management

class UserPlayer : public Player
{
public:
	UserPlayer();
	void myTurn(Board<HexagonalShape>& board, sf::Color lastColorComputer);
		bool getTurnStatus();
	sf::Color getLastColor();


private:
	bool m_isTurn;
	sf::Color m_lastColorPlayer;
};
