#include "Menu.h"
#include "RandomButton.h"
#include "GreedyButton.h"
#include "SmartButton.h"
#include  <iostream>
//===============================================
Menu::Menu() :
	m_algoritem(NUL), m_openSentence1(WELCOM, Resources::resources().getFontAriel(),
		RECTANGEL_HEXAGONALS / 15)
{
	setOpenSentence();
	setButtons();
	setArrow();
	setBackground();
}
//===============================================
void Menu::setButtons()
{
	m_buttons.push_back(std::make_unique<RandomButton>());
	m_buttons.push_back(std::make_unique<GreedyButton>());
	m_buttons.push_back(std::make_unique<SmartButton>());
}
//===============================================
void Menu::setArrow()
{
	m_arrow.setPointCount(7);
	m_arrow.setPoint(0, sf::Vector2f(0, 20));
	m_arrow.setPoint(1, sf::Vector2f(20, 40));
	m_arrow.setPoint(2, sf::Vector2f(20, 30));
	m_arrow.setPoint(3, sf::Vector2f(50, 30));
	m_arrow.setPoint(4, sf::Vector2f(50, 10));
	m_arrow.setPoint(5, sf::Vector2f(20, 10));
	m_arrow.setPoint(6, sf::Vector2f(20, 0));
	m_arrow.setFillColor(sf::Color::Red);
	m_arrow.setOutlineColor(sf::Color::Black);
	m_arrow.setOutlineThickness(4);
}
//===============================================
void Menu::openMenu(sf::RenderWindow* menuWindow)
{
	while (menuWindow->isOpen())
	{
		menuWindow->clear();
		resetfirstbutton();
		SinkingSlowly();
		drowMenu(menuWindow);
		menuWindow->display();
		for (auto event = sf::Event{}; menuWindow->pollEvent(event); )
			switch (event.type)
			{
			case sf::Event::Closed:
				menuWindow->close();
				break;

			case sf::Event::KeyPressed:
				isKeyPressed(event, menuWindow);
				break;

			case sf::Event::MouseMoved:
				isMouseMoved(event);
				break;

			case sf::Event::MouseButtonReleased:
				isMousReleased(event, menuWindow);
				break;
			}
		if (m_algoritem != NUL)
			break;
	}
}
//===============================================
void Menu::drowMenu(sf::RenderWindow* menuWindow)
{
	flashingArrow();

	for (int cell = 0; cell < m_background.size(); ++cell)
		m_background[cell].drowShape(menuWindow);
	menuWindow->draw(m_openSentence1);
	menuWindow->draw(m_openSentence2);
	menuWindow->draw(m_arrow);

	for (int cell = 0; cell < m_buttons.size(); ++cell)
		m_buttons[cell]->drowButton(menuWindow);
}
//===============================================
void Menu::isMouseMoved(const sf::Event& event)
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isButtonPressed(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)))
			m_buttons[cell]->highlightsButton(m_arrow);
		else
			m_buttons[cell]->resetHighlightsButton();
}
//===============================================
void Menu::isMousReleased(const sf::Event& event, sf::RenderWindow* menuWindow)
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isButtonPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			m_algoritem = m_buttons[cell]->turnOnButton();
}
//===============================================
//Moves the cursor backand forth
void Menu::isKeyPressed(const sf::Event& event, sf::RenderWindow* menuWindow)
{
	switch (event.key.code)
	{

	case sf::Keyboard::Up:
		isUpPressed();
		break;

	case sf::Keyboard::Down:
		isDownPressed();
		break;

	case sf::Keyboard::Enter:
		for (int cell = 0; cell < m_buttons.size(); ++cell)
			if (m_buttons[cell]->isPressedNow())
				m_algoritem = m_buttons[cell]->turnOnButton();
	
		break;
	}
}
//===============================================
void Menu::isUpPressed()//Moves the cursor backand forth
{
	for (size_t cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
		{
			m_buttons[cell]->resetHighlightsButton();
			if (cell - 1 == -1)
				cell = m_buttons.size() - 1;
			else
				cell -= 1;
			m_buttons[cell]->highlightsButton(m_arrow);
		}
}
//===============================================
void Menu::isDownPressed()//Moves the cursor backand forth
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
		{
			m_buttons[cell]->resetHighlightsButton();
			if (cell + 1 == m_buttons.size())
				cell = 0;
			else
				cell += 1;
			m_buttons[cell]->highlightsButton(m_arrow);
		}
}
//===============================================
void Menu::flashingArrow()
{
	if (m_arrowClock.getElapsedTime().asSeconds() > 0.8)
	{
		m_arrowClock.restart();
		if (m_arrow.getFillColor() == sf::Color(0, 0, 0, 0))
		{
			m_arrow.setOutlineColor(sf::Color::Black);
			m_arrow.setFillColor(sf::Color::Red);
		}
		else
		{
			m_arrow.setFillColor(sf::Color(0, 0, 0, 0));
			m_arrow.setOutlineColor(sf::Color(0, 0, 0, 0));
		}
	}
}
//===============================================
void Menu::resetfirstbutton()
{
	for (int cell = 0; cell < m_buttons.size(); ++cell)
		if (m_buttons[cell]->isPressedNow())
			return;
	m_buttons[0]->highlightsButton(m_arrow);
}
//===============================================
Algoritem Menu::getAlgoritem()
{
	return m_algoritem;
}
//===============================================
void Menu::setBackground()
{
	for (int i = 0; i < 100; i++)
	{
		m_background.emplace_back(sf::Vector2f(rand() % int(WINDOW_WIDTH),
			rand() % int(WINDOW_HEIGHT)));
	}
}
//===============================================
void Menu::setOpenSentence()
{
	m_openSentence1.setFillColor(sf::Color(204, 51, 0));
	m_openSentence1.setOrigin(m_openSentence1.getGlobalBounds().width / 2, m_openSentence1.getGlobalBounds().height / 2);

	m_openSentence2 = m_openSentence1;
	m_openSentence2.setString("Welcome");
	m_openSentence2.setCharacterSize(RECTANGEL_HEXAGONALS / 13);

	m_openSentence2.setOrigin(m_openSentence2.getGlobalBounds().width / 2, m_openSentence2.getGlobalBounds().height / 2);
	m_openSentence1.setOrigin(m_openSentence1.getGlobalBounds().width / 2, m_openSentence1.getGlobalBounds().height / 2);

	m_openSentence2.setPosition(WINDOW_WIDTH / 2, RECTANGEL_HEXAGONALS / 10);
	m_openSentence1.setPosition(WINDOW_WIDTH / 2, m_openSentence2.getPosition().y + WINDOW_HEIGHT / 17);
}
//===============================================
void Menu::SinkingSlowly()
{
	if (m_SinkingClock.getElapsedTime().asSeconds() > 0.05)
	{
		m_SinkingClock.restart();
		for (int cell = 0; cell < m_background.size(); ++cell)
		{
			m_background[cell].getHexagon().setPosition(m_background[cell].getHexagon().getPosition().x,
				m_background[cell].getHexagon().getPosition().y + 1);
			if(m_background[cell].getHexagon().getPosition().y > WINDOW_HEIGHT)
				m_background[cell].getHexagon().setPosition(m_background[cell].getHexagon().getPosition().x , -RADIUS);
		}
	}
}
//===============================================

