
#include "RandomButton.h"

RandomButton::RandomButton() :
	Buttons("Random",  sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3))
{}
//===============================================
Algoritem RandomButton::turnOnButton()
{
	return RANDOM;
}


