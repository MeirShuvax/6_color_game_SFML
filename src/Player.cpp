#include "Player.h"
#include <iostream>
#include "Resources.h"

Player::Player(std::string WoL):
	m_areaSize(0.084746), m_victoryText(WoL, Resources::resources().getFontAriel(), COLOR_KEY_SIZE)
{
	m_victoryText.setFillColor(sf::Color::Red);
	m_victoryText.setPosition(WINDOW_WIDTH/ 2 , WINDOW_HEIGHT / 2);
	m_victoryText.setOrigin(m_victoryText.getGlobalBounds().width / 2, 
		m_victoryText.getGlobalBounds().height / 2);

	m_victoryRect.setSize(sf::Vector2f(m_victoryText.getGlobalBounds().width ,
		m_victoryText.getGlobalBounds().height+ PIXEL_SIZE*3));
	m_victoryRect.setFillColor(sf::Color::Color(252,220,220,200));
	m_victoryRect.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	m_victoryRect.setOrigin(m_victoryText.getGlobalBounds().width / 2,
		m_victoryText.getGlobalBounds().height / 2);

	m_areaText.setFont(Resources::resources().getFontAriel());
	m_areaText.setFillColor(sf::Color::White);
	m_areaText.setCharacterSize(25);
	m_areaText.setString(std::to_string(m_areaSize) + '%');
}
//===============================================
void Player::handlNeighbors(std::vector<HexagonalShape>& gameBoard, sf::Color color, Sign type)
{
	for (int i = 0; i < gameBoard.size(); ++i)
	{
		if (gameBoard[i].getType() == type)
		{
			
			travelByBFS(color, type, &gameBoard[i]);
		}
	}
	CleansFootsteps(gameBoard);
}
//===============================================
void Player::travelByBFS(sf::Color color, Sign type, HexagonalShape* hexagon)
{
	if (hexagon->getSign())
		return;

	hexagon->changeSign(true);

	for (int j = 0; j < hexagon->getNeighbors().size(); ++j)
	{
		if (hexagon->getNeighbors()[j]->getHexagon().getFillColor() == color )
		{
			
			hexagon->getNeighbors()[j]->setType(type);
			travelByBFS( color, type, hexagon->getNeighbors()[j]);
		}
	}

}
//===============================================
void Player::updateColor(std::vector<HexagonalShape>&gameBoard ,sf::Color color, Sign type)
{
	m_areaSize = 0;

	for (int i = 0; i < gameBoard.size(); ++i)
	{
		if (gameBoard[i].getType() == type)
		{
			m_areaSize += countArea(countAllArea(gameBoard), gameBoard[i].getArea());
			gameBoard[i].setColor(color);
		}
	}
}
//===============================================
void Player::printPrecent(sf::RenderWindow* window)
{
	m_areaText.setString(std::to_string(m_areaSize) + '%');
	window->draw(m_areaText);
}
//===============================================
double_t Player::countArea(int sizeArea, double_t obgectArea) const
{
	return (obgectArea / double_t(sizeArea)) * double_t(100);
}
//===============================================
void Player::CleansFootsteps(std::vector<HexagonalShape>& gameBoard)
{
	std::for_each(gameBoard.begin(), gameBoard.end(), [](HexagonalShape& obj) {
	obj.changeSign(false);
		});
}
//===============================================
bool Player::checkVictory() const
{
	return m_areaSize > 50;
}
//===============================================
void Player::printVictory(sf::RenderWindow* window) const
{
	window->draw(m_victoryRect);
	window->draw(m_victoryText);
}
//===============================================
double_t Player::countAllArea(std::vector<HexagonalShape>& gameBoard) const
{
	double_t sum = 0;
	for (auto& i : gameBoard)
		sum += i.getArea();
	return sum;
}


