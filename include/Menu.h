#pragma once

#include "HexagonalShape.h"
#include "Resources.h"
#include "Buttons.h"
#include <memory>
#include "Define.h"


//The role of this department is to manage the game menu,
//and make sure that the actions are performed according to the player's click


class Menu
{
public:
	Menu();
	void openMenu(sf::RenderWindow* menuWindow);
	Algoritem getAlgoritem();



private:
	void setArrow();//Creates a marker arrow
	void setButtons();//
	void setBackground();
	void setOpenSentence();

	void drowMenu(sf::RenderWindow* menuWindow);
	void isMouseMoved(const sf::Event& event);
	void isMousReleased(const sf::Event& event, sf::RenderWindow* menuWindow);
	void isKeyPressed(const sf::Event& event, sf::RenderWindow* menuWindow);
	//Moves the cursor backand forth
	void isUpPressed();
	//Moves the cursor backand forth
	void isDownPressed();
	void flashingArrow();
	void resetfirstbutton();
	void SinkingSlowly();
	//Vector of menu buttons
	std::vector < std::unique_ptr<Buttons>> m_buttons;
	sf::ConvexShape m_arrow;
	sf::Clock m_arrowClock;
	sf::Clock m_SinkingClock;
	sf::Text m_openSentence1;
	sf::Text m_openSentence2;
	std::vector <HexagonalShape> m_background;
	Algoritem m_algoritem;

};