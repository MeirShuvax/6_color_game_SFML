#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ColorKeys.h"
#include "Define.h"

//The base class - all the functions that are common to each
//type of template are found in it.

class BoardBase
{
public:
	BoardBase() = default;
    ~BoardBase() = default;
	sf::RenderWindow* getWindow() const;
	bool isColorPeressed(sf::Color& color, sf::Vector2i click) const;
	void updatForbiddenColor(sf::Color colorP, sf::Color colorC);

protected:
	void setBackround();
	Sign checkSign(const int i, const int j) const;
	double_t checkArea(const int i, const int j) const;
	void BuildUserKeys();

	sf::Clock m_blinkCloke;
	sf::Clock m_turnCloke;
	sf::RenderWindow* m_gameWindow;
	std::vector<ColorKeys> m_colorKeys;
	sf::RectangleShape m_backroundSideLeft;
	sf::RectangleShape m_backroundSideRight;
	sf::RectangleShape m_backroundInformationUp;
	sf::RectangleShape m_backroundInformationDown;


private:


};
