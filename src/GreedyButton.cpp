#include "GreedyButton.h"
//===============================================
GreedyButton::GreedyButton() :
	Buttons("Greedy", sf::Vector2f(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 3) + RECTANGEL_HEXAGONALS/6))
{}
//===============================================
Algoritem GreedyButton::turnOnButton()
{
	return GREEDY;
}