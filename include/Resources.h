#pragma once
#include <SFML/Graphics.hpp>

//responsible for the resources

class Resources
{
public:
	
	static Resources& resources();
	Resources(const Resources&) = delete;
	void operator = (const Resources&) = delete;
	sf::Font& getFontAriel();


private:
	Resources();
	sf::Font m_fontAriel;


};


