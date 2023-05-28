#include "NewGameButton.h"
#include "Game.h"
NewGameButton::NewGameButton():
	Buttons("new game", sf::Vector2f( WINDOW_WIDTH/8, WINDOW_HEIGHT/20), 
		RECTANGEL_HEXAGONALS / 20	/*sf::Vector2f(WINDOW_WIDTH/4, INFORMATION_DISPLAY / 2)*/){}

//===============================================
Algoritem NewGameButton::turnOnButton()
{
	return NUL;
}
//===============================================