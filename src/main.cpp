#include "Game.h"
#include <SFML/Graphics.hpp>


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Game().run();
}
