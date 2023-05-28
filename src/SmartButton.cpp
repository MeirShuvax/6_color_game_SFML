#include "SmartButton.h"

SmartButton::SmartButton() :
	Buttons("Smart" ,sf::Vector2f(WINDOW_WIDTH / 2,( WINDOW_HEIGHT / 3) + RECTANGEL_HEXAGONALS / 3))
{}
//===============================================
Algoritem SmartButton::turnOnButton()
{
	return SMART;
}


