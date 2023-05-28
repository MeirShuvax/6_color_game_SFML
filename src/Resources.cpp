#include "Resources.h"

Resources::Resources()
{
	m_fontAriel.loadFromFile("C:/Windows/Fonts/COOPBL.TTF");
}

Resources& Resources::resources()
{
	static auto resources = Resources();
	return resources;
}

sf::Font& Resources::getFontAriel()
{
	return m_fontAriel;
}