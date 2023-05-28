#include "BoardBase.h"


sf::RenderWindow* BoardBase::getWindow() const
{
	return m_gameWindow;
}


void BoardBase::setBackround()
{
	m_backroundSideLeft.setFillColor(sf::Color::Color(150, 148, 141));
	m_backroundSideLeft.setPosition(0, 0);
	m_backroundSideLeft.setSize(sf::Vector2f(RECTANGEL_SIDE, WINDOW_HEIGHT));

	m_backroundSideRight.setFillColor(sf::Color::Color(150, 148, 141));
	m_backroundSideRight.setPosition(RECTANGEL_HEXAGONALS + RECTANGEL_SIDE + 3, 0);
	m_backroundSideRight.setSize(sf::Vector2f(RECTANGEL_SIDE, WINDOW_HEIGHT));

	m_backroundInformationUp.setFillColor(sf::Color::Color(150, 148, 141));
	m_backroundInformationUp.setPosition(0, 0);
	m_backroundInformationUp.setSize(sf::Vector2f(WINDOW_HEIGHT, INFORMATION_DISPLAY));

	m_backroundInformationDown.setFillColor(sf::Color::Color(150, 148, 141));
	m_backroundInformationDown.setPosition(0, WINDOW_HEIGHT - INFORMATION_DISPLAY - RADIUS / 2);
	m_backroundInformationDown.setSize(sf::Vector2f(WINDOW_WIDTH, INFORMATION_DISPLAY + RADIUS / 2));
}

//===============================================
//Build User Keys vector
//===============================================
void BoardBase::BuildUserKeys()
{
	m_colorKeys.emplace_back(sf::Color::Red, sf::Vector2f((WINDOW_WIDTH / 3), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
	m_colorKeys.emplace_back(sf::Color::Color(217, 131, 26), sf::Vector2f((WINDOW_WIDTH / 3 + COLOR_KEY_SIZE + WINDOW_WIDTH / 60), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
	m_colorKeys.emplace_back(sf::Color::Yellow, sf::Vector2f((WINDOW_WIDTH / 3 + (COLOR_KEY_SIZE + WINDOW_WIDTH / 60) * 2), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
	m_colorKeys.emplace_back(sf::Color::Green, sf::Vector2f((WINDOW_WIDTH / 3 + (COLOR_KEY_SIZE + WINDOW_WIDTH / 60) * 3), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
	m_colorKeys.emplace_back(sf::Color::Blue, sf::Vector2f((WINDOW_WIDTH / 3 + (COLOR_KEY_SIZE + WINDOW_WIDTH / 60) * 4), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
	m_colorKeys.emplace_back(sf::Color::Color(227, 91, 186), sf::Vector2f((WINDOW_WIDTH / 3 + (COLOR_KEY_SIZE + WINDOW_WIDTH / 60) * 5), (WINDOW_HEIGHT - INFORMATION_DISPLAY / 2)));
}

bool BoardBase::isColorPeressed(sf::Color& color, sf::Vector2i click) const
{
	auto i = std::find_if(m_colorKeys.cbegin(), m_colorKeys.cend(), [click](auto i)
		{return i.isPressed(sf::Vector2f(click));  });
	if (i != m_colorKeys.end())
	{
		color = i->getColor();
		return true;
	}

	return false;

}

void BoardBase::updatForbiddenColor(sf::Color colorP, sf::Color colorC)
{

	for (auto& i : m_colorKeys)
	{
		i.getColor() == colorP || i.getColor() == colorC ? i.forbidden(true) :
			i.forbidden(false);
	}
}

Sign BoardBase::checkSign(const int i, const int j) const
{
	if (i == 0 && j == SUM_HEXAGONALS - 1)
		return COMPUTER;

	else if (j == 0 && i == SUM_HEXAGONALS - 1)
		return PLAYER;

	return EMPTY;
}

//===============================================
double_t BoardBase::checkArea(const int i, const int j)const
{
	if (i == 0 || i == SUM_HEXAGONALS - 1)
		return 0.75;

	else if (i % 2 != 0 && (j == 0 || j == SUM_HEXAGONALS))
		return 0.5;

	return 1;
}